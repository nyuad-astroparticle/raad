#include "SensitiveDetector.hh"
#include "G4SDManager.hh"
#include "TrackInformation.hh"

SensitiveDetector::SensitiveDetector(const G4String& name, const G4String& hitsCollectionName)
: G4VSensitiveDetector(name)
{
    collectionName.insert(hitsCollectionName);
}

void SensitiveDetector::Initialize(G4HCofThisEvent* hitsCollection)
{
    this->hitsCollection = new HitsCollection(SensitiveDetectorName, collectionName[0]);

    G4int hitsCollectionId = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);   
    hitsCollection->AddHitsCollection(hitsCollectionId,this->hitsCollection);
}

G4bool SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history)
{
    G4double edep = step->GetTotalEnergyDeposit();


    // if(edep == 0.0) return false;
    G4String parentVolume = "NA";
    if (step->GetTrack()->GetOriginTouchable()){
        parentVolume = step->GetTrack()->GetOriginTouchable()->GetVolume()->GetName();
    }

    // Get the migrantID if any
    G4int migrantID = -1;
    if (step->GetTrack()->GetUserInformation()){
        TrackInformation* info  = static_cast<TrackInformation*> (step->GetTrack()->GetUserInformation());
        migrantID               = info->GetMigrantID();
    }


    auto hit = new DetectorHit();
    hit->setTrackID(step->GetTrack()->GetTrackID());
    hit->setParticle(step->GetTrack()->GetParticleDefinition()->GetParticleName());
    hit->setEnergyDeposited(edep);
    hit->setPosition(step->GetPostStepPoint()->GetPosition());
    hit->setTime(step->GetPostStepPoint()->GetLocalTime());
    hit->setVolume(step->GetPreStepPoint()->GetPhysicalVolume()->GetName());
    hit->setInitialEnergy   (step->GetTrack()->GetVertexKineticEnergy());
    hit->setOrigin(parentVolume);
    hit->setMigrantID       (migrantID);

    hitsCollection->insert(hit);

    return true;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent* hitsCollection){
    if ( verboseLevel>1 ) {
     G4int nofHits = this->hitsCollection->entries();
     G4cout << G4endl
            << "-------->Hits Collection: in this event they are " << nofHits
            << " hits in the tracker chambers: " << G4endl;
     for ( G4int i=0; i<nofHits; i++ ) (*(this->hitsCollection))[i]->Print();
  }
}
