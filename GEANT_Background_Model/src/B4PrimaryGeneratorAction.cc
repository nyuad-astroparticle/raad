


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
#include "math.h" 


  //G4double ParamParticleIDphotons = 0.001;
  //G4double ParamParticleIDprotons = 0.8;
  //G4double ParamParticleIDelectrons = 0.9;
  G4double ParamParticleIDphotons = 0.00000000001;
  G4double ParamParticleIDprotons = 0.00000000002;
  G4double ParamParticleIDelectrons = 0.99999999;
  G4double IDprotons = 1.;
  G4double IDelectrons = 2.;
  G4double IDphotons = 3.;
  G4double IDTGF = 4.;
  G4double IDGRB = 5.;
  G4double ParticleLabel;


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
  //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("e-");
//G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("gamma");



  //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("e-");
//G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("proton");
//fParticleGun->SetParticleDefinition(particleDefinition);
};
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
  G4double RandomExtraction = G4UniformRand();
  G4double RandomProtonEnergy = G4UniformRand();
  G4double RandomElectronEnergy = G4UniformRand();
  G4double RandomPhotonEnergy = G4UniformRand();
  G4double kineticEnergy;
  G4double RandomDirection = 0;
//******************************************************************************
//*****************************Occurance Protons********************************
//******************************************************************************
G4double BR0p=0.;
G4double BR1p = 0.0855656;
G4double BR2p = 0.160181;
G4double BR3p = 0.2296;
G4double BR4p = 0.293812;
G4double BR5p = 0.355297;
G4double BR6p = 0.413184;
G4double BR7p = 0.467921;
G4double BR8p = 0.519456;
G4double BR9p = 0.567262;
G4double BR10p = 0.611256;
G4double BR11p = 0.652409;
G4double BR12p = 0.690291;
G4double BR13p = 0.724056;
G4double BR14p = 0.75392;
G4double BR15p = 0.780544;
G4double BR16p = 0.804348;
G4double BR17p = 0.825839;
G4double BR18p = 0.845329;
G4double BR19p = 0.862967;
G4double BR20p = 0.878695;
G4double BR21p = 0.892662;
G4double BR22p = 0.905062;
G4double BR23p = 0.916348;
G4double BR24p = 0.926719;
G4double BR25p = 0.936293;
G4double BR26p = 0.945056;
G4double BR27p = 0.952875;
G4double BR28p = 0.959773;
G4double BR29p = 0.965795;
G4double BR30p = 0.971023;
G4double BR31p = 0.975545;
G4double BR32p = 0.979448;
G4double BR33p = 0.982828;
G4double BR34p = 0.985912;
G4double BR35p = 0.988809;
G4double BR36p = 0.991554;
G4double BR37p = 0.994134;
G4double BR38p = 0.996454;
G4double BR39p = 0.998419;
G4double BR40p = 1.;
//******************************************************************************
//*****************************Occurance Electrons******************************
//******************************************************************************
G4double BR0e=0.;
G4double BR1e = 0.403629;
G4double BR2e = 0.572978;
G4double BR3e = 0.666602;
G4double BR4e = 0.727977;
G4double BR5e = 0.773829;
G4double BR6e = 0.810259;
G4double BR7e = 0.839317;
G4double BR8e = 0.863366;
G4double BR9e = 0.88392;
G4double BR10e = 0.901584;
G4double BR11e = 0.916767;
G4double BR12e = 0.929809;
G4double BR13e = 0.940957;
G4double BR14e = 0.950466;
G4double BR15e = 0.958566;
G4double BR16e = 0.965452;
G4double BR17e = 0.971279;
G4double BR18e = 0.976198;
G4double BR19e = 0.980356;
G4double BR20e = 0.983866;
G4double BR21e = 0.986784;
G4double BR22e = 0.989168;
G4double BR23e = 0.991139;
G4double BR24e = 0.992802;
G4double BR25e = 0.9942;
G4double BR26e = 0.995347;
G4double BR27e = 0.996283;
G4double BR28e = 0.997051;
G4double BR29e = 0.997679;
G4double BR30e = 0.998186;
G4double BR31e = 0.998599;
G4double BR32e = 0.99894;
G4double BR33e = 0.999217;
G4double BR34e = 0.999432;
G4double BR35e = 0.999598;
G4double BR36e = 0.999726;
G4double BR37e = 0.999823;
G4double BR38e = 0.999895;
G4double BR39e = 0.999953;
G4double BR40e = 1.;
//******************************************************************************
//*****************************Occurrance Photons***********************************
//******************************************************************************
G4double BR0f=0.;
G4double BR1f = 0.717725;
G4double BR2f = 0.87944428189;
G4double BR3f = 0.93564491492;
G4double BR4f = 0.96087244295;
G4double BR5f = 0.97396487446;
G4double BR6f = 0.98160767181;
G4double BR7f = 0.98646952216;
G4double BR8f = 0.98967380153;
G4double BR9f = 0.99189327447;
G4double BR10f = 0.99348397434;
G4double BR11f = 0.99467425853;
G4double BR12f = 0.99558332223;
G4double BR13f = 0.99630463733;
G4double BR14f = 0.99687065087;
G4double BR15f = 0.99732721643;
G4double BR16f = 0.99770031472;
G4double BR17f = 0.99800669227;
G4double BR18f = 0.99826478586;
G4double BR19f = 0.99848827881;
G4double BR20f = 0.99867760266;
G4double BR21f = 0.99883988018;
G4double BR22f = 0.99898106521;
G4double BR23f = 0.99910591220;
G4double BR24f = 0.99921556164;
G4double BR25f = 0.99931177294;
G4double BR26f = 0.99939688561;
G4double BR27f = 0.99947288875;
G4double BR28f = 0.99954141383;
G4double BR29f = 0.99960276915;
G4double BR30f = 0.99965753242;
G4double BR31f = 0.99970662707;
G4double BR32f = 0.99975088877;
G4double BR33f = 0.99979106383;
G4double BR34f = 0.99982780770;
G4double BR35f = 0.99986153885;
G4double BR36f = 0.99989273769;
G4double BR37f = 0.99992184158;
G4double BR38f = 0.99994922443;
G4double BR39f = 0.99997519577;
G4double BR40f = 1.0000000000;
//******************************************************************************
//*****************************Energy Protons (keV)***********************************
//******************************************************************************
G4double Energy1p = 3000;
G4double Energy2p = 11000;
G4double Energy3p = 19000;
G4double Energy4p = 27000;
G4double Energy5p = 35000;
G4double Energy6p = 43000;
G4double Energy7p = 51000;
G4double Energy8p = 59000;
G4double Energy9p = 67000;
G4double Energy10p = 75000;
G4double Energy11p = 83000;
G4double Energy12p = 91000;
G4double Energy13p = 99000;
G4double Energy14p = 107000;
G4double Energy15p = 115000;
G4double Energy16p = 123000;
G4double Energy17p = 131000;
G4double Energy18p = 139000;
G4double Energy19p = 147000;
G4double Energy20p = 155000;
G4double Energy21p = 163000;
G4double Energy22p = 171000;
G4double Energy23p = 179000;
G4double Energy24p = 187000;
G4double Energy25p = 195000;
G4double Energy26p = 203000;
G4double Energy27p = 211000;
G4double Energy28p = 219000;
G4double Energy29p = 227000;
G4double Energy30p = 235000;
G4double Energy31p = 243000;
G4double Energy32p = 251000;
G4double Energy33p = 259000;
G4double Energy34p = 267000;
G4double Energy35p = 275000;
G4double Energy36p = 283000;
G4double Energy37p = 291000;
G4double Energy38p = 299000;
G4double Energy39p = 307000;
G4double Energy40p = 315000;
//******************************************************************************
//*****************************Energy Electrons (keV)*****************************
//******************************************************************************
G4double Energy1e = 125.;
G4double Energy2e = 250.;
G4double Energy3e = 375.;
G4double Energy4e = 500.;
G4double Energy5e = 625.;
G4double Energy6e = 750.;
G4double Energy7e = 875.;
G4double Energy8e = 1000.;
G4double Energy9e = 1125.;
G4double Energy10e = 1250.;
G4double Energy11e = 1375.;
G4double Energy12e = 1500.;
G4double Energy13e = 1625.;
G4double Energy14e = 1750.;
G4double Energy15e = 1875.;
G4double Energy16e = 2000.;
G4double Energy17e = 2125.;
G4double Energy18e = 2250.;
G4double Energy19e = 2375.;
G4double Energy20e = 2500.;
G4double Energy21e = 2625.;
G4double Energy22e = 2750.;
G4double Energy23e = 2875.;
G4double Energy24e = 3000.;
G4double Energy25e = 3125.;
G4double Energy26e = 3250.;
G4double Energy27e = 3375.;
G4double Energy28e = 3500.;
G4double Energy29e = 3625.;
G4double Energy30e = 3750.;
G4double Energy31e = 3875.;
G4double Energy32e = 4000.;
G4double Energy33e = 4125.;
G4double Energy34e = 4250.;
G4double Energy35e = 4375.;
G4double Energy36e = 4500.;
G4double Energy37e = 4625.;
G4double Energy38e = 4750.;
G4double Energy39e = 4875.;
G4double Energy40e = 5000.;
//******************************************************************************
//*****************************Energy Photons (keV)*****************************
//******************************************************************************
G4double Energy1f = 20.;
G4double Energy2f = 40.;
G4double Energy3f = 61.9887;
G4double Energy4f = 84.7962;
G4double Energy5f = 108.152;
G4double Energy6f = 131.925;
G4double Energy7f = 156.035;
G4double Energy8f = 180.43;
G4double Energy9f = 205.07;
G4double Energy10f = 229.928;
G4double Energy11f = 254.98;
G4double Energy12f = 280.208;
G4double Energy13f = 305.597;
G4double Energy14f = 331.135;
G4double Energy15f = 356.812;
G4double Energy16f = 382.617;
G4double Energy17f = 408.542;
G4double Energy18f = 434.582;
G4double Energy19f = 460.729;
G4double Energy20f = 486.978;
G4double Energy21f = 513.324;
G4double Energy22f = 539.762;
G4double Energy23f = 566.289;
G4double Energy24f = 592.9;
G4double Energy25f = 619.592;
G4double Energy26f = 646.363;
G4double Energy27f = 673.208;
G4double Energy28f = 700.126;
G4double Energy29f = 727.113;
G4double Energy30f = 754.169;
G4double Energy31f = 781.289;
G4double Energy32f = 808.473;
G4double Energy33f = 835.719;
G4double Energy34f = 863.024;
G4double Energy35f = 890.387;
G4double Energy36f = 917.807;
G4double Energy37f = 945.281;
G4double Energy38f = 972.809;
G4double Energy39f = 1000.39;
G4double Energy40f = 1028.02;

//******************************************************************************
//*****************************Direction Values EGphotons********************************
//******************************************************************************
G4double THR_EG_0= 0.;
G4double THR_EG_1= 0.25;
G4double THR_EG_2= 0.5;
G4double THR_EG_3= 0.75;
G4double epsilonDIFF=0.00000001;
//******************************************************************************
//*****************************Direction Values GRB********************************
//******************************************************************************
G4double THR_GRB_0= 0.;
G4double THR_GRB_1= 0.25;
G4double THR_GRB_2= 0.5;
G4double THR_GRB_3= 0.75;


//******************************************************************************
//*****************************Direction Values Trapped********************************
//******************************************************************************
G4double THR_trap_0= 0.;
G4double THR_trap_1= 0.2;
G4double THR_trap_2= 0.4;
G4double THR_trap_3= 0.6;
G4double THR_trap_4= 0.8;




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
  //fParticleGun->SetParticlePosition(G4ThreeVector( -40*mm, 20*mm, 0*mm)); //Impact Point Veto side
  // Set particle energy
  
//   if (G4UniformRand() > BR1)    kineticEnergy = 20*keV+G4UniformRand()*19980*keV;  //Adriano, uniform spectrum
// else  kineticEnergy = 511*keV; //Adriano, 511 keV line on top of the uniform gamma spectrum


//**********************************************************************************************************************************
//**********************************************************************************************************************************
//************************************************ Protons+e-, Extragalactic uniformely Distrubuted, Gamma Contamination***************************
//**********************************************************************************************************************************
//**********************************************************************************************************************************
  if   ((ParamParticleIDprotons<RandomExtraction)&&(RandomExtraction<ParamParticleIDelectrons)){
	G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("proton");
	fParticleGun->SetParticleDefinition(particleDefinition);
        fEventAction->ParticleLabel=IDprotons; //1 means Proton	


        if (BR0p<RandomProtonEnergy<BR1p){
	kineticEnergy = Energy1p*keV+G4UniformRand()*8000.*keV;}
        else if (BR1p<RandomProtonEnergy<BR2p){
	kineticEnergy = Energy2p*keV+G4UniformRand()*8000.*keV;}
        else if (BR2p<RandomProtonEnergy<BR3p){
	kineticEnergy = Energy3p*keV+G4UniformRand()*8000.*keV;}
        else if (BR3p<RandomProtonEnergy<BR4p){
	kineticEnergy = Energy4p*keV+G4UniformRand()*8000.*keV;}
        else if (BR4p<RandomProtonEnergy<BR5p){
	kineticEnergy = Energy5p*keV+G4UniformRand()*8000.*keV;}
        else if (BR5p<RandomProtonEnergy<BR6p){
	kineticEnergy = Energy6p*keV+G4UniformRand()*8000.*keV;}
        else if (BR6p<RandomProtonEnergy<BR7p){
	kineticEnergy = Energy7p*keV+G4UniformRand()*8000.*keV;}
        else if (BR7p<RandomProtonEnergy<BR8p){
	kineticEnergy = Energy8p*keV+G4UniformRand()*8000.*keV;}
	else if (BR8p<RandomProtonEnergy<BR9p){
	kineticEnergy = Energy9p*keV+G4UniformRand()*8000.*keV;}
        else if (BR9p<RandomProtonEnergy<BR10p){
	kineticEnergy = Energy10p*keV+G4UniformRand()*8000.*keV;}
        else if (BR10p<RandomProtonEnergy<BR11p){
	kineticEnergy = Energy11p*keV+G4UniformRand()*8000.*keV;}
	else if (BR11p<RandomProtonEnergy<BR12p){
	kineticEnergy = Energy12p*keV+G4UniformRand()*8000.*keV;}
        else if (BR12p<RandomProtonEnergy<BR13p){
	kineticEnergy = Energy13p*keV+G4UniformRand()*8000.*keV;}
        else if (BR13p<RandomProtonEnergy<BR14p){
	kineticEnergy = Energy14p*keV+G4UniformRand()*8000.*keV;}
        else if (BR14p<RandomProtonEnergy<BR15p){
	kineticEnergy = Energy15p*keV+G4UniformRand()*8000.*keV;}
        else if (BR15p<RandomProtonEnergy<BR16p){
	kineticEnergy = Energy16p*keV+G4UniformRand()*8000.*keV;}
        else if (BR16p<RandomProtonEnergy<BR17p){
	kineticEnergy = Energy17p*keV+G4UniformRand()*8000.*keV;}
        else if (BR17p<RandomProtonEnergy<BR18p){
	kineticEnergy = Energy18p*keV+G4UniformRand()*8000.*keV;}
        else if (BR18p<RandomProtonEnergy<BR19p){
	kineticEnergy = Energy19p*keV+G4UniformRand()*8000.*keV;}
	else if (BR19p<RandomProtonEnergy<BR20p){
	kineticEnergy = Energy20p*keV+G4UniformRand()*8000.*keV;}
        else if (BR20p<RandomProtonEnergy<BR21p){
	kineticEnergy = Energy21p*keV+G4UniformRand()*8000.*keV;}
	else if (BR21p<RandomProtonEnergy<BR22p){
	kineticEnergy = Energy22p*keV+G4UniformRand()*8000.*keV;}
        else if (BR22p<RandomProtonEnergy<BR23p){
	kineticEnergy = Energy23p*keV+G4UniformRand()*8000.*keV;}
        else if (BR23p<RandomProtonEnergy<BR24p){
	kineticEnergy = Energy24p*keV+G4UniformRand()*8000.*keV;}
        else if (BR24p<RandomProtonEnergy<BR25p){
	kineticEnergy = Energy25p*keV+G4UniformRand()*8000.*keV;}
        else if (BR25p<RandomProtonEnergy<BR26p){
	kineticEnergy = Energy26p*keV+G4UniformRand()*8000.*keV;}
        else if (BR26p<RandomProtonEnergy<BR27p){
	kineticEnergy = Energy27p*keV+G4UniformRand()*8000.*keV;}
        else if (BR27p<RandomProtonEnergy<BR28p){
	kineticEnergy = Energy28p*keV+G4UniformRand()*8000.*keV;}
        else if (BR28p<RandomProtonEnergy<BR29p){
	kineticEnergy = Energy29p*keV+G4UniformRand()*8000.*keV;}
	else if (BR29p<RandomProtonEnergy<BR30p){
	kineticEnergy = Energy30p*keV+G4UniformRand()*8000.*keV;}
        else if (BR30p<RandomProtonEnergy<BR31p){
	kineticEnergy = Energy31p*keV+G4UniformRand()*8000.*keV;}
	else if (BR31p<RandomProtonEnergy<BR32p){
	kineticEnergy = Energy32p*keV+G4UniformRand()*8000.*keV;}
        else if (BR32p<RandomProtonEnergy<BR33p){
	kineticEnergy = Energy33p*keV+G4UniformRand()*8000.*keV;}
        else if (BR33p<RandomProtonEnergy<BR34p){
	kineticEnergy = Energy34p*keV+G4UniformRand()*8000.*keV;}
        else if (BR34p<RandomProtonEnergy<BR35p){
	kineticEnergy = Energy35p*keV+G4UniformRand()*8000.*keV;}
        else if (BR35p<RandomProtonEnergy<BR36p){
	kineticEnergy = Energy36p*keV+G4UniformRand()*8000.*keV;}
        else if (BR36p<RandomProtonEnergy<BR37p){
	kineticEnergy = Energy37p*keV+G4UniformRand()*8000.*keV;}
        else if (BR37p<RandomProtonEnergy<BR38p){
	kineticEnergy = Energy38p*keV+G4UniformRand()*8000.*keV;}
        else if (BR38p<RandomProtonEnergy<BR39p){
	kineticEnergy = Energy39p*keV+G4UniformRand()*8000.*keV;}
        else if (BR39p<RandomProtonEnergy<BR40p){
	kineticEnergy = Energy40p*keV+G4UniformRand()*8000.*keV;}
        else {kineticEnergy = G4UniformRand()*8000.*keV;}
	fParticleGun -> SetParticleEnergy(kineticEnergy);
	RandomDirection = G4UniformRand();



        if ((RandomDirection>0.)&&(RandomDirection<THR_trap_1)){
        //Set Particle Position Direction From Side 1 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(-40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(1,0,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        else if ((RandomDirection>THR_trap_1)&&(RandomDirection<THR_trap_2)){
	//Set Particle Position Direction From Side 2 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(+40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(-1,0,0);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

	
        else if ((RandomDirection>THR_trap_2)&&(RandomDirection<THR_trap_3)){
	//Set Particle Position Direction From Side 3 No Veto (EG Photons+Trapped+GRB)
          
	fParticleGun->SetParticlePosition(G4ThreeVector((-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm,-40*mm)); //Impact Point
	G4ThreeVector v2(0,0,1);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        else if ((RandomDirection>THR_trap_3)&&(RandomDirection<THR_trap_4)){
	//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,-1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
	}
        //else if (RandomDirection>0.75){
	//else if (RandomDirection>(THR_GRB_3+epsilonDIFF)){
	else {
	//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,-1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }
	
}

else if (ParamParticleIDelectrons<RandomExtraction){
	G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("e-");
	fParticleGun->SetParticleDefinition(particleDefinition);
	fEventAction->ParticleLabel=IDelectrons; //2 means Electrons

	if (BR0e<RandomElectronEnergy<BR1e){
	kineticEnergy = Energy1e*keV+G4UniformRand()*125*keV;}
        else if (BR1e<RandomElectronEnergy<BR2e){
	kineticEnergy = Energy2e*keV+G4UniformRand()*125*keV;}
        else if (BR2e<RandomElectronEnergy<BR3e){
	kineticEnergy = Energy3e*keV+G4UniformRand()*125*keV;}
        else if (BR3e<RandomElectronEnergy<BR4e){
	kineticEnergy = Energy4e*keV+G4UniformRand()*125*keV;}
        else if (BR4e<RandomElectronEnergy<BR5e){
	kineticEnergy = Energy5e*keV+G4UniformRand()*125*keV;}
        else if (BR5e<RandomElectronEnergy<BR6e){
	kineticEnergy = Energy6e*keV+G4UniformRand()*125*keV;}
        else if (BR6e<RandomElectronEnergy<BR7e){
	kineticEnergy = Energy7e*keV+G4UniformRand()*125*keV;}
        else if (BR7e<RandomElectronEnergy<BR8e){
	kineticEnergy = Energy8e*keV+G4UniformRand()*125*keV;}
	else if (BR8e<RandomElectronEnergy<BR9e){
	kineticEnergy = Energy9e*keV+G4UniformRand()*125*keV;}
        else if (BR9e<RandomElectronEnergy<BR10e){
	kineticEnergy = Energy10e*keV+G4UniformRand()*125*keV;}
        else if (BR10e<RandomElectronEnergy<BR11e){
	kineticEnergy = Energy11e*keV+G4UniformRand()*125*keV;}
	else if (BR11e<RandomElectronEnergy<BR12e){
	kineticEnergy = Energy12e*keV+G4UniformRand()*125*keV;}
        else if (BR12e<RandomElectronEnergy<BR13e){
	kineticEnergy = Energy13e*keV+G4UniformRand()*125*keV;}
        else if (BR13e<RandomElectronEnergy<BR14e){
	kineticEnergy = Energy14e*keV+G4UniformRand()*125*keV;}
        else if (BR14e<RandomElectronEnergy<BR15e){
	kineticEnergy = Energy15e*keV+G4UniformRand()*125*keV;}
        else if (BR15e<RandomElectronEnergy<BR16e){
	kineticEnergy = Energy16e*keV+G4UniformRand()*125*keV;}
        else if (BR16e<RandomElectronEnergy<BR17e){
	kineticEnergy = Energy17e*keV+G4UniformRand()*125*keV;}
        else if (BR17e<RandomElectronEnergy<BR18e){
	kineticEnergy = Energy18e*keV+G4UniformRand()*125*keV;}
        else if (BR18e<RandomElectronEnergy<BR19e){
	kineticEnergy = Energy19e*keV+G4UniformRand()*125*keV;}
	else if (BR19e<RandomElectronEnergy<BR20e){
	kineticEnergy = Energy20e*keV+G4UniformRand()*125*keV;}
        else if (BR20e<RandomElectronEnergy<BR21e){
	kineticEnergy = Energy21e*keV+G4UniformRand()*125*keV;}
	else if (BR21e<RandomElectronEnergy<BR22e){
	kineticEnergy = Energy22e*keV+G4UniformRand()*125*keV;}
        else if (BR22e<RandomElectronEnergy<BR23e){
	kineticEnergy = Energy23e*keV+G4UniformRand()*125*keV;}
        else if (BR23e<RandomElectronEnergy<BR24e){
	kineticEnergy = Energy24e*keV+G4UniformRand()*125*keV;}
        else if (BR24e<RandomElectronEnergy<BR25e){
	kineticEnergy = Energy25e*keV+G4UniformRand()*125*keV;}
        else if (BR25e<RandomElectronEnergy<BR26e){
	kineticEnergy = Energy26e*keV+G4UniformRand()*125*keV;}
        else if (BR26e<RandomElectronEnergy<BR27e){
	kineticEnergy = Energy27e*keV+G4UniformRand()*125*keV;}
        else if (BR27e<RandomElectronEnergy<BR28e){
	kineticEnergy = Energy28e*keV+G4UniformRand()*125*keV;}
        else if (BR28e<RandomElectronEnergy<BR29e){
	kineticEnergy = Energy29e*keV+G4UniformRand()*125*keV;}
	else if (BR29e<RandomElectronEnergy<BR30e){
	kineticEnergy = Energy30e*keV+G4UniformRand()*125*keV;}
        else if (BR30e<RandomElectronEnergy<BR31e){
	kineticEnergy = Energy31e*keV+G4UniformRand()*125*keV;}
	else if (BR31e<RandomElectronEnergy<BR32e){
	kineticEnergy = Energy32e*keV+G4UniformRand()*125*keV;}
        else if (BR32e<RandomElectronEnergy<BR33e){
	kineticEnergy = Energy33e*keV+G4UniformRand()*125*keV;}
        else if (BR33e<RandomElectronEnergy<BR34e){
	kineticEnergy = Energy34e*keV+G4UniformRand()*125*keV;}
        else if (BR34e<RandomElectronEnergy<BR35e){
	kineticEnergy = Energy35e*keV+G4UniformRand()*125*keV;}
        else if (BR35e<RandomElectronEnergy<BR36e){
	kineticEnergy = Energy36e*keV+G4UniformRand()*125*keV;}
        else if (BR36e<RandomElectronEnergy<BR37e){
	kineticEnergy = Energy37e*keV+G4UniformRand()*125*keV;}
        else if (BR37e<RandomElectronEnergy<BR38e){
	kineticEnergy = Energy38e*keV+G4UniformRand()*125*keV;}
        else if (BR38e<RandomElectronEnergy<BR39e){
	kineticEnergy = Energy39e*keV+G4UniformRand()*125*keV;}
        else if (BR39e<RandomElectronEnergy<BR40e){
	kineticEnergy = Energy40e*keV+G4UniformRand()*125*keV;}
        else {kineticEnergy = G4UniformRand()*125*keV;}
	fParticleGun -> SetParticleEnergy(kineticEnergy);
	RandomDirection = G4UniformRand();


        if ((RandomDirection>0.)&&(RandomDirection<THR_trap_1)){
        //Set Particle Position Direction From Side 1 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(-40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(1,0,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        else if ((RandomDirection>THR_trap_1)&&(RandomDirection<THR_trap_2)){
	//Set Particle Position Direction From Side 2 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(+40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(-1,0,0);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

	
        else if ((RandomDirection>THR_trap_2)&&(RandomDirection<THR_trap_3)){
	//Set Particle Position Direction From Side 3 No Veto (EG Photons+Trapped+GRB)
          
	fParticleGun->SetParticlePosition(G4ThreeVector((-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm,-40*mm)); //Impact Point
	G4ThreeVector v2(0,0,1);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        else if ((RandomDirection>THR_trap_3)&&(RandomDirection<THR_trap_4)){
	//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,-1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
}
        //else if (RandomDirection>0.75){
	//else if (RandomDirection>(THR_GRB_3+epsilonDIFF)){
	else {
	//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,-1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }
        


        
}
else if ((ParamParticleIDphotons<RandomExtraction)&&(RandomExtraction<ParamParticleIDprotons)){
	G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
	fParticleGun->SetParticleDefinition(particleDefinition);
	fEventAction->ParticleLabel=IDphotons; //3 means Extragalactic Photons
 
	if (BR0f<RandomPhotonEnergy<BR1f){
	kineticEnergy = Energy1f*(1-0.5*G4UniformRand())*keV;}
        else if (BR1f<RandomPhotonEnergy<BR2f){
	kineticEnergy = Energy2f*(1-0.5*G4UniformRand())*keV;}
        else if (BR2f<RandomPhotonEnergy<BR3f){
	kineticEnergy = Energy3f*(1-0.5*G4UniformRand())*keV;}
        else if (BR3f<RandomPhotonEnergy<BR4f){
	kineticEnergy = Energy4f*(1-0.5*G4UniformRand())*keV;}
        else if (BR4f<RandomPhotonEnergy<BR5f){
	kineticEnergy = Energy5f*(1-0.5*G4UniformRand())*keV;}
        else if (BR5f<RandomPhotonEnergy<BR6f){
	kineticEnergy = Energy6f*(1-0.5*G4UniformRand())*keV;}
        else if (BR6f<RandomPhotonEnergy<BR7f){
	kineticEnergy = Energy7f*(1-0.5*G4UniformRand())*keV;}
        else if (BR7f<RandomPhotonEnergy<BR8f){
	kineticEnergy = Energy8f*(1-0.5*G4UniformRand())*keV;}
	else if (BR8f<RandomPhotonEnergy<BR9f){
	kineticEnergy = Energy9f*(1-0.5*G4UniformRand())*keV;}
        else if (BR9f<RandomPhotonEnergy<BR10f){
	kineticEnergy = Energy10f*(1-0.5*G4UniformRand())*keV;}
        else if (BR10f<RandomPhotonEnergy<BR11f){
	kineticEnergy = Energy11f*(1-0.5*G4UniformRand())*keV;}
	else if (BR11f<RandomPhotonEnergy<BR12f){
	kineticEnergy = Energy12f*(1-0.5*G4UniformRand())*keV;}
        else if (BR12f<RandomPhotonEnergy<BR13f){
	kineticEnergy = Energy13f*(1-0.5*G4UniformRand())*keV;}
        else if (BR13f<RandomPhotonEnergy<BR14f){
	kineticEnergy = Energy14f*(1-0.5*G4UniformRand())*keV;}
        else if (BR14f<RandomPhotonEnergy<BR15f){
	kineticEnergy = Energy15f*(1-0.5*G4UniformRand())*keV;}
        else if (BR15f<RandomPhotonEnergy<BR16f){
	kineticEnergy = Energy16f*(1-0.5*G4UniformRand())*keV;}
        else if (BR16f<RandomPhotonEnergy<BR17f){
	kineticEnergy = Energy17f*(1-0.5*G4UniformRand())*keV;}
        else if (BR17f<RandomPhotonEnergy<BR18f){
	kineticEnergy = Energy18f*(1-0.5*G4UniformRand())*keV;}
        else if (BR18f<RandomPhotonEnergy<BR19f){
	kineticEnergy = Energy19f*(1-0.5*G4UniformRand())*keV;}
	else if (BR19f<RandomPhotonEnergy<BR20f){
	kineticEnergy = Energy20f*(1-0.5*G4UniformRand())*keV;}
        else if (BR20f<RandomPhotonEnergy<BR21f){
	kineticEnergy = Energy21f*(1-0.5*G4UniformRand())*keV;}
	else if (BR21f<RandomPhotonEnergy<BR22f){
	kineticEnergy = Energy22f*(1-0.5*G4UniformRand())*keV;}
        else if (BR22f<RandomPhotonEnergy<BR23f){
	kineticEnergy = Energy23f*(1-0.5*G4UniformRand())*keV;}
        else if (BR23f<RandomPhotonEnergy<BR24f){
	kineticEnergy = Energy24f*(1-0.5*G4UniformRand())*keV;}
        else if (BR24f<RandomPhotonEnergy<BR25f){
	kineticEnergy = Energy25f*(1-0.5*G4UniformRand())*keV;}
        else if (BR25f<RandomPhotonEnergy<BR26f){
	kineticEnergy = Energy26f*(1-0.5*G4UniformRand())*keV;}
        else if (BR26f<RandomPhotonEnergy<BR27f){
	kineticEnergy = Energy27f*(1-0.5*G4UniformRand())*keV;}
        else if (BR27f<RandomPhotonEnergy<BR28f){
	kineticEnergy = Energy28f*(1-0.5*G4UniformRand())*keV;}
        else if (BR28f<RandomPhotonEnergy<BR29f){
	kineticEnergy = Energy29f*(1-0.5*G4UniformRand())*keV;}
	else if (BR29f<RandomPhotonEnergy<BR30f){
	kineticEnergy = Energy30f*(1-0.5*G4UniformRand())*keV;}
        else if (BR30f<RandomPhotonEnergy<BR31f){
	kineticEnergy = Energy31f*(1-0.5*G4UniformRand())*keV;}
	else if (BR31f<RandomPhotonEnergy<BR32f){
	kineticEnergy = Energy32f*(1-0.5*G4UniformRand())*keV;}
        else if (BR32f<RandomPhotonEnergy<BR33f){
	kineticEnergy = Energy33f*(1-0.5*G4UniformRand())*keV;}
        else if (BR33f<RandomPhotonEnergy<BR34f){
	kineticEnergy = Energy34f*(1-0.5*G4UniformRand())*keV;}
        else if (BR34f<RandomPhotonEnergy<BR35f){
	kineticEnergy = Energy35f*(1-0.5*G4UniformRand())*keV;}
        else if (BR35f<RandomPhotonEnergy<BR36f){
	kineticEnergy = Energy36f*(1-0.5*G4UniformRand())*keV;}
        else if (BR36f<RandomPhotonEnergy<BR37f){
	kineticEnergy = Energy37f*(1-0.5*G4UniformRand())*keV;}
        else if (BR37f<RandomPhotonEnergy<BR38f){
	kineticEnergy = Energy38f*(1-0.5*G4UniformRand())*keV;}
        else if (BR38f<RandomPhotonEnergy<BR39f){
	kineticEnergy = Energy39f*(1-0.5*G4UniformRand())*keV;}
        else if (BR39e<RandomPhotonEnergy<BR40f){
	kineticEnergy = Energy40f*(1-0.5*G4UniformRand())*keV;}
        else {kineticEnergy = (1-0.5*G4UniformRand())*keV;}
        fParticleGun -> SetParticleEnergy(kineticEnergy);
	RandomDirection = G4UniformRand();
      

        if ((RandomDirection>0.)&&(RandomDirection<THR_EG_1)){
        //Set Particle Position Direction From Side 1 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(-40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(1,0,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        else if ((RandomDirection>THR_EG_1)&&(RandomDirection<THR_EG_2)){
	//Set Particle Position Direction From Side 2 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(+40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(-1,0,0);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

	
        else if ((RandomDirection>THR_EG_2)&&(RandomDirection<THR_EG_3)){
	//Set Particle Position Direction From Side 3 No Veto (EG Photons+Trapped+GRB)
          
	fParticleGun->SetParticlePosition(G4ThreeVector((-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm,-40*mm)); //Impact Point
	G4ThreeVector v2(0,0,1);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        //else if (RandomDirection>0.75){
	//else if (RandomDirection>(THR_GRB_3+epsilonDIFF)){
	else {
	//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,-1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }
}


        else { G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
	fParticleGun->SetParticleDefinition(particleDefinition);
        RandomDirection = G4UniformRand();

        if (G4UniformRand()>0.94){
        //if (G4UniformRand()<0.000001){
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, -40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fEventAction->ParticleLabel=IDTGF; //4 means TGF
        kineticEnergy =15000*G4UniformRand()*keV;
        fParticleGun -> SetParticleEnergy(kineticEnergy);;
        //Set Particle Position Direction From BOTTOM (TGF+Trapped)
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }


        else{
        fEventAction->ParticleLabel=IDGRB; //5 means GRB
        kineticEnergy =20000*G4UniformRand()*keV;
	//kineticEnergy =500*G4UniformRand()*keV;
	fParticleGun -> SetParticleEnergy(kineticEnergy);

	if ((RandomDirection>0.)&&(RandomDirection<THR_GRB_1)){
        //Set Particle Position Direction From Side 1 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(-40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(1,0,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        else if ((RandomDirection>THR_GRB_1)&&(RandomDirection<THR_GRB_2)){
	//Set Particle Position Direction From Side 2 (EG Photons+Trapped+GRB)
	fParticleGun->SetParticlePosition(G4ThreeVector(+40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm));
        G4ThreeVector v2(-1,0,0);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

	
        else if ((RandomDirection>THR_GRB_2)&&(RandomDirection<THR_GRB_3)){
	//Set Particle Position Direction From Side 3 No Veto (EG Photons+Trapped+GRB)
          
	fParticleGun->SetParticlePosition(G4ThreeVector((-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm,-40*mm)); //Impact Point
	G4ThreeVector v2(0,0,1);
	fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }

        //else if (RandomDirection>0.75){
	//else if (RandomDirection>(THR_GRB_3+epsilonDIFF)){
        else {
	//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
        fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
        G4ThreeVector v2(0,-1,0);
        fParticleGun->SetParticleMomentumDirection(v2);
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
        }
        }
        
}
        //fParticleGun->SetParticleMomentumDirection(v2);
	//fParticleGun->GeneratePrimaryVertex(anEvent);
	//fEventAction->nrgpri = fParticleGun->GetParticleEnergy();


	


//**********************************************************************************************************************************
//**********************************************************************************************************************************
//Set Particle Position Direction From Side 1 (EG Photons+Trapped+GRB)
//fParticleGun->SetParticlePosition(G4ThreeVector( -40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
//G4ThreeVector v2(1,0,0);
//fParticleGun->SetParticleMomentumDirection(v2);
//fParticleGun->GeneratePrimaryVertex(anEvent);
//fEventAction->nrgpri = fParticleGun->GetParticleEnergy();

//Set Particle Position Direction From Side 2 (EG Photons+Trapped+GRB)
//fParticleGun->SetParticlePosition(G4ThreeVector( +40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
//G4ThreeVector v2(-1,0,0);
//fParticleGun->SetParticleMomentumDirection(v2);
//fParticleGun->GeneratePrimaryVertex(anEvent);
//fEventAction->nrgpri = fParticleGun->GetParticleEnergy();

//Set Particle Position Direction From Side 3 No Veto (EG Photons+Trapped+GRB)
//fParticleGun->SetParticlePosition(G4ThreeVector((-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm,-40*mm)); //Impact Point
//G4ThreeVector v2(0,0,1);
//fParticleGun->SetParticleMomentumDirection(v2);
//fParticleGun->GeneratePrimaryVertex(anEvent);
//fEventAction->nrgpri = fParticleGun->GetParticleEnergy();

//Set Particle Position Direction From TOP(EG Photons+Trapped+GRB)
//fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, 40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
//G4ThreeVector v2(0,-1,0);
//fParticleGun->SetParticleMomentumDirection(v2);
//fParticleGun->GeneratePrimaryVertex(anEvent);
//fEventAction->nrgpri = fParticleGun->GetParticleEnergy();

//Set Particle Position Direction From BOTTOM (TGF+Trapped)
//fParticleGun->SetParticlePosition(G4ThreeVector( (-23+46*G4UniformRand())*mm, -40*mm, (-21+42*G4UniformRand())*mm)); //Impact Point
//G4ThreeVector v2(0,1,0);
//fParticleGun->SetParticleMomentumDirection(v2);
//fParticleGun->GeneratePrimaryVertex(anEvent);
//fEventAction->nrgpri = fParticleGun->GetParticleEnergy();












// Set particle position
  
  ////fParticleGun->SetParticlePosition(G4ThreeVector( -60*mm, 14*mm, 0*mm));
 ////fParticleGun->SetParticlePosition(G4ThreeVector( -20*mm, 20*mm, -40*mm)); //Impact Point FRONT (No Veto)
  ////fParticleGun->SetParticlePosition(G4ThreeVector( -40*mm, 20*mm, 0*mm)); //Impact Point Veto side
//**//fParticleGun->SetParticlePosition(G4ThreeVector( -40*mm, (-23+46*G4UniformRand())*mm, (-21+42*G4UniformRand())*mm)); //Impact Point Veto side
////fParticleGun->SetParticlePosition(G4ThreeVector( -40*mm, +23*mm, (-21+42*G4UniformRand())*mm)); //Impact Point Veto side
  ////fParticleGun -> SetParticleEnergy(kineticEnergy);
   
  ////fEventAction->nrgpri = fParticleGun->GetParticleEnergy();
  
  // Set particle direction
  
  //steta  = (G4UniformRand()-0.5)*2.0;
  //teta = std::acos(steta);
  //phi = G4UniformRand();
  //phi*=3.1415926;
  //phi*=2.0;
  //dirY = std::sin(teta)*std::cos(phi);
  //dirX = std::sin(teta)*std::sin(phi);
  //dirZ = std::cos(teta);
  //dirZ = std::sin(teta)*std::cos(phi);
  //dirX = std::sin(teta)*std::sin(phi);
  //dirY = std::cos(teta);
  //dirX = std::sin(teta)*std::cos(phi);
  //dirZ = std::sin(teta)*std::sin(phi);
  //dirY = std::cos(teta);
  //G4ThreeVector v2(dirX,dirY,dirZ);
 //G4ThreeVector v2(0,0,1); // interaction point on the front
  //*//G4ThreeVector v2(1,0,0); //Entering the VETO
 //*// fParticleGun->SetParticleMomentumDirection(v2);
  //*//fParticleGun->GeneratePrimaryVertex(anEvent);
  //fParticleGun -> SetParticleEnergy(kineticEnergy);
 //*// fEventAction->nrgpri = fParticleGun->GetParticleEnergy();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

