/***********************************************************
LIGHT-1 Background Simulation > Run Action
------------------------------------------------------------

This class defines two methods one to be exectuted at the
beginning of a run and one more at the end. These two 
commands collect the particles send over the run and save
their energy depositions on a csv file to be read by anyone.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef RunAction_HH
#define RunAction_HH

#include "G4UserRunAction.hh"
#include "G4String.hh"

class RunAction : public G4UserRunAction
{
    friend class RunActionMaster;
    
    public:
        RunAction();
        ~RunAction() override;

        void BeginOfRunAction(const G4Run*) override;
        void   EndOfRunAction(const G4Run*) override;
    
    private:
        static void BookAnalysis(G4String filename = "TEST.csv", G4bool ntupleMerging = false);

};

#endif