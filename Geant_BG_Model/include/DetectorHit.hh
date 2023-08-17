#ifndef DetectorHit_HH
#define DetectorHit_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class DetectorHit : public G4VHit
{
public:
    DetectorHit() = default;
    DetectorHit(const DetectorHit&) = default;
    ~DetectorHit() override = default;

    DetectorHit& operator=(const DetectorHit&) = default;
    G4bool operator==(const DetectorHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    void Draw() override;
    void Print() override;

    void setTrackID(G4int trackID)                      {this->trackID = trackID;};
    void setParticle(G4String particle)                 {this->particle = particle;};
    void setEnergyDeposited(G4double energyDeposited)   {this->energyDeposited = energyDeposited;};
    void setPosition(G4ThreeVector position)            {this->position = position;};
    void setTime(G4double time)                         {this->time = time;};
    void setVolume(G4String volume)                     {this->volume = volume;};
    void setInitialEnergy(G4double initialEnergy)       {this->initialEnergy = initialEnergy;};
    void setOrigin(G4String originVolume)               {this->originVolume = originVolume;};
    void setMigrantID       (G4int migrantID)           {this->migrantID = migrantID; };


    G4int           getTrackID()            {return trackID;};
    G4String        getParticle()           {return particle;};
    G4double        getEnergyDeposited()    {return energyDeposited;};
    G4ThreeVector   getPosition()           {return position;};
    G4double        getTime()               {return time;};
    G4String        getVolume()             {return volume;};
    G4double        getInitialEnergy()      {return initialEnergy;};
    G4String        getOrigin()             {return originVolume;};
    G4int           getMigrantID()          {return migrantID;};


private:
    G4int           trackID             = -1;
    G4String        particle            ="";
    G4double        energyDeposited     = 0;
    G4ThreeVector   position;
    G4double        time                = -1;
    G4String        volume              = "";
    G4int           verboseLevel        = 0;
    G4double        initialEnergy       = 0;
    G4String        originVolume        = "";
    G4int           migrantID           = -1;
};


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

using HitsCollection = G4THitsCollection<DetectorHit>;
extern G4ThreadLocal G4Allocator<DetectorHit>* HitAllocator;

inline void* DetectorHit::operator new(size_t)
{
    if(!HitAllocator) HitAllocator = new G4Allocator<DetectorHit>;
    return (void*) HitAllocator->MallocSingle();
}

inline void DetectorHit::operator delete(void* hit)
{
    HitAllocator->FreeSingle((DetectorHit*) hit);
}

#endif