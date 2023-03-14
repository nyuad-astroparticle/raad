/***********************************************************
LIGHT-1 Background Simulation > Event Action
IMPLEMENTAZIONE
------------------------------------------------------------

Each event is a particle shot to the detector. Here we
define the variables we want to keep track of during one
event. We will tell Geant4 what to do before and after it
sends the particles.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Include the corresponding headefile
#include "EventAction.hh"

// Include Geant4 predefined headers
#include "AnalysisManager.hh"
#include "G4Event.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Constructor
EventAction::EventAction() : G4UserEventAction()
{
    // Set all the energies to zero
    zeroTrackers();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Destructor
EventAction::~EventAction(){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Zeroes everything
void EventAction::zeroTrackers()
{
    // Initialize Class Parameters
    energyDepCrystals = new G4double[4];
    for(int i=0;i<3;i++) energyDepCrystals[i] = 0;
    energyDepVeto           = 0;
    energyDepEnclosure      = 0;
    energyDepMomentive      = 0;
    energyDepAluminiumBox   = 0;
    energyInitial           = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* event)
{
    // Set all the energies to zero
    zeroTrackers();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
    // Get the analysis Manager
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    G4cout << "Hello from End of Event Action" << G4endl;
    
    // Add all the energies to the Analysis Manager
    analysisManager->FillNtupleSColumn(0,0,particle);
    analysisManager->FillNtupleIColumn(0,1,event->GetEventID());
    analysisManager->FillNtupleDColumn(0,2,energyInitial);
    G4cout << "Almost Bye from End of Event Action" << G4endl;
    analysisManager->FillNtupleDColumn(0,3,energyDepCrystals[0]);
    analysisManager->FillNtupleDColumn(0,4,energyDepCrystals[1]);
    analysisManager->FillNtupleDColumn(0,5,energyDepCrystals[2]);
    analysisManager->FillNtupleDColumn(0,6,energyDepCrystals[3]);
    analysisManager->FillNtupleDColumn(0,7,energyDepVeto);
    analysisManager->FillNtupleDColumn(0,8,energyDepEnclosure);
    analysisManager->FillNtupleDColumn(0,9,energyDepMomentive);
    analysisManager->FillNtupleDColumn(0,10,energyDepAluminiumBox);
    analysisManager->AddNtupleRow();

    G4cout << "Bye from End of Event Action" << G4endl;
}