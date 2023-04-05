/***********************************************************
LIGHT-1 Background Simulation > Run Action
ΕΚΤΕΛΕΣΗ
------------------------------------------------------------

Uses a Geant4 defined CSV manager thingy that will compile
the track information (i.e. energies deposited and stuff) to
a single CSV and saves it. The directories are managed by UI
commands in a messenger.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Include the corresponding header
#include "RunAction.hh"

// Include Geant4 relevant headers
#include "AnalysisManager.hh"
#include "G4Run.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Constructor
RunAction::RunAction() : G4UserRunAction()
{
    // Start the analysis manager
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    
    // Create a Default filename that can be changed by the user using UI commands
    G4String defaultFilename = "light1_background_results";
    analysisManager->SetFileName(defaultFilename);
    analysisManager->SetNtupleMerging(true);
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Destructor
RunAction::~RunAction(){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* run)
{
    // Print that you are staring a run
    G4cout << ">>> Run " << run->GetRunID() << " starting..." << G4endl;

    auto analysisManager = G4AnalysisManager::Instance();       // Get an instance of the running analysis manager
    G4String filename = analysisManager->GetFileName();         // Get the filename the user has set (or default)
    analysisManager->OpenFile(filename);                        // Open the file

    // Create the structure of the data as an Ntuple (Table)
    analysisManager->CreateNtuple("L1BG","LIGHT-1 Background Energy Depositions");
    analysisManager->CreateNtupleSColumn("Particle");
    analysisManager->CreateNtupleIColumn("EventID");
    analysisManager->CreateNtupleDColumn("EnergyInitial");
    analysisManager->CreateNtupleDColumn("EdepCrystal1");
    analysisManager->CreateNtupleDColumn("EdepCrystal2");
    analysisManager->CreateNtupleDColumn("EdepCrystal3");
    analysisManager->CreateNtupleDColumn("EdepCrystal4");
    analysisManager->CreateNtupleDColumn("EdepVeto");
    analysisManager->CreateNtupleDColumn("EdepEnclosure");
    analysisManager->CreateNtupleDColumn("EdepMomentive");
    analysisManager->CreateNtupleDColumn("EdepAluminiumBox");
    analysisManager->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* run)
{
    // Save the data to the file
    auto analysisManager = G4AnalysisManager::Instance();       // Get an instance of the running analysis manager 
    analysisManager->Write();                                   // Write the accumulated data to the file
    analysisManager->CloseFile();                               // Close it
    analysisManager->Reset();                                   // Clear the bUFfeR
}