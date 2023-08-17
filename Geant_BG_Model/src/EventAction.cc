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
#include "G4AnalysisManager.hh"
#include "G4Event.hh"
#include "DetectorHit.hh"
#include "G4SystemOfUnits.hh"
#include "G4TrajectoryContainer.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Constructor
EventAction::EventAction() : G4UserEventAction()
{
    // Set all the energies to zero
    energyDepCrystals = new G4double[4];
    zeroTrackers();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Destructor
EventAction::~EventAction(){
    delete[] energyDepCrystals;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Zeroes everything
void EventAction::zeroTrackers()
{
    // Initialize Class Parameters
    for(int i=0;i<4;i++) energyDepCrystals[i] = 0;
    energyDepVeto           = 0;
    energyDepEnclosure      = 0;
    energyDepMomentive      = 0;
    energyDepAluminiumBox   = 0;
    energyInitial           = 0;
    particle                = "";
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* event){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
    auto eventHitsCollections = event->GetHCofThisEvent();
    auto analysisManager = G4AnalysisManager::Instance();

    for (int i=0;i<eventHitsCollections->GetNumberOfCollections();i++){
        auto eventHitsCollection = static_cast<HitsCollection*> (eventHitsCollections->GetHC(i));

        for (int j=0;j<eventHitsCollection->GetSize();j++){
            DetectorHit* hit = (*eventHitsCollection)[j];
            
            analysisManager->FillNtupleIColumn(0,event->GetEventID());
            analysisManager->FillNtupleIColumn(1,hit->getTrackID());
            analysisManager->FillNtupleSColumn(2,hit->getParticle());
            analysisManager->FillNtupleDColumn(3,hit->getEnergyDeposited()/MeV);
            analysisManager->FillNtupleDColumn(4,hit->getPosition()[0]);
            analysisManager->FillNtupleDColumn(5,hit->getPosition()[1]);
            analysisManager->FillNtupleDColumn(6,hit->getPosition()[2]);
            analysisManager->FillNtupleDColumn(7,hit->getTime()/ns);
            analysisManager->FillNtupleSColumn(8,hit->getVolume());
            analysisManager->FillNtupleDColumn(9,hit->getInitialEnergy()/keV);
            analysisManager->FillNtupleSColumn(10,hit->getOrigin());
            analysisManager->FillNtupleIColumn(11,hit->getMigrantID());
            analysisManager->AddNtupleRow();
        }
    }

    // Set all the energies to zero
    zeroTrackers();
}