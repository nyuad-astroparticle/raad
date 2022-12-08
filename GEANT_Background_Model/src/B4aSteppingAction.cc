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
/// \file B4aSteppingAction.cc
/// \brief Implementation of the B4aSteppingAction class

#include "B4aSteppingAction.hh"
#include "B4aEventAction.hh"
#include "B4aDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aSteppingAction::B4aSteppingAction(
                      const B4aDetectorConstruction* detectorConstruction,
                      B4aEventAction* eventAction)
  : G4UserSteppingAction(),
    fDetConstruction(detectorConstruction),
    fEventAction(eventAction)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aSteppingAction::~B4aSteppingAction()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aSteppingAction::UserSteppingAction(const G4Step* step)
{
// Collect energy and track length step by step

  // get volume of the current step
  G4VPhysicalVolume* volume 
    = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  G4String volu=volume->GetName();
  G4Track* track = step->GetTrack();
  G4int pid = track->GetParentID();
  G4int trid= track->GetTrackID();
  G4StepPoint* preStepPoint = step->GetPreStepPoint();
  
  // energy deposit
  G4double edep = step->GetTotalEnergyDeposit();
  G4double temp1,temp2,temp3,temp4,tempTOT,tempVETO,tempMomentive,tempAlbox,tempEncl;
  // step length
  G4double stepLength = 0.;
  if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    stepLength = step->GetStepLength();
  }

  
  if (volu == "Crystal1"){ //-- gianmarco
        temp1 = step->GetTotalEnergyDeposit();
	fEventAction->Edep1 = fEventAction->Edep1 + temp1;
	/*
	        G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
	       << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
	*/
  }
  
  if (volu == "Crystal2"){ //-- gianmarco
        temp2 = step->GetTotalEnergyDeposit();
        fEventAction->Edep2 = fEventAction->Edep2 + temp2;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }

  if (volu == "Crystal3"){ //-- gianmarco
        temp3 = step->GetTotalEnergyDeposit();
        fEventAction->Edep3 = fEventAction->Edep3 + temp3;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }

  if (volu == "Crystal4"){ //-- gianmarco
        temp4 = step->GetTotalEnergyDeposit();
        fEventAction->Edep4 = fEventAction->Edep4 + temp4;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }

if (volu == "oalboxhPV"){ //-- gianmarco
        tempAlbox = step->GetTotalEnergyDeposit();
        fEventAction->EdepAlbox = fEventAction->EdepAlbox + tempAlbox;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }
 if (volu == "ovetoboxhPV"){ //-- gianmarco
        tempVETO =step->GetTotalEnergyDeposit();
	fEventAction->EdepVETO = fEventAction->EdepVETO + tempVETO;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }

 if (volu == "oMomentiveboxPV"){ //-- gianmarco
        tempMomentive =step->GetTotalEnergyDeposit();
	fEventAction->EdepMomentive = fEventAction->EdepMomentive + tempMomentive;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }

if (volu == "ofiberglasshPV"){ //-- Adriano
        tempEncl =step->GetTotalEnergyDeposit();
	fEventAction->EdepEnclosure = fEventAction->EdepEnclosure + tempEncl;
        /*
                G4cout << " process: "
               << " E_k0 = " << step->GetPreStepPoint()->GetKineticEnergy()*MeV
               << " E_k  = " << step->GetTrack()->GetKineticEnergy()*MeV
               << " deposited energy: " << step->GetTotalEnergyDeposit()*MeV << G4endl;
        */
  }


  if (volu == "Crystal1"||volu == "Crystal2"||volu == "Crystal3"||volu == "Crystal4"){ //-- gianmarco
  tempTOT= step->GetTotalEnergyDeposit();
  fEventAction->EdepTOT = fEventAction->EdepTOT + tempTOT;
  } 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
