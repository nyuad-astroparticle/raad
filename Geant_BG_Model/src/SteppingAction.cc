/***********************************************************
LIGHT-1 Background Simulation > Stepping Action
ЖАСАУ
------------------------------------------------------------

We want to identify when the particle hits the volumes and
store the energy deposited durin the hit. Here we override
the stepping class in order to store those things.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Include the corresponding header
#include "SteppingAction.hh"

// Include the headers referenced in the construction
#include "EventAction.hh"

// Include Geant4 relevant headers
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Constructor
SteppingAction::SteppingAction(EventAction* eventAction)
    : G4UserSteppingAction()
{
    // Assign the class variables
    this->eventAction = eventAction;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//Destructor
SteppingAction::~SteppingAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// After every step find the energy deposited and store it in the event action variables
void SteppingAction::UserSteppingAction(const G4Step* step)
{
    // Get the volume name that the stupid particle hit
    G4String volumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();

    // Switch through the possible volumes
    if (!volumeName.compare("Crystal1")) 
        eventAction->setEnergyDepCrystal1(eventAction->getEnergyDepCrystals()[0] + step->GetTotalEnergyDeposit()/MeV);

    else if (!volumeName.compare("Crystal2")) 
        eventAction->setEnergyDepCrystal2(eventAction->getEnergyDepCrystals()[1] + step->GetTotalEnergyDeposit()/MeV);

    else if (!volumeName.compare("Crystal3")) 
        eventAction->setEnergyDepCrystal3(eventAction->getEnergyDepCrystals()[2] + step->GetTotalEnergyDeposit()/MeV);

    else if (!volumeName.compare("Crystal4")) 
        eventAction->setEnergyDepCrystal4(eventAction->getEnergyDepCrystals()[3] + step->GetTotalEnergyDeposit()/MeV);

    else if (!volumeName.compare("aluminiumBox")) 
        eventAction->setEnergyDepAluminiumBox(eventAction->getEnergyDepAluminiumBox() + step->GetTotalEnergyDeposit()/MeV);

    else if (!volumeName.compare("veto")) 
        eventAction->setEnergyDepVeto(eventAction->getEnergyDepVeto() + step->GetTotalEnergyDeposit()/MeV);
    
    else if (!volumeName.compare("momentive")) 
        eventAction->setEnergyDepMomentive(eventAction->getEnergyDepMomentive() + step->GetTotalEnergyDeposit()/MeV);
    
    else if (!volumeName.compare("fiberglass")) 
        eventAction->setEnergyDepEnclosure(eventAction->getEnergyDepEnclosure() + step->GetTotalEnergyDeposit()/MeV);
    
    else if (!volumeName.compare("fiberglass")) 
        eventAction->setEnergyDepEnclosure(eventAction->getEnergyDepEnclosure() + step->GetTotalEnergyDeposit()/MeV);
}
