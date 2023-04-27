/***********************************************************
LIGHT-1 Background Simulation > Sensitive Detector
------------------------------------------------------------

The object we need to attach to a logical volume in order
to force Geant4 to keep track of the energy deposited by the
particles that cross it.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef SensitiveDetector_h
#define SensitiveDetector_h

// Include the template library from Geant4
#include "G4VSensitiveDetector.hh"

// The sensitive detector class
class SensitiveDetector : public G4VSensitiveDetector
{
public:
    SensitiveDetector(G4String name);                       // Constructor
    ~SensitiveDetector();                                   // Destructor

    // Override class to save the enrgy on each hit
    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);

    // Things to do before and after an event
    void Initialize(G4HCofThisEvent* hitContainer);         // Called at the beggining
    void EndOfEvent(G4HCofThisEvent* hitContainer);         // Called at the end
};

#endif