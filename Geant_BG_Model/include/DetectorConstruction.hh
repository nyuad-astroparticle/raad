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
#include "SensitiveDetector.hh"
#include "G4SDManager.hh"

// Say that we will overload some the Geant4 predefined classes
class G4VPhysicalVolume;
class G4LogicalVolume;

// The main class that builds a detector with its coordinate system
class DetectorConstruction : public G4VUserDetectorConstruction
{

public:
    DetectorConstruction();                         // Constructor
    virtual ~DetectorConstruction();                // Destructor

    G4VPhysicalVolume *Construct() override;
    void ConstructSDandField() override;


private:
    void DefineMaterials();                         // Define the materials used
    G4VPhysicalVolume* DefineVolumes();             // Construct the geometry of the material

    G4LogicalVolume* crystalLogicalVolumeLBC        = nullptr;  
    G4LogicalVolume* crystalLogicalVolumeCeBr3      = nullptr;  
    G4LogicalVolume* aluminiumBoxLogicalVolume      = nullptr;
    G4LogicalVolume* vetoLogicalVolume              = nullptr;
    G4LogicalVolume* momentiveLogicalVolume         = nullptr;
    G4LogicalVolume* fiberglassLogicalVolume        = nullptr;
};


#endif