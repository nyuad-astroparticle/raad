/***********************************************************
LIGHT-1 Background Simulation > Particle Messenger
------------------------------------------------------------

We define a bunch of commands that the user can use during
runtime. These commands, set the particle's energy, type,
whether to sample from a probability distribution, etc.
This class managed the Primary generator action class

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef ParticleMessenger_h
#define ParticleMessenger_h

// Import the class we want to manage with this messenger
#include "PrimaryGeneratorAction.hh"
#include "G4UImessenger.hh"
#include "globals.hh"

// Get instances of useful classes
class PrimaryGeneratorAction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAString;


//Define the manager class
class ParticleMessenger : public G4UImessenger
{
public:
    ParticleMessenger(PrimaryGeneratorAction*);     // Constructor
    ~ParticleMessenger();                           // Destructor

    // Override the method that would be called by default every time we run such a command
    void SetNewValue(G4UIcommand* command, G4String input) override;

private:
    PrimaryGeneratorAction* primaryGenerator;       // The object to control
    G4UIdirectory* prefix;                          // The prefix of the commands

    // The available Commands
    G4UIcmdWithAString* setSpectrum;                // Set Set the spectrum by which to sample energies from
    G4UIcmdWithADoubleAndUnit* setEnergy;           // Set the energy of the particle for fixed energies
    G4UIcmdWithAString* selectParticle;             // Select between proton, electron, and gamma
};

#endif