/***********************************************************
LIGHT-1 Background Simulation > Event Action
------------------------------------------------------------

Each event is a particle shot to the detector. Here we
define the variables we want to keep track of during one
event. We will tell Geant4 what to do before and after it
sends the particles.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef EventAction_h
#define EventAction_h

// Include the G4 Defined building blocks for this custom class
#include "G4UserEventAction.hh"
#include "globals.hh"

// Class to handle Event action
class EventAction : public G4UserEventAction
{
public:
    EventAction();                                          // Constructor
    virtual ~EventAction();                                 // Destructor

    // Begin and end of event
    virtual void BeginOfEventAction(const G4Event* event);  // At the start of the events set parameters to 0
    virtual void   EndOfEventAction(const G4Event* event);  // At the end return them to the run manager

    // Create some Getters
    G4double* getEnergyDepCrystals(){return energyDepCrystals;}
    G4double  getEnergyDepVeto(){return energyDepVeto;}
    G4double  getEnergyDepEnclosure(){return energyDepEnclosure;}
    G4double  getEnergyDepMomentive(){return energyDepMomentive;}
    G4double  getEnergyDepAluminiumBox(){return energyDepAluminiumBox;}
    G4double  getEnergyInitial(){return energyInitial;}
    G4String  getParticle(){return particle;}

    // Create some Setters
    void setEnergyDepCrystals(G4double* EnergyDepCrystals);
    void setEnergyDepCrystal1(G4double EnergyDepCrystal1){energyDepCrystals[0] = EnergyDepCrystal1; return;}
    void setEnergyDepCrystal2(G4double EnergyDepCrystal2){energyDepCrystals[1] = EnergyDepCrystal2; return;}
    void setEnergyDepCrystal3(G4double EnergyDepCrystal3){energyDepCrystals[2] = EnergyDepCrystal3; return;}
    void setEnergyDepCrystal4(G4double EnergyDepCrystal4){energyDepCrystals[3] = EnergyDepCrystal4; return;}
    void setEnergyDepVeto(G4double EnergyDepVeto){energyDepVeto = EnergyDepVeto; return;}
    void setEnergyDepEnclosure(G4double EnergyDepEnclosure){energyDepEnclosure = EnergyDepEnclosure; return;}
    void setEnergyDepMomentive(G4double EnergyDepMomentive){energyDepMomentive = EnergyDepMomentive; return;}
    void setEnergyDepAluminiumBox(G4double EnergyDepAluminiumBox){energyDepAluminiumBox = EnergyDepAluminiumBox; return;}
    void setEnergyInitial(G4double EnergyInitial){energyInitial = EnergyInitial; return;}
    void setParticle(G4String Particle){particle = Particle; return;}

    // Mutator to set parameters to zero
    void zeroTrackers();

private:
    // Some variables to keep track of
    G4double* energyDepCrystals;        // Energy Deposited to Each Crystal
    G4double energyDepVeto;             // Energy Deposited to the Veto
    G4double energyDepEnclosure;        // Energy Deposited to the Enclosure
    G4double energyDepMomentive;        // Energy Deposited to the Momentive (that weird resin)
    G4double energyDepAluminiumBox;     // Energy Deposited to the Aluminium Enclosure
    G4double energyInitial;             // Initial Energy of the particle
    G4String particle;                  // The particle name
};

#endif