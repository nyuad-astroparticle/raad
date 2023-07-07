/***********************************************************
LIGHT-1 Background Simulation > Particle Messenger
تطبيق
------------------------------------------------------------

We define a bunch of commands that the user can use during
runtime. These commands, set the particle's energy, type,
whether to sample from a probability distribution, etc.
This class managed the Primary generator action class

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Include the relevant headerfile
#include "ParticleMessenger.hh"

// Include the headerfile of the target class
#include "PrimaryGeneratorAction.hh"

// Include Geant4 Predefined headers
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4UIcommand.hh"
#include <fstream>

using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ParticleMessenger::ParticleMessenger(PrimaryGeneratorAction* primaryGeneratorAction)
// Constructor
    : G4UImessenger(), 
    primaryGenerator(primaryGeneratorAction)
{
    // Define the command prefix the thing you type before you use the command
    prefix = new G4UIdirectory("/light1/");
    prefix->SetGuidance("Control particle generation parameters");

    //----------------------- Define the rest of the commands -----------------------
    
    // Set energy
    setEnergy = new G4UIcmdWithADoubleAndUnit("/light1/setEnergy",this);                // Command Name
    setEnergy->SetGuidance("Set the enrgy of the particle");                            // Guidance Line 1
    setEnergy->SetGuidance(" turns off random energy sampling");                        // Guidance Line 2
    setEnergy->SetParameterName("energy",false);                                        // Single un-omittable parameter
    setEnergy->SetUnitCategory("Energy");                                               // Unit cateogry
    setEnergy->SetDefaultValue(100);                                                    // Default Value
    setEnergy->SetDefaultUnit("MeV");                                                   // Unit for default value
    setEnergy->AvailableForStates(G4State_Idle);                                        // Available only when nothing is currently running

    // Set Spectrum
    setSpectrum = new G4UIcmdWithAString("/light1/setSpectrum",this);                   // Command Name
    setSpectrum->SetGuidance("Sets the fit parameters for sampling an energy spectrum");// Guidance Line 1
    setSpectrum->SetGuidance(" turns on random energy sampling");                       // Guidance Line 2
    setSpectrum->SetParameterName("filename",false);                                    // Parameter Names, all un-omittable
    setSpectrum->SetDefaultValue("./test.txt");                                         // Default values
    setSpectrum->AvailableForStates(G4State_Idle);                                      // Available only when nothing is currently running

    //Select Particle
    selectParticle = new G4UIcmdWithAString("/light1/selectParticle",this);             // Command Name
    selectParticle->SetGuidance("Select the particle to shoot");                        // Guidance Line 1
    selectParticle->SetGuidance(" between proton, electron, and gamma");                // Guidance Line 2
    selectParticle->SetParameterName("particleName",false);                             // Single Unskippable Parameter
    selectParticle->SetDefaultValue("proton");                                          // Default Value
    selectParticle->SetCandidates("proton electron gamma");                             // Available Options (seperated by single spaces)
    selectParticle->AvailableForStates(G4State_Idle);                                   // Available only when nothing is currently running

    // Select crystal
    selectCrystal = new G4UIcmdWithAnInteger("/light1/selectCrystal",this);             // Command Name
    selectCrystal->SetGuidance("Select the crystal you want the particles to hit");     // Guidance Line 1
    selectCrystal->SetGuidance(" enter 1-4 for crystals, 0 for the entire detector.");  // Guidance Line 2
    selectCrystal->SetParameterName("crystal",false);                                   // Single un-omittable parameter
    selectCrystal->SetDefaultValue(0);                                                  // Default Value
    selectCrystal->AvailableForStates(G4State_Idle);                                    // Available only when nothing is currently running

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Destructor
ParticleMessenger::~ParticleMessenger()
{
    delete prefix;
    delete setSpectrum;
    delete setEnergy;
    delete selectParticle;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Handle invoking the actuall command 
void ParticleMessenger::SetNewValue(G4UIcommand* command, G4String input)
{
    // Create an ugly nested if else block to do so
    if (command == setEnergy){                                                          // Set Energy Command
        G4double newEnergy  = setEnergy->GetNewDoubleValue(input);                      // Get the new energy
        G4double newUnit    = setEnergy->GetNewUnitValue(input);                        // Get the new unit
        primaryGenerator->setEnergy(newEnergy*newUnit);                                 // Set the energy of the particles
    }

    else if (command == setSpectrum){                                                   // Set Spectrum Command
        G4String filename = input;                                                      // Get the filename

        ifstream spectrum_file(filename);                                               // Open a file
        G4String unit="MeV";                                                                  // First line is the unit
        int lines = 1;                                                                      // Second line is the number of rows

        spectrum_file >> unit;                                                          // Collect the unit from the file
        spectrum_file >> lines;                                                         // Collect the number of rows

        G4double* pdf       = new G4double[lines];                                      // Store the pdf
        G4double* energy    = new G4double[lines];                                      // Store the energies
        for (int i=0; i<lines; i++) spectrum_file >> energy[i] >> pdf[i];               // Get both from each line
        spectrum_file.close();                                                          // Close the file

        primaryGenerator->setEnergy(pdf, energy, lines, G4UIcommand::ValueOf(unit));    // Set the energy of the primary generator to sample the spectrum
    }
    
    else if (command == selectParticle){                                                // Select Particle Command
        G4String newParticle = input;                                                   // Get the particle as it is
        auto particleTable = G4ParticleTable::GetParticleTable();                       // Get the particle table

        // Find which particle it is
        if (!input.compare("proton"))
            primaryGenerator->setParticle(particleTable->FindParticle("proton"));       // Set the particle to a proton
        else if (!input.compare("electron"))
            primaryGenerator->setParticle(particleTable->FindParticle("e-"));           // Set the particle to an electron
        else if (!input.compare("gamma")) 
            primaryGenerator->setParticle(particleTable->FindParticle("gamma"));        // Set the particle to a photon
    }

    // Create an ugly nested if else block to do so
    if (command == selectCrystal){                                                      // Set Energy Command
        G4double newCrystal  = selectCrystal->GetNewIntValue(input);                    // Get the new energy
        primaryGenerator->selectCrystal(newCrystal);                                    // Set the energy of the particles
    }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
