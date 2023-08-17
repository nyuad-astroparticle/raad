/***********************************************************
LIGHT-1 Background Simulation > Sensitive Detector
------------------------------------------------------------

The object we need to attach to a logical volume in order
to force Geant4 to keep track of the energy deposited by the
particles that cross it.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef SensitiveDetector_HH
#define SensitiveDetector_HH

#include "G4VSensitiveDetector.hh"
#include "DetectorHit.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
public:
    SensitiveDetector(const G4String& name, const G4String& hitsCollectionName);
    ~SensitiveDetector() override = default;

    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;

    void Initialize(G4HCofThisEvent* hitsCollection) override;
    void EndOfEvent(G4HCofThisEvent* hitsCollection) override;

private:
    HitsCollection* hitsCollection = nullptr;
};

#endif