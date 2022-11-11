# This script downloads all the data until a particular date based on sequence number 
# and stores them in a predefined directory

# Import Libraries
import raadpy as rp
import numpy as np
from tqdm import tqdm
import sys

# Helper Function to delete n lines
CURSOR_UP_ONE   = '\x1b[1A' 
ERASE_LINE      = '\x1b[2K'

def delete_last_lines(wait=True,n=4): 
    for _ in range(n): 
        sys.stdout.write(CURSOR_UP_ONE) 
        sys.stdout.write(ERASE_LINE) 

# Download based on sequence number
def download_seq_nr(fileName:str,start:int=0,end:int=None,MAX:int=5000,start_time:str=None,end_time:str=None):
    # Input processing
    if end is None: end = float('inf')
    
    # Sequence number and other stuff init
    seq         = start
    host        = "https://light1.mcs.nanoavionics.com"
    url         = f'{host}/{fileName}_download?'
    cnt         = 0

    # Initialize array to hold the buffer raw data
    data        = []
    
    # Do unless interrupted
    while seq < end:
        # Find the query for NA Server
        query       = f'seq_nr=gt.{seq}&seq_nr=lte.{seq+MAX}'
        if start_time is not None:  query += f'&archived_ts=gte.{start_time}'
        if end_time   is not None:  query += f'&archived_ts=lt.{end_time}' 
        
        # Print stuff
        print('Current File: ',url+query,'\nEntries Downloaded:',len(data),'\nLast Sequence Number:',seq,'\nIterations:',cnt)

        # Send the query
        new_data    = rp.download_range(url+query,token=rp.TOKEN,limit=-1,VERBOSE=False,clear=lambda wait: None)

        # Update variables
        data        = data + new_data
        seq         = seq + MAX
        cnt        += 1
        
        # Exit condition with searching one last time
        if len(new_data) == 0:
            data = rp.sort(data)    # Sort by "entry_nr"
            break
        
        delete_last_lines()
    return data

# Download script packet
def download_data(filepath:str='./',buffers=range(1,8),MAX:int=5000,start_time:str=None,end_time:str=None):
    # List that holds all the filenames
    filenames = []

    # First go ahead and download all the buffers
    # for buffer in tqdm(buffers,desc='Downloading Buffer'):
    #     # Download the data of the buffer
    #     fileName    = "pc_buff"+str(buffer)
    #     data        = download_seq_nr(fileName,MAX=MAX,start_time=start_time,end_time=end_time)

    #     # Save the data of the buffer
    #     fname   = rp.save_raw_data(data,filepath=filepath,buffer=buffer)
    #     filenames.append(fname)

    # Download the script log
    log         = download_seq_nr('pc_se0_log',MAX=MAX,start_time=start_time,end_time=end_time)
    log         = rp.log_to_ascii(log,fileName=filepath+'light1-se-log.txt')
    decoded_log = rp.log_expand(text=log)

    # Extract the metadata from the logfile
    metadata = rp.log_metadata(decoded_log=decoded_log)

    # Save the datafile as a json on the same directory
    with open(filepath + "metadata.json","w") as meta_file: rp.json.dump(metadata,meta_file,indent=4)

    return metadata

if __name__ == '__main__': 
    download_data(end_time='2022-10-25T06:26:00')