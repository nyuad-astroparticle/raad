/***********************************************************
LIGHT-1 Background Simulation > Primary Generation Action
------------------------------------------------------------

This is where we create the particles. It creates a particle
Gun, it sets the energy, the momentum and all that stuff.
It also chooses wisely from within an energy range.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h

// Include the custom event class because we want to pass information to it about the generation of the primaries
#include "EventAction.hh"

// Import Some Default classes
#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

// Get instances of some of the useful G4 predefined classes
class G4ParticleGun;                                            // Get it? Because it shoots the particle XDDDDD
class G4Event;                                                  // The event is a collection of shots
class G4ParticleDefinition;                                     // Store parameters of a particle
class ParticleMessenger;                                        // Class that handles user input

// The main Primary Generation class
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction(EventAction* eventAction);           // Constructor
    ~PrimaryGeneratorAction() override;                         // Destructor

    // Public methods to manage the particle production
    void setParticle(G4ParticleDefinition* particle);           // Sets the particle
    void setRandomizeEnergy(G4bool randomizeEnergy);            // Sets if the energy is randomized from a given spectrum or not
    void setEnergy(G4double energy);                            // Sets the fixed Energy
    void setEnergy(G4ThreeVector spectrumFit, G4double unit);   // Sets the Parameters for sampling the energy

    // The method that generates the particles
    virtual void GeneratePrimaries(G4Event* event) override;
    
private:
    G4ParticleGun* particleGun;                                 // The particle Gun Used
    ParticleMessenger* particleMessenger;                       // Handles the parameters of the run
    G4ParticleDefinition* particle;                             // The particle to shoot
    G4double energy;                                            // Particle energy if needed
    G4bool randomizeEnergy;                                     // Decides if energy is randomized based on parameters or fixed
    G4double randomUnit;                                        // Energy unit to be used if the energy is set randomly
    G4ThreeVector spectrumFit;                                  // Parameters for randomizing energy
    G4double SampleEnergy();                                    // Samples an energy at random given the spectrumFit Parameters
    G4ThreeVector SampleStartPosition();                        // Samples a starting position outside of the detector
    G4ThreeVector SampleMomentumDirection(G4ThreeVector start); // Samples momentum direction so that the particle hits the detector
    EventAction* eventAction;                                   // Event Action instance that collects the imformation of the primaries generated
};

#endif