/***********************************************************
LIGHT-1 Background Simulation > Action Initialization
------------------------------------------------------------

Defines how the Geant4 simulation is going to perform each
step. This is the class that puts all the *Action* Classes
together so that Geant can understand them.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef ActionInitialization_h
#define ActionInitialization_h

// Geant4 Predefined Class that deals with initialization
#include "G4VUserActionInitialization.hh"

// Our Custom Class
class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization();                 // Constructor
    ~ActionInitialization();                // Destructor

    void BuildForMaster() const override;   // Build Manager for the simulation
    void Build() const override;            // Build Manager for each thread
};

#endif