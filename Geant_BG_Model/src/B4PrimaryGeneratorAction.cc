


//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
// 
/// \file B4PrimaryGeneratorAction.cc
/// \brief Implementation of the B4PrimaryGeneratorAction class

#include "B4PrimaryGeneratorAction.hh"
#include "B4aEventAction.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "TRandom3.h"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4PrimaryGeneratorAction::B4PrimaryGeneratorAction(B4aEventAction* eventAction)
 : G4VUserPrimaryGeneratorAction(),
   fEventAction(eventAction),
   fParticleGun(0)
{
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);

  // default particle kinematic
  //
//  G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("e-");
G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
//G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("proton");
  fParticleGun->SetParticleDefinition(particleDefinition);
// fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.5,1.));
//fParticleGun -> SetParticleEnergy(30000*keV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4PrimaryGeneratorAction::~B4PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // This function is called at the begining of event

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get world volume
  // from G4LogicalVolumeStore
  //
  G4double teta,steta,phi;
  G4double dirX,dirY,dirZ,TestEmission;
  G4double PartSelectParameter = 0.99999; //Adriano
/////////////////////////////////////////////////////////
  //G4double BR1 = 0.02; //Adriano
  //G4double BR2 = 0.98; //Adriano
///////////////////////////////////////////////////////  
//G4double BR1 = 0.; //Adriano
  //G4double BR2 = 0.2; //Adriano
  //G4double BR3 = 0.4; //Adriano
  //G4double BR4 = 0.6; //Adriano
  //G4double BR5 = 0.8; //Adriano
//////////////////////////////////////////////////////////
  G4double BR1 = 0.02; //Adriano
  G4double BR2 = 0.04; //Adriano
  G4double BR3 = 0.06; //Adriano
  G4double BR4 = 0.08; //Adriano
  G4double BR5 = 0.1; //Adriano
  G4double BR6 = 0.12; //Adriano
  G4double BR7 = 0.14; //Adriano
  G4double BR8 = 0.16; //Adriano
  G4double BR9 = 0.18; //Adriano
  G4double BR10 = 0.2; //Adriano
  G4double BR11 = 0.22; //Adriano
  G4double BR12 = 0.24; //Adriano
  G4double BR13 = 0.26; //Adriano
  G4double BR14 = 0.28; //Adriano
  G4double BR15 = 0.30; //Adriano
  G4double BR16 = 0.32; //Adriano
  G4double BR17 = 0.34; //Adriano
  G4double BR18 = 0.36; //Adriano
  G4double BR19 = 0.38; //Adriano
  G4double BR20 = 0.40; //Adriano
  G4double BR21 = 0.42; //Adriano
  G4double BR22 = 0.44; //Adriano
  G4double BR23 = 0.46; //Adriano
  G4double BR24 = 0.48; //Adriano
  G4double BR25 = 0.50; //Adriano
  G4double BR26 = 0.52; //Adriano
  G4double BR27 = 0.54; //Adriano
  G4double BR28 = 0.56; //Adriano
  G4double BR29 = 0.58; //Adriano
  G4double BR30 = 0.60; //Adriano
  G4double BR31 = 0.62; //Adriano
  G4double BR32 = 0.64; //Adriano
  G4double BR33 = 0.66; //Adriano
  G4double BR34 = 0.68; //Adriano
  G4double BR35 = 0.70; //Adriano
  G4double BR36 = 0.72; //Adriano
  G4double BR37 = 0.74; //Adriano
  G4double BR38 = 0.76; //Adriano
  G4double BR39 = 0.78; //Adriano
  G4double BR40 = 0.80; //Adriano
  G4double BR41 = 0.82; //Adriano
  G4double BR42 = 0.84; //Adriano
  G4double BR43 = 0.86; //Adriano
  G4double BR44 = 0.88; //Adriano
  G4double BR45 = 0.90; //Adriano
  G4double BR46 = 0.92; //Adriano
  G4double BR47 = 0.94; //Adriano
  G4double BR48 = 0.96; //Adriano
  G4double BR49 = 0.98; //Adriano
  G4double BR50 = 1.; //Adriano

  G4double kineticEnergy;
  G4double worldZHalfLength = 0;
  G4LogicalVolume* worlLV
    = G4LogicalVolumeStore::GetInstance()->GetVolume("World");
  G4Box* worldBox = 0;
  if ( worlLV) worldBox = dynamic_cast< G4Box*>(worlLV->GetSolid()); 
  if ( worldBox ) {
    worldZHalfLength = worldBox->GetZHalfLength();  
  }
  else  {
    G4cerr << "World volume of box not found." << G4endl;
    G4cerr << "Perhaps you have changed geometry." << G4endl;
    G4cerr << "The gun will be place in the center." << G4endl;
  } 
  
  // Set particle position
  
  //fParticleGun->SetParticlePosition(G4ThreeVector( -60*mm, 14*mm, 0*mm));
 // fParticleGun->SetParticlePosition(G4ThreeVector( -20*mm, 20*mm, -40*mm)); //Impact Point FRONT (No Veto)
  fParticleGun->SetParticlePosition(G4ThreeVector( -40*mm, 20*mm, 0*mm)); //Impact Point Veto side
  // Set particle energy
  
//   if (G4UniformRand() > BR1)    kineticEnergy = 20*keV+G4UniformRand()*19980*keV;  //Adriano, uniform spectrum
// else  kineticEnergy = 511*keV; //Adriano, 511 keV line on top of the uniform gamma spectrum
//
//kineticEnergy = 1000*keV; //Adriano For Electrons
//kineticEnergy = 20000*keV+G4UniformRand()*500000*keV;  //Adriano, uniform spectrum
//kineticEnergy = G4UniformRand()*400*keV;  //Adriano

 //if (G4UniformRand() < BR2)    kineticEnergy = 300*keV;  //Adriano
 //else if (BR2 <G4UniformRand() < BR3)    kineticEnergy = 650*keV;  //Adriano
 //else if (BR3 <G4UniformRand() < BR4)    kineticEnergy = 1300*keV;  //Adriano
 //else if (BR4 <G4UniformRand() < BR5)    kineticEnergy = 1650*keV;  //Adriano
 //else      kineticEnergy = 511*keV;  //Adriano



// ADRIANO: for GAMMAS

TestEmission = G4UniformRand();
if (0. <TestEmission < BR1)    kineticEnergy = 10*keV;  //Adriano
else if (BR1 <TestEmission < BR2)    kineticEnergy = 30*keV;  //Adriano
else if (BR2 <TestEmission < BR3)    kineticEnergy = 50*keV;  //Adriano
else if (BR3 <TestEmission < BR4)    kineticEnergy = 80*keV;  //Adriano
else if (BR4 <TestEmission < BR5)    kineticEnergy = 100*keV;  //Adriano
else if (BR5 <TestEmission < BR6)    kineticEnergy = 150*keV;  //Adriano
else if (BR6 <TestEmission < BR7)    kineticEnergy = 200*keV;  //Adriano
else if (BR7 <TestEmission < BR8)    kineticEnergy = 250*keV;  //Adriano
else if (BR8 <TestEmission < BR9)    kineticEnergy = 300*keV;  //Adriano
else if (BR9 <TestEmission < BR10)    kineticEnergy = 350*keV;  //Adriano
else if (BR10 <TestEmission < BR11)    kineticEnergy = 400*keV;  //Adriano
else if (BR11 <TestEmission < BR12)    kineticEnergy = 450*keV;  //Adriano
else if (BR12 <TestEmission < BR13)    kineticEnergy = 500*keV;  //Adriano
else if (BR13 <TestEmission < BR14)    kineticEnergy = 550*keV;  //Adriano
else if (BR14 <TestEmission < BR15)    kineticEnergy = 600*keV;  //Adriano
else if (BR15 <TestEmission < BR16)    kineticEnergy = 650*keV;  //Adriano
else if (BR16 <TestEmission < BR17)    kineticEnergy = 700*keV;  //Adriano
else if (BR17 <TestEmission < BR18)    kineticEnergy = 750*keV;  //Adriano
else if (BR18 <TestEmission < BR19)    kineticEnergy = 800*keV;  //Adriano
else if (BR19 <TestEmission < BR20)    kineticEnergy = 850*keV;  //Adriano
else if (BR20 <TestEmission < BR21)    kineticEnergy = 900*keV;  //Adriano
else if (BR21 <TestEmission < BR22)    kineticEnergy = 950*keV;  //Adriano
else if (BR22 <TestEmission < BR23)    kineticEnergy = 1000*keV;  //Adriano
else if (BR23 <TestEmission < BR24)    kineticEnergy = 1500*keV;  //Adriano
else if (BR24 <TestEmission < BR25)    kineticEnergy = 2000*keV;  //Adriano
else if (BR25 <TestEmission < BR26)    kineticEnergy = 2500*keV;  //Adriano
else if (BR26 <TestEmission < BR27)    kineticEnergy = 3000*keV;  //Adriano
else if (BR27 <TestEmission < BR28)    kineticEnergy = 3500*keV;  //Adriano
else if (BR28 <TestEmission < BR29)    kineticEnergy = 4000*keV;  //Adriano
else if (BR29 <TestEmission < BR30)    kineticEnergy = 4500*keV;  //Adriano
else if (BR30 <TestEmission < BR31)    kineticEnergy = 5000*keV;  //Adriano
else if (BR31 <TestEmission < BR32)    kineticEnergy = 6000*keV;  //Adriano
else if (BR32 <TestEmission < BR33)    kineticEnergy = 7000*keV;  //Adriano
else if (BR33 <TestEmission < BR34)    kineticEnergy = 8000*keV;  //Adriano
else if (BR34 <TestEmission < BR35)    kineticEnergy = 9000*keV;  //Adriano
else if (BR35 <TestEmission < BR36)    kineticEnergy = 10000*keV;  //Adriano
else if (BR36 <TestEmission < BR37)    kineticEnergy = 11000*keV;  //Adriano
else if (BR37 <TestEmission < BR38)    kineticEnergy = 12000*keV;  //Adriano
else if (BR38 <TestEmission < BR39)    kineticEnergy = 13000*keV;  //Adriano
else if (BR39 <TestEmission < BR40)    kineticEnergy = 14000*keV;  //Adriano
else if (BR40 <TestEmission < BR41)    kineticEnergy = 15000*keV;  //Adriano
else if (BR41 <TestEmission < BR42)    kineticEnergy = 16000*keV;  //Adriano
else if (BR42 <TestEmission < BR43)    kineticEnergy = 17000*keV;  //Adriano
else if (BR43 <TestEmission < BR44)    kineticEnergy = 18000*keV;  //Adriano
else if (BR44 <TestEmission < BR45)    kineticEnergy = 19000*keV;  //Adriano
else if (BR45 <TestEmission < BR46)    kineticEnergy = 20000*keV;  //Adriano
else if (BR46 <TestEmission < BR47)    kineticEnergy = 25000*keV;  //Adriano
else if (BR47 <TestEmission < BR48)    kineticEnergy = 30000*keV;  //Adriano
else if (BR48 <TestEmission < BR49)    kineticEnergy = 40000*keV;  //Adriano
else if (BR49 <TestEmission < BR50)    kineticEnergy = 50000*keV;  //Adriano
else      kineticEnergy = 60000*keV;  //Adriano

// ADRIANO: for PROTONS

//TestEmission = G4UniformRand();
//if (0. <TestEmission < BR1)    kineticEnergy = 1*MeV;  //Adriano
// else if (BR1 <TestEmission < BR2)    kineticEnergy = 10*MeV;  //Adriano
// else if (BR2 <TestEmission < BR3)    kineticEnergy = 15*MeV;  //Adriano
//  else if (BR3 <TestEmission < BR4)    kineticEnergy = 20*MeV;  //Adriano
 //else if (BR4 <TestEmission < BR5)    kineticEnergy = 25*MeV;  //Adriano
//  else if (BR5 <TestEmission < BR6)    kineticEnergy = 30*MeV;  //Adriano
//  else if (BR6 <TestEmission < BR7)    kineticEnergy = 35*MeV;  //Adriano
//  else if (BR7 <TestEmission < BR8)    kineticEnergy = 40*MeV;  //Adriano
//  else if (BR8 <TestEmission < BR9)    kineticEnergy = 45*MeV;  //Adriano
//  else if (BR9 <TestEmission < BR10)    kineticEnergy = 50*MeV;  //Adriano
//  else if (BR10 <TestEmission < BR11)    kineticEnergy = 55*MeV;  //Adriano
//  else if (BR11 <TestEmission < BR12)    kineticEnergy = 60*MeV;  //Adriano
//  else if (BR12 <TestEmission < BR13)    kineticEnergy = 65*MeV;  //Adriano
//  else if (BR13 <TestEmission < BR14)    kineticEnergy = 70*MeV;  //Adriano
//  else if (BR14 <TestEmission < BR15)    kineticEnergy = 75*MeV;  //Adriano
//  else if (BR15 <TestEmission < BR16)    kineticEnergy = 80*MeV;  //Adriano
//  else if (BR16 <TestEmission < BR17)    kineticEnergy = 85*MeV;  //Adriano
//  else if (BR17 <TestEmission < BR18)    kineticEnergy = 90*MeV;  //Adriano
//  else if (BR18 <TestEmission < BR19)    kineticEnergy = 95*MeV;  //Adriano
//  else if (BR19 <TestEmission < BR20)    kineticEnergy = 100*MeV;  //Adriano
//  else if (BR20 <TestEmission < BR21)    kineticEnergy = 110*MeV;  //Adriano
//  else if (BR21 <TestEmission < BR22)    kineticEnergy = 120*MeV;  //Adriano
//  else if (BR22 <TestEmission < BR23)    kineticEnergy = 130*MeV;  //Adriano
//  else if (BR23 <TestEmission < BR24)    kineticEnergy = 150*MeV;  //Adriano
//  else if (BR24 <TestEmission < BR25)    kineticEnergy = 200*MeV;  //Adriano
//  else if (BR25 <TestEmission < BR26)    kineticEnergy = 250*MeV;  //Adriano
//  else if (BR26 <TestEmission < BR27)    kineticEnergy = 300*MeV;  //Adriano
//  else if (BR27 <TestEmission < BR28)    kineticEnergy = 350*MeV;  //Adriano
//  else if (BR28 <TestEmission < BR29)    kineticEnergy = 400*MeV;  //Adriano
//  else if (BR29 <TestEmission < BR30)    kineticEnergy = 450*MeV;  //Adriano
//  else if (BR30 <TestEmission < BR31)    kineticEnergy = 500*MeV;  //Adriano
//  else if (BR31 <TestEmission < BR32)    kineticEnergy = 600*MeV;  //Adriano
//  else if (BR32 <TestEmission < BR33)    kineticEnergy = 700*MeV;  //Adriano
//  else if (BR33 <TestEmission < BR34)    kineticEnergy = 800*MeV;  //Adriano
//  else if (BR34 <TestEmission < BR35)    kineticEnergy = 900*MeV;  //Adriano
//  else if (BR35 <TestEmission < BR36)    kineticEnergy = 1000*MeV;  //Adriano
//  else if (BR36 <TestEmission < BR37)    kineticEnergy = 1100*MeV;  //Adriano
//  else if (BR37 <TestEmission < BR38)    kineticEnergy = 1200*MeV;  //Adriano
//  else if (BR38 <TestEmission < BR39)    kineticEnergy = 1300*MeV;  //Adriano
//  else if (BR39 <TestEmission < BR40)    kineticEnergy = 1400*MeV;  //Adriano
//  else if (BR40 <TestEmission < BR41)    kineticEnergy = 1500*MeV;  //Adriano
//  else if (BR41 <TestEmission < BR42)    kineticEnergy = 1600*MeV;  //Adriano
//  else if (BR42 <TestEmission < BR43)    kineticEnergy = 1700*MeV;  //Adriano
//  else if (BR43 <TestEmission < BR44)    kineticEnergy = 1800*MeV;  //Adriano
//  else if (BR44 <TestEmission < BR45)    kineticEnergy = 1900*MeV;  //Adriano
//  else if (BR45 <TestEmission < BR46)    kineticEnergy = 2000*MeV;  //Adriano
//  else if (BR46 <TestEmission < BR47)    kineticEnergy = 2500*MeV;  //Adriano
//  else if (BR47 <TestEmission < BR48)    kineticEnergy = 3000*MeV;  //Adriano
//  else if (BR48 <TestEmission < BR49)    kineticEnergy = 4000*MeV;  //Adriano
//  else if (BR49 <TestEmission < BR50)    kineticEnergy = 5000*MeV;  //Adriano
// else      kineticEnergy = 6000*MeV;  //Adriano


// ADRIANO: for ELECTRONS

//TestEmission = G4UniformRand();
//if (0. <TestEmission < BR1)    kineticEnergy = 10*keV;  //Adriano
//else if (BR1 <TestEmission < BR2)    kineticEnergy = 30*keV;  //Adriano
//else if (BR2 <TestEmission < BR3)    kineticEnergy = 50*keV;  //Adriano
//else if (BR3 <TestEmission < BR4)    kineticEnergy = 80*keV;  //Adriano
//else if (BR4 <TestEmission < BR5)    kineticEnergy = 100*keV;  //Adriano
//else if (BR5 <TestEmission < BR6)    kineticEnergy = 150*keV;  //Adriano
//else if (BR6 <TestEmission < BR7)    kineticEnergy = 200*keV;  //Adriano
//else if (BR7 <TestEmission < BR8)    kineticEnergy = 250*keV;  //Adriano
//else if (BR8 <TestEmission < BR9)    kineticEnergy = 300*keV;  //Adriano
//else if (BR9 <TestEmission < BR10)    kineticEnergy = 350*keV;  //Adriano
//else if (BR10 <TestEmission < BR11)    kineticEnergy = 400*keV;  //Adriano
//else if (BR11 <TestEmission < BR12)    kineticEnergy = 450*keV;  //Adriano
//else if (BR12 <TestEmission < BR13)    kineticEnergy = 500*keV;  //Adriano
//else if (BR13 <TestEmission < BR14)    kineticEnergy = 550*keV;  //Adriano
//else if (BR14 <TestEmission < BR15)    kineticEnergy = 600*keV;  //Adriano
//else if (BR15 <TestEmission < BR16)    kineticEnergy = 650*keV;  //Adriano
//else if (BR16 <TestEmission < BR17)    kineticEnergy = 700*keV;  //Adriano
//else if (BR17 <TestEmission < BR18)    kineticEnergy = 750*keV;  //Adriano
//else if (BR18 <TestEmission < BR19)    kineticEnergy = 800*keV;  //Adriano
//else if (BR19 <TestEmission < BR20)    kineticEnergy = 850*keV;  //Adriano
//else if (BR20 <TestEmission < BR21)    kineticEnergy = 900*keV;  //Adriano
//else if (BR21 <TestEmission < BR22)    kineticEnergy = 950*keV;  //Adriano
//else if (BR22 <TestEmission < BR23)    kineticEnergy = 1000*keV;  //Adriano
//else if (BR23 <TestEmission < BR24)    kineticEnergy = 1100*keV;  //Adriano
//else if (BR24 <TestEmission < BR25)    kineticEnergy = 1200*keV;  //Adriano
//else if (BR25 <TestEmission < BR26)    kineticEnergy = 1300*keV;  //Adriano
//else if (BR26 <TestEmission < BR27)    kineticEnergy = 1400*keV;  //Adriano
//else if (BR27 <TestEmission < BR28)    kineticEnergy = 1500*keV;  //Adriano
//else if (BR28 <TestEmission < BR29)    kineticEnergy = 1600*keV;  //Adriano
//else if (BR29 <TestEmission < BR30)    kineticEnergy = 1700*keV;  //Adriano
//else if (BR30 <TestEmission < BR31)    kineticEnergy = 1800*keV;  //Adriano
//else if (BR31 <TestEmission < BR32)    kineticEnergy = 1900*keV;  //Adriano
//else if (BR32 <TestEmission < BR33)    kineticEnergy = 2000*keV;  //Adriano
//else if (BR33 <TestEmission < BR34)    kineticEnergy = 2100*keV;  //Adriano
//else if (BR34 <TestEmission < BR35)    kineticEnergy = 2200*keV;  //Adriano
//else if (BR35 <TestEmission < BR36)    kineticEnergy = 2300*keV;  //Adriano
//else if (BR36 <TestEmission < BR37)    kineticEnergy = 2400*keV;  //Adriano
//else if (BR37 <TestEmission < BR38)    kineticEnergy = 2500*keV;  //Adriano
//else if (BR38 <TestEmission < BR39)    kineticEnergy = 3000*keV;  //Adriano
//else if (BR39 <TestEmission < BR40)    kineticEnergy = 3500*keV;  //Adriano
//else if (BR40 <TestEmission < BR41)    kineticEnergy = 4000*keV;  //Adriano
//else if (BR41 <TestEmission < BR42)    kineticEnergy = 4500*keV;  //Adriano
//else if (BR42 <TestEmission < BR43)    kineticEnergy = 5000*keV;  //Adriano
//else if (BR43 <TestEmission < BR44)    kineticEnergy = 6000*keV;  //Adriano
//else if (BR44 <TestEmission < BR45)    kineticEnergy = 7000*keV;  //Adriano
//else if (BR45 <TestEmission < BR46)    kineticEnergy = 8000*keV;  //Adriano
//else if (BR46 <TestEmission < BR47)    kineticEnergy = 9000*keV;  //Adriano
//else if (BR47 <TestEmission < BR48)    kineticEnergy = 10000*keV;  //Adriano
//else if (BR48 <TestEmission < BR49)    kineticEnergy = 15000*keV;  //Adriano
//else if (BR49 <TestEmission < BR50)    kineticEnergy = 20000*keV;  //Adriano
//else      kineticEnergy = 30000*keV;  //Adriano

  fParticleGun -> SetParticleEnergy(kineticEnergy);
   
  fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
  
  // Set particle direction
  
  steta  = (G4UniformRand()-0.5)*2.0;
  teta = std::acos(steta);
  phi = G4UniformRand();
  phi*=3.1415926;
  phi*=2.0;
  dirY = std::sin(teta)*std::cos(phi);
  dirX = std::sin(teta)*std::sin(phi);
  dirZ = std::cos(teta);
  //G4ThreeVector v2(dirX,dirY,dirZ);
//G4ThreeVector v2(0,0,1); // interaction point on the front
G4ThreeVector v2(1,0,0); //Entering the VETO
  fParticleGun->SetParticleMomentumDirection(v2);

  
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

