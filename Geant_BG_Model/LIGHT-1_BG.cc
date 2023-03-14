/***********************************************************
LIGHT-1 Background Simulation
------------------------------------------------------------

This is the main file of the GEANT4 background simulation
for LIGHT-1. 

We simulate the charged particle energy depositions along 
each point at the orbit of the payload. I hope you have
as much fun running this as I have had making it :D.

For any help please contact Panos: po524@nyu.edu
***********************************************************/


// We start by including the custom headers for this simulation
#include "DetectorConstruction.hh"      // Builds the detector
#include "ActionInitialization.hh"      // Sets the way particles move through it

// Now we include the GEANT4 headers
#include "QBBC.hh"                      // One of the default lists of physical interactions
#include "G4RunManagerFactory.hh"       // Predefined stuff to build the simulation
#include "G4UImanager.hh"               // Predefined stuff to build the UI
#include "G4VisExecutive.hh"            // Visualization stuff
#include "G4UIExecutive.hh"             // Manage Interactive User Interface


int main(int argc, char** argv){
    // Create the default run manager
    auto runManager = G4RunManagerFactory::CreateRunManager();

    // Create the UI
    auto ui = new G4UIExecutive(argc,argv);

    // Initialize the detector, physics etc.
    runManager->SetUserInitialization(new DetectorConstruction());

    // Add the physics using the default interactions of particles
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(0);
    runManager->SetUserInitialization(physicsList);

    // Tell Geant4 to use our way of stepping the particles
    runManager->SetUserInitialization(new ActionInitialization());

    // Initialize Run Manager
    runManager->Initialize();

    // Create the visualization environment
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    // Add UI elements
    G4UImanager* uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand("/run/verbose 1");
    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVolume");

    // Start the UI
    ui->SessionStart();   

    // Terminate the Simulation
    delete visManager;
    delete ui;
    delete runManager;
    return 0;
}