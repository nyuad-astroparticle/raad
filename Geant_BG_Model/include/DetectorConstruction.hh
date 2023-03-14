/***********************************************************
LIGHT-1 Background Simulation > DETECTOR Construction
------------------------------------------------------------

We define the detector using boxes with specific materials, 
sizes, etc. Perhaps in the future we could use a GDML file
to add the 3D model instead.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef DetectorConstruction_h
#define DetectorConstruction_h

// Include some libraries from Geant4
#include "G4VUserDetectorConstruction.hh"       // Elements used to construct the detector
#include "globals.hh"                           // Global variables in some sense

// Say that we will overload some the Geant4 predefined classes
class G4VPhysicalVolume;
class G4LogicalVolume;

// The main class that builds a detector with its coordinate system
class DetectorConstruction : public G4VUserDetectorConstruction
{

public:
    DetectorConstruction();                         // Constructor
    virtual ~DetectorConstruction();                // Destructor

    // Functions relevant to building the geometry
    virtual G4VPhysicalVolume* Construct();         // Main Geometry Builder


private:
    void DefineMaterials();                         // Define the materials used
    G4VPhysicalVolume* DefineVolumes();             // Construct the geometry of the material

};


#endif