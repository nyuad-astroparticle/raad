#############################
#       RAAD Library        #
#############################

# Import necessary Libraries
from astropy.time import Time, TimeDelta
import pandas as pd
import numpy as np
import geoviews as gv
from tqdm import tqdm
gv.extension('bokeh', 'matplotlib')


##################################################################################
# Helper functions
##################################################################################

# helper function to convert longitude in range -180 to 180
def in_range(longitude):
    return longitude if longitude <= 180 else longitude - 360




##################################################################################
# Classes
##################################################################################

# TGF Class
class event: 
    # Constructor ###############################################################
    def __init__(self,timestamp,latitude:float,longitude:float,detector_id:str,event_id:str='',mission:str='',time_format:str='mjd',event_type:str='TGF'):
        # Set up the variables
        self.timestamp      = Time(timestamp, format=time_format)
        self.latitude       = latitude
        self.longitude      = longitude
        self.detector_id    = detector_id
        self.event_id       = event_id
        self.mission        = mission
        self.event_type     = event_type

    
    # SOME FUNCTIONS FOR THE TGF CLASS ##########################################

    # Return a string for that TGF
    def __str__(self):
        str = ''' %s: %s | Mission: %s
        Timestamp (ISO): %s
        Lat: %9.4f \t Long: %9.4f
        Detector_id: %s
        '''%(self.event_type,self.event_id,self.mission,self.get_iso(),self.latitude,self.longitude,self.detector_id)

        return str

    # Print a TGF
    def print(self):
       print(self.__str__())

    # Get any time format that astropy has to offer
    def get_timestamp(self,time_format:str='mjd',data_type:str='long'):
        data_type = None if time_format == 'iso' else data_type
        return self.timestamp.to_value(time_format,data_type)

    # Return EPOCH Date
    def get_epoch(self):
        return self.get_timestamp('unix')

    # Return MJD Date
    def get_mjd(self):
        return self.get_timestamp('mjd') 

    # Return ISO Date
    def get_iso(self):
        return self.get_timestamp('iso',None)
    

# Since we will be working with tgf arrays so much we will create
# Another class called TGF Array that has methods to handle an array of TGFs
class array:
    event_types = ['fermi','light-1','lightning']

    # Constructor
    def __init__(self,events=None,filename='',event_type=event_types[0]):
        
        # Add the tgfs as an array
        self.events = [] if events is None else events

        # if you add a filename, add the apppend the tgfs from that filename
        if filename != '':
            self.from_file(filename=filename,event_type=event_type,append=True)


    # Method to append
    def append(self,ev):
        self.events.append(ev)
    
    # Method to convert this into a string
    def __str__(self):
        string = ''
        for i,ev in enumerate(self.events):
            string += '%5d'%i + str(ev) + '\n'
    
        return string

    # Make objects compatible with len()
    def __len__(self):
        return len(self.events)

    # Overload the [] opeartor to be able to do tgf_array[1] etc.
    def __getitem__(self,i):
        if type(i) == list: return array([self.events[index] for index in i])
        else: return self.events[i]

    # Overload the [] operator to be able to do tgf_array[1] = 3 etc.
    def __set_item__(self,i,value):
        if type(i) == list:
            if type(value) == list:
                assert(len(value) == len(i))
                for index in i: self.events[index]=value[index]
            else:
                for index in i: self.events[index]=value
        
        else: self.events[i] = value

    # And a print method
    def print(self):
        print(self.__str__())

    
    # Get longitude and latitude as numpy arrays
    def get_coords(self):
        coords = []
        for event in self.events:
            coords.append([event.longitude,event.latitude])
        
        return np.array(coords)

    # Get array of timestamps
    def get_timestamps(self,format=None):
        times = []
        for event in self.events:
            if format is None:
                times.append(event.timestamp)
            else:
                times.append(event.get_timestamp(format))

        return np.array(times)

    # To list function
    def to_list(self):
        return self.events



    # Generate an array of tgfs from a file
    def fermi_from_file(self,filename,append:bool=True):
        # Load the TGF data
        data = pd.read_csv(filename).to_numpy()
        tgfs = []                                   # List to store the TGFs

        # For all the TGFs in the loaded dataset
        for datum in data:
            # Create a TGF and append it to the array
            tgfs.append(event(timestamp = datum[5],
                            longitude   = in_range(float(datum[9])), 
                            latitude    = float(datum[10]),
                            detector_id = datum[8],
                            event_id    = datum[2],
                            mission     = 'fermi',
                            time_format = 'mjd',
                            event_type  = 'TGF'))
        
        # If you want to append the data to the original array do so here
        if append: self.events += tgfs

        # Otherwise return them as a different tgf_array
        else: return array(tgfs)

    # Generate an array of lightnings from a file
    def lightning_from_file(self,filename:str,append:bool=True):
        # Load the lightning data
        data    = pd.read_csv(filename).to_numpy()
        lights  = []                                   # List to store the ligtnigs

        # For all the TGFs in the loaded dataset
        for datum in data:
            # Create a TGF and append it to the array
            lights.append(event(timestamp   = float(datum[0]) * 1e-9,
                                longitude   = in_range(float(datum[2])), 
                                latitude    = float(datum[1]),
                                detector_id = 'Blitz',
                                event_id    = datum[2],
                                mission     = 'Blitzurtong',
                                time_format = 'unix',
                                event_type  = 'Lightning'))
        
        # If you want to append the data to the original array do so here
        if append: self.events += lights

        # Otherwise return them as a different tgf_array
        else: return array(lights)
    
    def from_file(self,filename:str,event_type:str=event_types[0],append:bool=True):
        # Choose the appropriate function to load the data
        if   event_type == array.event_types[0]:
            return self.fermi_from_file(filename=filename, append=append)
        
        elif event_type == array.event_types[2]:
            return self.lightning_from_file(filename=filename, append=append)



##################################################################################
# Working functions
##################################################################################

# Visualize a set of TGFs on a map
def map(tgfs,lightnings:array=None):
    # If it is a single point, convert it into an array
    if type(tgfs)   == list:        tgfs = array(tgfs)
    elif type(tgfs) == event:       tgfs = array([tgfs])
    elif type(tgfs) != array: raise Exception("type %s is not an event object nor a list. Please enter a TGF object"%type(tgfs))

    # Convert the points to GeoViews points
    points = gv.Points([tgfs.get_coords()])

    # Create the tgf map
    tgf_map = (gv.tile_sources.OSM * points).opts(gv.opts.Points(
                global_extent=True, 
                width=1300, 
                height=900, 
                size=7,
                color='Blue',
                marker='+'))
    
    # if there are lightnings create the lighning map and add it to the TGF map
    if lightnings is not None:
        points_lightning = gv.Points([lightnings.get_coords()])
        
        lightning_map = (gv.tile_sources.OSM * points_lightning).opts(gv.opts.Points(
                global_extent=True, 
                width=1300, 
                height=900, 
                size=7,
                color='red',
                marker='+'))

        tgf_map *= lightning_map

    return tgf_map


# Print the closest lightnings
def get_nearby_lightning(tgf,lightnings:array,threshold:float=1):
    # If we are given an array of TGFs
    if type(tgf) == array:
        # Create a list to output the lighning arrays for each event
        lightnings = []

        # For all the events
        for T in tqdm(tgf):
            # Calculate the closest ones
            lightnings.append(get_nearby_lightning(T))

        return lightnings
    
    # If we are given a lightning
    elif type(tgf) == event:
        # The threshold is the maximum time to look for lightnings from the tgf
        threshold = TimeDelta(threshold,format='sec')

        # Get the TGF's timestamp
        tgf_time = tgf.timestamp

        # Get all the timestamps
        timestamps = lightnings.get_timestamps()

        # find the indices where the timedifference is less than threshold
        idx = [i for i,time in enumerate(timestamps) if abs(time - tgf_time) < threshold]

        # Get the appropriate subarray
        return lightnings[idx]

    # if it is not of type event of array then raise an error
    else:
        raise Exception("Type %s is not of type event, or array. Please use an object of type event or array for the tgf"%type(tgf))
