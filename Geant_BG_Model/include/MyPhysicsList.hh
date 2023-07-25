
#include "G4VUserPhysicsList.hh"
#include "G4OpticalPhysics.hh"
#include "G4Scintillation.hh"
#include "G4EmStandardPhysics_option4.hh" 

class MyPhysicsList : public G4VUserPhysicsList {
public:
    MyPhysicsList();
    virtual ~MyPhysicsList();

    virtual void ConstructParticle();
    virtual void ConstructProcess();
    virtual void SetCuts();
};