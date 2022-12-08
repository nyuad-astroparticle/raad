
#include "B4aDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
//#include "WLSMaterials.hh"
//#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
//#include "G4GlobalMagFieldMessenger.hh" --gianmarco
//#include "G4AutoDelete.hh" --gianmarco

#include "G4SDManager.hh"
#include "G4SDChargedFilter.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSTrackLength.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4SubtractionSolid.hh" // --gianmarco

//G4ThreadLocal --gianmarco
//G4GlobalMagFieldMessenger* B4aDetectorConstruction::fMagFieldMessenger = 0; --gianmarco


B4aDetectorConstruction::B4aDetectorConstruction()
 : G4VUserDetectorConstruction(),
   fCheckOverlaps(true)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aDetectorConstruction::~B4aDetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B4aDetectorConstruction::Construct()
{
  // Define materials
  DefineMaterials();

  // Define volumes
  return DefineVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aDetectorConstruction::DefineMaterials()
{
  // Lead material defined using NIST Manager
  G4double a;
  G4double z;
  G4double density;
  G4int ncomponents,number_of_atoms;
  /// G4double fractionmass;
  //std::vector<G4int> natoms;
  //std::vector<G4double> fractionMass;
  //std::vector<G4String> elements;
  //G4int ncomponents, number_of_atoms;

  G4NistManager* nistManager = G4NistManager::Instance();
  G4Element* Ce = new G4Element("Ce", "Ce", z=58., a=140.116*g/mole);
  G4Element* Br = new G4Element("Br", "Br", z=35., a=79.904*g/mole);
 // G4Element* Ga = new G4Element("Ga", "Ga", z=31., a=69.723*g/mole);
  G4Element* N = new G4Element("Nitrogen", "N", z=7., a=14.0067*g/mole);
  G4Element* Na = new G4Element("Sodium", "Na", z=11., a=22.990*g/mole);
  G4Element* Cl = new G4Element("Clorine", "Cl", z=17., a=35.453*g/mole);
  G4Element* Si = new G4Element("Silicon", "Si", z=14., a=28.09*g/mole);
  G4Element* O = new G4Element("Oxygen"  , "O", z=8 , a=16.00*g/mole);
  G4Element* H = new G4Element("Hydrogen"  , "H", z=1 , a=1.008*g/mole);
  G4Element* C = new G4Element("Carbon"  , "C", z=6 , a=12.01*g/mole);
  G4Element* F = new G4Element("Fluorine"  , "F", z=9 , a=18.998*g/mole);
  G4Element* I = new G4Element("Iodine"  , "I", z=53 , a=126.904*g/mole);
  G4Element* Cs = new G4Element("Cesium"  , "Cs", z=55 , a=132.9*g/mole);
  G4Element* La = new G4Element("Lanthanum"  , "La", z=57 , a=138.91*g/mole);
 G4Element* Bi = new G4Element("Bismuth"  , "Bi", z=83 , a=208.98*g/mole);
 G4Element* Ge = new G4Element("Germanium"  , "Ge", z=32 , a=72.63*g/mole);

  nistManager->FindOrBuildMaterial("G4_Al"); //Uncomment to use the Al package



  // Vacuum
  new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                  kStateGas, 2.73*kelvin, 3.e-18*pascal);

  G4Material* CeBr3 = new G4Material("CeBr3", density=5.2*g/cm3,ncomponents=2);
  	CeBr3->AddElement(Ce, number_of_atoms=1);
  	CeBr3->AddElement(Br, number_of_atoms=3);

 G4Material* LaBr3 = new G4Material("LaBr3", density=5.06*g/cm3,ncomponents=2);
  	LaBr3->AddElement(La, number_of_atoms=1);
  	LaBr3->AddElement(Br, number_of_atoms=3);

 G4Material* LBC = new G4Material("LBC", density=4.90*g/cm3,ncomponents=3);
  	LBC->AddElement(La, number_of_atoms=1);
  	LBC->AddElement(Br, number_of_atoms=2.85);
        LBC->AddElement(Cl, number_of_atoms=0.15);

 G4Material* BGO = new G4Material("BGO", density=9.22*g/cm3,ncomponents=3);
  	BGO->AddElement(Bi, number_of_atoms=4);
  	BGO->AddElement(Ge, number_of_atoms=3);
        BGO->AddElement(O, number_of_atoms=12);


  G4Material* NaI = new G4Material("NaI", density=3.67*g/cm3,ncomponents=2);
  	NaI->AddElement(Na, number_of_atoms=1);
  	NaI->AddElement(I, number_of_atoms=1);

 G4Material* CsI = new G4Material("CsI", density=4.51*g/cm3,ncomponents=2);
  	CsI->AddElement(Cs, number_of_atoms=1);
  	CsI->AddElement(I, number_of_atoms=1);

  G4Material* optilayer = new G4Material("optilayer", density=2.2*g/cm3,ncomponents=2);
  	optilayer->AddElement(C, number_of_atoms=2);
  	optilayer->AddElement(F, number_of_atoms=4);

  G4Material* quartz = new G4Material("quartz",density= 2.32*g/cm3, ncomponents=2);
	quartz->AddElement(Si, number_of_atoms=1);
	quartz->AddElement(O , number_of_atoms=2);

  G4Material* polystyrene = new G4Material("polystyrene",density= 1.05*g/cm3, ncomponents=2);
       polystyrene->AddElement(C, number_of_atoms=8);
       polystyrene->AddElement(H, number_of_atoms=8);

  G4Material* RTV615 = new G4Material("RTV615", density=1.060*g/cm3,ncomponents=4);
  	RTV615->AddElement(Si, number_of_atoms=1);
  	RTV615->AddElement(C, number_of_atoms=2);
  	RTV615->AddElement(H, number_of_atoms=6);
  	RTV615->AddElement(O, number_of_atoms=1);  


  G4Material* FGlassEpoxy = new G4Material("FGlassEpoxy", density=1.3*g/cm3,ncomponents=4);
  	FGlassEpoxy->AddElement(Cl, number_of_atoms=1);
  	FGlassEpoxy->AddElement(C, number_of_atoms=21);
  	FGlassEpoxy->AddElement(H, number_of_atoms=25);
  	FGlassEpoxy->AddElement(O, number_of_atoms=5);

  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B4aDetectorConstruction::DefineVolumes()
{
  // Geometry parameters

  G4double worldSizeXY = 20.0*cm;
  G4double worldSizeZ  = worldSizeXY;
  G4double epsilon = 0.01; //*mm;
  // Get materials
  G4Material* defaultMaterial = G4Material::GetMaterial("Galactic");
  G4Material* CeBr3 = G4Material::GetMaterial("CeBr3");
  G4Material* NaI = G4Material::GetMaterial("NaI"); //ADRIANO 
  G4Material* CsI = G4Material::GetMaterial("CsI"); //ADRIANO  
  G4Material* LaBr3 = G4Material::GetMaterial("LaBr3"); //ADRIANO
  G4Material* LBC = G4Material::GetMaterial("LBC"); //ADRIANO 
  G4Material* BGO = G4Material::GetMaterial("BGO"); //ADRIANO  
  G4Material* G4_Al = G4Material::GetMaterial("G4_Al");
  G4Material* quartz = G4Material::GetMaterial("quartz");
  G4Material* optilayer = G4Material::GetMaterial("optilayer");
  G4Material* polystyrene = G4Material::GetMaterial("polystyrene");
  G4Material* FGlassEpoxy = G4Material::GetMaterial("FGlassEpoxy");

  G4Material* RTV615 = G4Material::GetMaterial("RTV615");

  if ( ! defaultMaterial  ) {
    G4ExceptionDescription msg;
    msg << "Cannot retrieve materials already defined.";
    G4Exception("B4DetectorConstruction::DefineVolumes()",
      "MyCode0001", FatalException, msg);
  }

  //
  // World
//========================================== World =========================
  G4VSolid* worldS
    = new G4Box("World",     
                 worldSizeXY/2, worldSizeXY/2, worldSizeZ/2); // its size

  G4LogicalVolume* worldLV
    = new G4LogicalVolume(
                 worldS,           // its solid
                 defaultMaterial,  // its material
                 "World");         // its name

  G4VPhysicalVolume* worldPV
    = new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(),  // at (0,0,0)
                 worldLV,          // its logical volume
                 "World",          // its name
                 0,                // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps

//================================= Crystals ==========================
G4VSolid* crystal1S
  = new G4Box("crystal1",
	      23./2*mm, 23./2*mm, 45./2*mm); //gianmarco verified

G4LogicalVolume* crystal1LV
  = new G4LogicalVolume(
               crystal1S,
               //CeBr3, //Adriano 
		//NaI,
		//CsI,
		//LaBr3,
		//LBC,
                BGO,
		//G4_Al,
               "Crystal1");

G4VPhysicalVolume* crystal1PV
  = new G4PVPlacement(
                0,          
                G4ThreeVector(-14.0*mm, 14.0*mm, 0.), // 11.5 + 2.5
                crystal1LV,     
                "Crystal1",     
                worldLV,        
                false,          
                0,              
                fCheckOverlaps);

 
G4VPhysicalVolume* crystal2PV
    = new G4PVPlacement(
        0,            
        G4ThreeVector(14.*mm, 14.*mm, 0.),
        crystal1LV,     
        "Crystal2",     
        worldLV,        
      false,           
        0,             
      fCheckOverlaps);

G4VPhysicalVolume* crystal3PV
    = new G4PVPlacement(
      0,             
    G4ThreeVector(-14.*mm, -14.*mm, 0.),
    crystal1LV,      
    "Crystal3",      
    worldLV,         
    false,           
    0,               
    fCheckOverlaps);

  G4VPhysicalVolume* crystal4PV
    = new G4PVPlacement(
      0,             
  G4ThreeVector(14.*mm, -14.*mm, 0.),
    crystal1LV,    
    "Crystal4",    
    worldLV,       
    false,         
    0,             
    fCheckOverlaps);



//=========================== Optical Separator ====================--gianmarco

  G4VSolid* olbox  = new G4Box("olbox",(51.-epsilon)/2*mm,(51.-epsilon)/2*mm,(45.-epsilon)/2*mm);

  G4SubtractionSolid *olbox1 = new G4SubtractionSolid("olbox1",olbox ,crystal1S, 0, G4ThreeVector(-14.0*mm, 14.0*mm, 0.));
  G4SubtractionSolid *olbox2 = new G4SubtractionSolid("olbox2",olbox1,crystal1S, 0, G4ThreeVector( 14.0*mm, 14.0*mm, 0.));
  G4SubtractionSolid *olbox3 = new G4SubtractionSolid("olbox3",olbox2,crystal1S, 0, G4ThreeVector(-14.0*mm,-14.0*mm, 0.));
  G4SubtractionSolid *olbox4 = new G4SubtractionSolid("olbox4",olbox3,crystal1S, 0, G4ThreeVector( 14.0*mm,-14.0*mm, 0.));
  

  G4LogicalVolume* olbox4LV = new G4LogicalVolume(
               olbox4,       
               optilayer, 
               //defaultMaterial, //Adriano
               "Layer1");  

  G4VPhysicalVolume* layer1PV = new G4PVPlacement(
                0,            
                G4ThreeVector(0.,0.,0.),
                olbox4LV,  
                "Layer1",   
                worldLV,    
                false,      
                0,          
                fCheckOverlaps);


//================================= Aluminum Box ==========================

  G4VSolid* oalbox  = new G4Box("oalbox",60./2*mm, 60./2*mm, 45.8/2*mm); //45.8 = 45+0.8
  G4VSolid* ialbox  = new G4Box("ialbox",(51.+epsilon)/2*mm,(51.+epsilon)/2*mm,(45.8+epsilon)/2*mm);
  G4SubtractionSolid *oalboxh = new G4SubtractionSolid("oalboxh",oalbox,ialbox, 0, G4ThreeVector( 0.*mm, 0.*mm, 0.8*mm));

  G4LogicalVolume* oalboxhLV = new G4LogicalVolume(
               oalboxh,       
               G4_Al, //Uncomment to use Al packaging
	       //defaultMaterial, // comment to use Al packaging 
               "oalboxhLV");
  
  G4VPhysicalVolume* oalboxhPV = new G4PVPlacement(
                0,
                G4ThreeVector(0.,0.,-0.4*mm),
                oalboxhLV,
                "oalboxhPV",
                worldLV,
                false,
                0,
                fCheckOverlaps);

 //============
 //
 //===================== Scintillator Veto =====================
   G4VSolid* ovetobox  = new G4Box("ovetobox",68./2*mm, 68./2*mm, 45.8/2*mm);
   G4VSolid* ivetobox  = new G4Box("ivetobox",(60.+epsilon)/2*mm,(60.+epsilon)/2*mm,(45.8+epsilon)/2*mm);
   G4SubtractionSolid *ovetoboxh = new G4SubtractionSolid("ovetoboxh",ovetobox,ivetobox, 0, G4ThreeVector( 0.*mm, 0.*mm, 0*mm));

     G4LogicalVolume* ovetoboxhLV = new G4LogicalVolume(
               ovetoboxh,
               polystyrene,
               "ovetoboxhLV");
  
  G4VPhysicalVolume* ovetoboxhPV = new G4PVPlacement(
                0,
                G4ThreeVector(0.,0.,-0.4*mm),
                ovetoboxhLV,
                "ovetoboxhPV",
                worldLV,
                false,
                0,
                fCheckOverlaps);
//========================================================================= 
  

//================================= Momentive Layer =====================
   G4VSolid* oMomentivebox  = new G4Box("oMomentivebox",70./2*mm, 70./2*mm, 46.4/2*mm);
   G4VSolid* iMomentivebox  = new G4Box("iMomentivebox",(68.+epsilon)/2*mm,(68.+epsilon)/2*mm,(46.4+epsilon)/2*mm);
   G4SubtractionSolid *oMomentiveboxh = new G4SubtractionSolid("Momentivebox",oMomentivebox,iMomentivebox, 0, G4ThreeVector( 0.*mm, 0.*mm, 0*mm));
   

     G4LogicalVolume* oMomentiveboxLV = new G4LogicalVolume(
               oMomentiveboxh,
               RTV615,
               "oMomentiveboxLV");

     G4VPhysicalVolume* oMomentiveboxPV = new G4PVPlacement(
                0,
                G4ThreeVector(0.,0.,-1.4*mm),
                oMomentiveboxLV,
                "oMomentiveboxPV",
                worldLV,
                false,
                0,
                fCheckOverlaps);
 //========================================================================= 

//===================== Fibreglass Enclosure =====================
   G4VSolid* ofiberglass  = new G4Box("ofiberglass",71.2/2*mm, 71.2/2*mm, 47.6/2*mm);
   G4VSolid* ifiberglass  = new G4Box("ifiberglass",(70.+epsilon)/2*mm,(70.+epsilon)/2*mm,(47.6+epsilon)/2*mm);
   G4SubtractionSolid *ofiberglassh = new G4SubtractionSolid("ofiberglassh",ofiberglass,ifiberglass, 0, G4ThreeVector( 0.*mm, 0.*mm, 0*mm));



   G4LogicalVolume* ofiberglasshLV = new G4LogicalVolume(
               ofiberglassh,
               //FGlassEpoxy,
	       G4_Al,
               "ofiberglasshLV");
  
   G4VPhysicalVolume* ofiberglasshPV = new G4PVPlacement(
                0,
                G4ThreeVector(0.,0.,-2.0*mm),
                ofiberglasshLV,
                "ofiberglasshPV",
                worldLV,
                false,
                0,
                fCheckOverlaps);
 //========================================================================= 


  //
  // Visualization attributes
  //

   G4VisAttributes* visible= new G4VisAttributes(G4Colour(0.0,0.0,1.0));
   visible->SetVisibility(true);
   G4VisAttributes* visible2= new G4VisAttributes(G4Colour(1.0,0.0,0.0));
   visible2->SetVisibility(true);
   G4VisAttributes* visible3= new G4VisAttributes(G4Colour(0.,1.0,0.));
   visible3->SetVisibility(true);
   G4VisAttributes* visible4= new G4VisAttributes(G4Colour(1.,1.0,1.0));
   visible4->SetVisibility(true);
   G4VisAttributes* invisible= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
   invisible->SetVisibility(false);
   G4VisAttributes* visible5= new G4VisAttributes(G4Colour(0.0,0.0,1.0));
   visible5->SetVisibility(true);
   G4VisAttributes* visible6= new G4VisAttributes(G4Colour(0.9,0.2,1.0));
   visible6->SetVisibility(true);


   worldLV->SetVisAttributes(invisible);
   crystal1LV->SetVisAttributes(visible);  
   olbox4LV->SetVisAttributes(visible2);     //optical-soft plastic layer
   oalboxhLV->SetVisAttributes(visible3);
   ovetoboxhLV->SetVisAttributes(visible4);
   oMomentiveboxLV->SetVisAttributes(visible5);
   ofiberglasshLV->SetVisAttributes(visible6);


  //
  // Always return the physical World
  //
  return worldPV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aDetectorConstruction::ConstructSDandField()
{
  G4SDManager::GetSDMpointer()->SetVerboseLevel(1);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
