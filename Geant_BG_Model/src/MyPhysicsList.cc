#include "MyPhysicsList.hh"

MyPhysicsList::MyPhysicsList() : G4VUserPhysicsList() {
    defaultCutValue = 1.0 * mm; // Set your default cut value for tracking (modify as needed).
    SetVerboseLevel(1); // Set the verbosity level (modify as needed).
}

MyPhysicsList::~MyPhysicsList() {}

void MyPhysicsList::ConstructParticle() {
    // You can construct particles if necessary, but for most cases, this is not required.
}

void MyPhysicsList::ConstructProcess() {
    // Add standard electromagnetic physics
    RegisterPhysics(new G4EmStandardPhysics_option4());

    // Add optical physics
    RegisterPhysics(new G4OpticalPhysics());

    // Create and configure the scintillation process
    G4Scintillation* scintillationProcess = new G4Scintillation();
    scintillationProcess->SetScintillationYieldFactor(1.0); // Set the scintillation yield factor (modify as needed).
    scintillationProcess->SetTrackSecondariesFirst(true); // Set whether to track secondaries first (modify as needed).

    // Register the scintillation process to cerium bromide
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "gamma"; // Change this to the appropriate particle name if you want to apply scintillation to other particles.
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
    if (particle) {
        G4ProcessManager* processManager = particle->GetProcessManager();
        processManager->AddProcess(scintillationProcess);
        processManager->SetProcessOrderingToLast(scintillationProcess, idxAtRest);
        processManager->SetProcessOrderingToLast(scintillationProcess, idxPostStep);
    }
}

void MyPhysicsList::SetCuts() {
    // Set production thresholds for particles (modify as needed).
    SetCutsWithDefault();
}
