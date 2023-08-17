/***********************************************************
LIGHT-1 Background Simulation > Action Initialization
कार्यान्वयन
------------------------------------------------------------

Defines how the Geant4 simulation is going to perform each
step. This is the class that puts all the *Action* Classes
together so that Geant can understand them.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Include the relevant headerfile
#include "ActionInitialization.hh"

// Include the rest of the headers
#include "RunAction.hh"
#include "EventAction.hh"
// #include "SteppingAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "TrackingAction.hh"


// Iniclude relevant Geant4 libraries


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ActionInitialization::~ActionInitialization() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Set the run action as the overarching Run Manager of all threads
void ActionInitialization::BuildForMaster() const 
{
    SetUserAction(new RunAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Set the action initializatin for each of the threads
void ActionInitialization::Build() const
{
    EventAction* eventAction = new EventAction;

    SetUserAction(new RunAction);
    SetUserAction(eventAction);
    SetUserAction(new PrimaryGeneratorAction(eventAction));
    // SetUserAction(new SteppingAction(eventAction));
    SetUserAction(new TrackingAction);
}