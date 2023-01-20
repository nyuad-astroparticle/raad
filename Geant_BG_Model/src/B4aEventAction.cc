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
/// \file B4aEventAction.cc
/// \brief Implementation of the B4aEventAction class

#include "B4aEventAction.hh"
#include "B4RunAction.hh"
#include "B4Analysis.hh"
//#include "B4PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4GenericMessenger.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>
#include "TMath.h"    //--gianmarco
#include "TRandom3.h" //--gianmarco




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aEventAction::B4aEventAction()
 : G4UserEventAction(),
   fMessenger(0),
   fEnergyAbs(0.),
   fEnergyGap(0.),
   fTrackLAbs(0.),
   fTrackLGap(0.),
   fPrintModulo(1)

{
  // Define /B4/event commands using generic messenger class
  fMessenger = new G4GenericMessenger(this, "/B4/event/", "Event control");

  // Define /B4/event/setPrintModulo command
  G4GenericMessenger::Command& setPrintModulo 
    = fMessenger->DeclareProperty("setPrintModulo", 
                                  fPrintModulo, 
                                 "Print events modulo n");
  setPrintModulo.SetRange("value>0");                                
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aEventAction::~B4aEventAction()
{
  delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aEventAction::BeginOfEventAction(const G4Event* evt)
{  

  G4int eventID = evt->GetEventID();
  if ( eventID % 1000 < 10 )  { 
    G4cout << "\n---> Begin of event: " << eventID << G4endl;
    //CLHEP::HepRandom::showEngineStatus();
  }

  // initialisation per event
  //fEnergyAbs = 0.;
  //fEnergyGap = 0.;
  //fTrackLAbs = 0.;
  //fTrackLGap = 0.;
  //EGap = 0.;
  //LAbs = 0.;
  //LGap = 0.;
  //EAbs = 0.;
  Edep1 = 0.;
  Edep2 = 0.;
  Edep3 = 0.;
  Edep4 = 0.;
  e1s=0.;
  e2s=0.;
  e3s=0.;
  e4s=0.;
  EdepTOT = 0.;
  EdepVETO =0.;
  EdepMomentive = 0.; 
  EdepAlbox = 0.;
  EdepEnclosure = 0.;
  eTOTs=0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aEventAction::EndOfEventAction(const G4Event* evt)
{
  // Accumulate statistics
  //
  //double nrgpri  = fParticleGun->GetParticleEnergy();
  // get analysis manager
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

 // sig1 = 0.573*TMath::Sqrt(Edep1*1000);
 // e1s=gRandom->Gaus(Edep1*1000,sig1);
 // sig2 = 0.573*TMath::Sqrt(Edep2*1000);
 // e2s=gRandom->Gaus(Edep2*1000,sig2);
 // sig3 = 0.573*TMath::Sqrt(Edep3*1000);
 // e3s=gRandom->Gaus(Edep3*1000,sig3);
 // sig4 = 0.573*TMath::Sqrt(Edep4*1000);
 // e4s=gRandom->Gaus(Edep4*1000,sig4);
 // sigTOT = 0.573*TMath::Sqrt(EdepTOT*1000);
 // eTOTs=gRandom->Gaus(EdepTOT*1000,sigTOT);

  sig1 = 0.573*TMath::Sqrt(Edep1*1000);
  e1s=gRandom->Gaus(Edep1*1000,sig1)/1000;
  sig2 = 0.573*TMath::Sqrt(Edep2*1000);
  e2s=gRandom->Gaus(Edep2*1000,sig2)/1000;
  sig3 = 0.573*TMath::Sqrt(Edep3*1000);
  e3s=gRandom->Gaus(Edep3*1000,sig3)/1000;
  sig4 = 0.573*TMath::Sqrt(Edep4*1000);
  e4s=gRandom->Gaus(Edep4*1000,sig4)/1000;
  sigTOT = 0.573*TMath::Sqrt(EdepTOT*1000);
  eTOTs=gRandom->Gaus(EdepTOT*1000,sigTOT)/1000;


  //e3s = 
  
  // fill histograms
  //analysisManager->FillH1(1, fEnergyAbs);
  //analysisManager->FillH1(2, fEnergyGap);
  
  analysisManager->FillNtupleDColumn(0, Edep1);
  analysisManager->FillNtupleDColumn(1, Edep2);
  analysisManager->FillNtupleDColumn(2, Edep3);
  analysisManager->FillNtupleDColumn(3, Edep4);
  analysisManager->FillNtupleDColumn(4, e1s);
  analysisManager->FillNtupleDColumn(5, e2s);
  analysisManager->FillNtupleDColumn(6, e3s);
  analysisManager->FillNtupleDColumn(7, e4s);
  analysisManager->FillNtupleDColumn(8, eTOTs);
  analysisManager->FillNtupleDColumn(9, nrgpri);
  analysisManager->FillNtupleDColumn(10, EdepTOT);
  analysisManager->FillNtupleDColumn(11, EdepVETO);
  analysisManager->FillNtupleDColumn(12, EdepMomentive);
  analysisManager->FillNtupleDColumn(13, EdepAlbox);
  analysisManager->FillNtupleDColumn(14, EdepEnclosure);
  analysisManager->FillNtupleDColumn(15, ParticleLabel);
  analysisManager->AddNtupleRow();  
  
  // Print per event (modulo n)
  //
  G4int eventID = evt->GetEventID();
  if ( eventID % 1000 < 1) {
    G4cout << "---> End of event: " << eventID << G4endl;     

    //G4cout
       //<< "   Absorber: total energy: " << std::setw(7)
                                       // << G4BestUnit(fEnergyAbs,"Energy")
//				       << G4BestUnit(EAbs,"Energy")
       //<< "       total track length: " << std::setw(7)
          //                             // << G4BestUnit(fTrackLAbs,"Length")
	//			       << G4BestUnit(LAbs,"Length")
 //      << G4endl
 //      << "        Gap: total energy: " << std::setw(7)
 //                                       << G4BestUnit(fEnergyGap,"Energy")
       G4cout << "       nrgpri              " << nrgpri<< G4endl;
  }
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
