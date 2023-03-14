/***********************************************************
LIGHT-1 Background Simulation > Stepping Action
------------------------------------------------------------

We want to identify when the particle hits the volumes and
store the energy deposited durin the hit. Here we override
the stepping class in order to store those things.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef SteppingAction_h
#define SteppingAction_h

// Include Geant4 predefined headers
#include "G4UserSteppingAction.hh"

// Fake define the needed classes
class EventAction;

// Stepping action class
class SteppingAction : public G4UserSteppingAction
{
public:
    // Constructor and Destructor
    SteppingAction(EventAction* eventAction);
    virtual ~SteppingAction();

    // Overload the method that is called at the end of each step
    virtual void UserSteppingAction(const G4Step* step);

private:
    // Kepp track of your event action
    EventAction* eventAction;
};

#endif