/***********************************************************
LIGHT-1 Background Simulation > Primary Generation Action
IMPLEMENTACIÓN
------------------------------------------------------------

This is where we create the particles. It creates a particle
Gun, it sets the energy, the momentum and all that stuff.
It also chooses wisely from within an energy range.

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Import the relevant header
#include "PrimaryGeneratorAction.hh"

// Include the messenger header that manages this class using the UI
#include "ParticleMessenger.hh"

// Include other Geant4 relevant headers
#include "G4ParticleGun.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4PhysicalConstants.hh"
#include "G4AnalysisManager.hh"

// Define a constant
#define SAT_ANGLE 1.225533143 // Half angle of the tangent cone at the earth from the satellite

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Constructor
PrimaryGeneratorAction::PrimaryGeneratorAction(EventAction* eventAction)
    : G4VUserPrimaryGeneratorAction()
{
    // Set the energy picking parameters
    randomizeEnergy     = false;
    entries             = 1;
    probability         = new G4double[entries];
    energies            = new G4double[entries];
    energy              = 1.0 * MeV;
    randomUnit          = MeV;

    // Set Up the particle Gun
    G4int numberOfParticles = 1;
    particleGun             = new G4ParticleGun(numberOfParticles);

    // Set particle gun default parameters (they should change according to user input during the run)
    particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");     // Proton as default particle
    particleGun->SetParticleDefinition(particle);                               // Particle Definition
    particleGun->SetParticleMomentumDirection(G4ThreeVector(1,0,0));            // Momentum Direction
    particleGun->SetParticleEnergy(energy);                                    // Initial Energy
    particleGun->SetParticlePosition(G4ThreeVector(-1.0*cm,0.0*cm,0.0*cm));     // Initial Position

    // Set the event action
    this->eventAction   = eventAction;

    // Start a Messenger
    particleMessenger   = new ParticleMessenger(this); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Destructor
PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete particleGun;
    delete particleMessenger;
    delete[] probability;
    delete[] energies;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Method that actually generates the particles according to any parameters set
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    // G4cout << "Hello From Generate Primaries\n energy parameters are: " << randomizeEnergy << G4endl;

    // Set the particle of the gun
    particleGun->SetParticleDefinition(particle);
    
    // Set the position of the particle gun
    G4ThreeVector position = SampleStartPosition();
    particleGun->SetParticlePosition(position);

    // Set the momentum direction
    G4ThreeVector momentumDirection = SampleMomentumDirection(position);
    particleGun->SetParticleMomentumDirection(momentumDirection);

    // Set the Kinetic energy
    G4double particleEnergy = SampleEnergy();
    particleGun->SetParticleEnergy(particleEnergy);

    // Keep track of the data at the event level
    eventAction->setParticle(particle->GetParticleName());      // Add the particle to row 0
    eventAction->setEnergyInitial(particleEnergy/MeV);          // Add the particle energy in MeV

    // Now add generate the particles to the event
    particleGun->GeneratePrimaryVertex(event);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Randomply pick a starting point around the earth cone
G4ThreeVector PrimaryGeneratorAction::SampleStartPosition()
{
    // Generate an angle outside the tangent cone to the earth

    // Generate a random position outside
    G4double theta = (G4UniformRand() * (pi - 0*SAT_ANGLE)) * rad;
    G4double phi   = G4UniformRand() * 2*pi * rad;
    G4double r     = 35 * cm;

    // Then we shift the coordinates so that the origin is at the center of the detector
    G4ThreeVector delta_center = G4ThreeVector(0,-0*71.2/2*mm,0);

    // Calculate the actual position of the particle
    // return G4ThreeVector(5*cm,5*cm,5*cm);
    return G4ThreeVector(r*std::sin(theta)*std::cos(phi), r*std::cos(theta), r*std::sin(theta)*std::sin(phi)) + delta_center;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Sample a momentum direction inside the detector
G4ThreeVector PrimaryGeneratorAction::SampleMomentumDirection(G4ThreeVector position_start)
{
    // Pick a random ending position inside the volume
    G4ThreeVector position_end = G4ThreeVector((G4UniformRand()-0.5)*71.2*mm, (G4UniformRand()-0.5)*71.2*mm, (G4UniformRand()-0.5)*47.6*mm);
    // G4ThreeVector position_end = G4ThreeVector(0*cm,0*cm,0*cm);

    // Set particle Direction
    G4ThreeVector momentum_direction = position_end - position_start;       // Get a vector in the direction
    return momentum_direction/momentum_direction.mag();                     // Nomralize the vector
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Sample an energy for the particle
G4double PrimaryGeneratorAction::SampleEnergy()
{
    // Check if you want to randomize the energy production
    if (!randomizeEnergy) return energy;

    // Otherwise sample the energy space using rejection sampling
    int i=0;
    G4double x,y, p_interp;
    do {
    // Create a random point
    x = G4UniformRand()*(energies[entries-1] - energies[0]) + energies[0];
    y = G4UniformRand();

    // Check if the random point is above the distribution
    for (i=0; i<entries; i++) if (energies[i] >= x) break;
    i--;

    //Interpolate the probability
    p_interp = (probability[i+1]*(x - energies[i]) + probability[i]*(energies[i+1] - x))/(energies[i+1] - energies[i]);
    } while (y > p_interp);

    return x;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::setParticle(G4ParticleDefinition* particle){
    this->particle = particle;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::setRandomizeEnergy(G4bool randomizeEnergy){
    this->randomizeEnergy = randomizeEnergy;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::setEnergy(G4double energy){
    // Stop the simulation from randomizing the energy
    setRandomizeEnergy(false);

    // Set the fixed energy
    this->energy = energy;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::setEnergy(G4double* fprobability, G4double* fenergies, G4int entries, G4double unit){
    // Start the randomization of the energy
    setRandomizeEnergy(true);

    // Delete the previous arrays
    delete[] probability;
    delete[] energies;

    // Set the energy sampling parameters
    this->probability = fprobability;
    this->energies    = fenergies;
    this->entries     = entries;
    this->randomUnit  = unit;
}