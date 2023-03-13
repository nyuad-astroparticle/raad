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
#include "ActionInitialization.hh"      // Starts the particle hitting stuff

// Now we include the GEANT4 headers
#include "QBBC.hh"                      // One of the default lists of physical interactions
#include "G4RunManagerFactory.hh"       // Predefined stuff to build the simulation
#include "G4UImanager.hh"               // Predefined stuff to build the UI

int main(){
    // Create the default run manager
    auto runManager = G4RunManagerFactory::CreateRunManager();

    // Initialize the detector, physics etc.
    runManager->SetUserInitialization(new DetectorConstruction());

    // Add the physics using the default interactions of particles
    G4VModularPhysicsList* physicsList = new QBBC();
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);




    return 0;
}