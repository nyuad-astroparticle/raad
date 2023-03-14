/***********************************************************
LIGHT-1 Background Simulation > Run Action
------------------------------------------------------------

This class defines two methods one to be exectuted at the
beginning of a run and one more at the end. These two 
commands collect the particles send over the run and save
their energy depositions on a csv file to be read by anyone.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef RunAction_h
#define RunAction_h

// Include the relevant Geant4 headers
#include "G4UserRunAction.hh"

// The actual RunAction class
class RunAction : public G4UserRunAction
{
  public:
    RunAction();                                        // Constructor
    virtual ~RunAction();                               // Destructor

    virtual void BeginOfRunAction(const G4Run*);        // Method that runs at the beggining, opens the file, etc.
    virtual void   EndOfRunAction(const G4Run*);        // Method that runs at the end, appending the results, etc.
};

#endif