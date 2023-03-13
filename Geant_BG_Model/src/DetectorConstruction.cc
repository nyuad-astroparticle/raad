/***********************************************************
LIGHT-1 Background Simulation > DETECTOR Construction
IMPLEMENTATION
------------------------------------------------------------

This is where we implement the construction of the geometry
of the detector onboard LIGHT-1

For any help please contact Panos: po524@nyu.edu
***********************************************************/

// Include the relevant headerfile
#include "DetectorConstruction.hh"

// These libraries can help us get materials
#include "G4Material.hh"
#include "G4NistManager.hh"

// The Geant4 libraries that contain the
// relevant volumes to use
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SubtractionSolid.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"


DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // Define materials
    DefineMaterials();

    // Define volumes
    return DefineVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{
    // Load material defined using NIST Manager
    G4double a;                               // Mass Number
    G4double z;                               // Atomic Number
    G4double density;                         // Density of material
    G4int ncomponents,number_of_atoms;        // Number of different elements, atoms

    // From NIST database get parameters of the following materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Element* Ce = new G4Element("Cerium",     "Ce",   z=58.,  a=140.116*g/mole);
    G4Element* Br = new G4Element("Bromine",    "Br",   z=35.,  a=79.904*g/mole);
    G4Element* N  = new G4Element("Nitrogen",   "N",    z=7.,   a=14.0067*g/mole);
    G4Element* Na = new G4Element("Sodium",     "Na",   z=11.,  a=22.990*g/mole);
    G4Element* Cl = new G4Element("Clorine",    "Cl",   z=17.,  a=35.453*g/mole);
    G4Element* Si = new G4Element("Silicon",    "Si",   z=14.,  a=28.09*g/mole);
    G4Element* O  = new G4Element("Oxygen",     "O",    z=8.,   a=16.00*g/mole);
    G4Element* H  = new G4Element("Hydrogen",   "H",    z=1.,   a=1.008*g/mole);
    G4Element* C  = new G4Element("Carbon",     "C",    z=6.,   a=12.01*g/mole);
    G4Element* F  = new G4Element("Fluorine",   "F",    z=9.,   a=18.998*g/mole);
    G4Element* I  = new G4Element("Iodine",     "I",    z=53.,  a=126.904*g/mole);
    G4Element* Cs = new G4Element("Cesium",     "Cs",   z=55.,  a=132.9*g/mole);
    G4Element* La = new G4Element("Lanthanum",  "La",   z=57.,  a=138.91*g/mole);
    G4Element* Bi = new G4Element("Bismuth",    "Bi",   z=83.,  a=208.98*g/mole);
    G4Element* Ge = new G4Element("Germanium",  "Ge",   z=32.,  a=72.63*g/mole);

    nistManager->FindOrBuildMaterial("G4_Al"); //Uncomment to use the Al package



    // Now define the equivalent Geant4 materials to be used for the detector
    // Vacuum
    new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,kStateGas, 2.73*kelvin, 3.e-18*pascal);
 
    // Cerium Bromide
    G4Material* CeBr3       = new G4Material("CeBr3", density=5.2*g/cm3,ncomponents=2);
  	CeBr3->AddElement(Ce, number_of_atoms=1);
  	CeBr3->AddElement(Br, number_of_atoms=3);

    // Lanthanium Bromide
    G4Material* LaBr3       = new G4Material("LaBr3", density=5.06*g/cm3,ncomponents=2);
    LaBr3->AddElement(La, number_of_atoms=1);
    LaBr3->AddElement(Br, number_of_atoms=3);

    // Lanthanium Bromochloride
    G4Material* LBC         = new G4Material("LBC", density=4.90*g/cm3,ncomponents=3);
    LBC->AddElement(La, number_of_atoms=1);
    LBC->AddElement(Br, number_of_atoms=2.85);
    LBC->AddElement(Cl, number_of_atoms=0.15);

    // Some other bismuth germanium stuff
    G4Material* BGO         = new G4Material("BGO", density=9.22*g/cm3,ncomponents=3);
    BGO->AddElement(Bi, number_of_atoms=4);
    BGO->AddElement(Ge, number_of_atoms=3);
    BGO->AddElement(O,  number_of_atoms=12);

    // Sodium Iodine
    G4Material* NaI         = new G4Material("NaI", density=3.67*g/cm3,ncomponents=2);
    NaI->AddElement(Na, number_of_atoms=1);
    NaI->AddElement(I,  number_of_atoms=1);

    // Cesium Iodine
    G4Material* CsI         = new G4Material("CsI", density=4.51*g/cm3,ncomponents=2);
    CsI->AddElement(Cs, number_of_atoms=1);
    CsI->AddElement(I,  number_of_atoms=1);

    // The optical layer thingy
    G4Material* optilayer   = new G4Material("optilayer", density=2.2*g/cm3,ncomponents=2);
    optilayer->AddElement(C, number_of_atoms=2);
    optilayer->AddElement(F, number_of_atoms=4);

    // The Quartz for the quartz window
    G4Material* quartz      = new G4Material("quartz",density= 2.32*g/cm3, ncomponents=2);
    quartz->AddElement(Si, number_of_atoms=1);
    quartz->AddElement(O , number_of_atoms=2);

    // Polystyrene
    G4Material* polystyrene = new G4Material("polystyrene",density= 1.05*g/cm3, ncomponents=2);
    polystyrene->AddElement(C, number_of_atoms=8);
    polystyrene->AddElement(H, number_of_atoms=8);

    // RTV615
    G4Material* RTV615      = new G4Material("RTV615", density=1.060*g/cm3,ncomponents=4);
    RTV615->AddElement(Si, number_of_atoms=1);
    RTV615->AddElement(C,  number_of_atoms=2);
    RTV615->AddElement(H,  number_of_atoms=6);
    RTV615->AddElement(O,  number_of_atoms=1);  

    // Epoxy that fills the rest of the volume
    G4Material* FGlassEpoxy = new G4Material("FGlassEpoxy", density=1.3*g/cm3,ncomponents=4);
    FGlassEpoxy->AddElement(Cl, number_of_atoms=1);
    FGlassEpoxy->AddElement(C,  number_of_atoms=21);
    FGlassEpoxy->AddElement(H,  number_of_atoms=25);
    FGlassEpoxy->AddElement(O,  number_of_atoms=5);

    // Print materials
    G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
    // Geometry parameters
    G4double worldSizeXY = 20.0*cm;
    G4double worldSizeZ  = worldSizeXY;
    G4double epsilon     = 0.01; //*mm;
    G4bool checkOverlaps = true;

    // Get the materials as defined in the previous method
    G4Material* defaultMaterial = G4Material::GetMaterial("Galactic");
    G4Material* CeBr3           = G4Material::GetMaterial("CeBr3");
    G4Material* NaI             = G4Material::GetMaterial("NaI");
    G4Material* CsI             = G4Material::GetMaterial("CsI");
    G4Material* LaBr3           = G4Material::GetMaterial("LaBr3");
    G4Material* LBC             = G4Material::GetMaterial("LBC");
    G4Material* BGO             = G4Material::GetMaterial("BGO");
    G4Material* G4_Al           = G4Material::GetMaterial("G4_Al");
    G4Material* quartz          = G4Material::GetMaterial("quartz");
    G4Material* optilayer       = G4Material::GetMaterial("optilayer");
    G4Material* polystyrene     = G4Material::GetMaterial("polystyrene");
    G4Material* FGlassEpoxy     = G4Material::GetMaterial("FGlassEpoxy");
    G4Material* RTV615          = G4Material::GetMaterial("RTV615");

    // If for some reason the materials are not properly defined throw an error
    if ( ! defaultMaterial  ) {
        G4ExceptionDescription msg;
        msg << "Cannot retrieve materials already defined.";
        G4Exception("B4DetectorConstruction::DefineVolumes()","MyCode0001", FatalException, msg);
    }

    //===================================== World =====================================
    G4VSolid* worldSolid
    = new G4Box("World", worldSizeXY/2, worldSizeXY/2, worldSizeZ/2); // its size

    G4LogicalVolume* worldLogicalVolume
    = new G4LogicalVolume(
                    worldSolid,         // its solid
                    defaultMaterial,    // its material
                    "World");           // its name

    G4VPhysicalVolume* worldPhysicalVolume
    = new G4PVPlacement(
                    0,                  // no rotation
                    G4ThreeVector(),    // at (0,0,0)
                    worldLogicalVolume, // its logical volume
                    "World",            // its name
                    0,                  // its mother  volume
                    false,              // no boolean operation
                    0,                  // copy number
                    checkOverlaps);     // checking overlaps

    //===================================== Crystals =====================================
    
    // The crystal Template
    G4VSolid* crystalSolid = new G4Box("crystal1",23./2*mm, 23./2*mm, 45./2*mm);
    G4LogicalVolume* crystalLogicalVolume = new G4LogicalVolume(
               crystalSolid,                            // The Solid
               CeBr3,                                   // Material
               "Crystal");                              // A name

    // The crystal positions
    G4ThreeVector crystalPositions[4];
    crystalPositions[0] = G4ThreeVector(-14.0*mm,  14.0*mm, 0.);
    crystalPositions[1] = G4ThreeVector( 14.0*mm,  14.0*mm, 0.);
    crystalPositions[2] = G4ThreeVector(-14.0*mm, -14.0*mm, 0.);
    crystalPositions[3] = G4ThreeVector( 14.0*mm, -14.0*mm, 0.);

    // Create the four crystals
    G4VPhysicalVolume* crystal1PhysicalVolume = new G4PVPlacement(
                0,                                      // No rotation
                crystalPositions[0],                    // Position
                crystalLogicalVolume,                   // The Logical Volume
                "Crystal1",                             // Name
                worldLogicalVolume,                     // The World Volume
                false,                                  // No boolean operation
                0,                                      // copy number
                checkOverlaps);                         // check overlaps

    G4VPhysicalVolume* crystal2PhysicalVolume = new G4PVPlacement(
                0,                                      // No rotation
                crystalPositions[1],                    // Position
                crystalLogicalVolume,                   // The Logical Volume
                "Crystal2",                             // Name
                worldLogicalVolume,                     // The World Volume
                false,                                  // No boolean operation
                0,                                      // copy number
                checkOverlaps);                         // check overlaps


    G4VPhysicalVolume* crystal3PhysicalVolume = new G4PVPlacement(
                0,                                      // No rotation
                crystalPositions[2],                    // Position
                crystalLogicalVolume,                   // The Logical Volume
                "Crystal3",                             // Name
                worldLogicalVolume,                     // The World Volume
                false,                                  // No boolean operation
                0,                                      // copy number
                checkOverlaps);                         // check overlaps

    G4VPhysicalVolume* crystal4PhysicalVolume = new G4PVPlacement(
                0,                                      // No rotation
                crystalPositions[3],                    // Position
                crystalLogicalVolume,                   // The Logical Volume
                "Crystal4",                             // Name
                worldLogicalVolume,                     // The World Volume
                false,                                  // No boolean operation
                0,                                      // copy number
                checkOverlaps);                         // check overlaps



    //===================================== Optical Separator =====================================
    G4VSolid* olbox  = new G4Box("olbox",(51.-epsilon)/2*mm,(51.-epsilon)/2*mm,(45.-epsilon)/2*mm);

    // Create a solid to subtract the crystals from
    G4SubtractionSolid *olbox1 = new G4SubtractionSolid("olbox1",olbox ,crystalSolid, 0, crystalPositions[0]);
    G4SubtractionSolid *olbox2 = new G4SubtractionSolid("olbox2",olbox1,crystalSolid, 0, crystalPositions[1]);
    G4SubtractionSolid *olbox3 = new G4SubtractionSolid("olbox3",olbox2,crystalSolid, 0, crystalPositions[2]);
    G4SubtractionSolid *olbox4 = new G4SubtractionSolid("olbox4",olbox3,crystalSolid, 0, crystalPositions[3]);
  

    G4LogicalVolume* olboxLogicalVolume = new G4LogicalVolume(
                olbox4,                                 // The solid
                optilayer,                              // Material
                "olbox");                               // Name

    G4VPhysicalVolume* olboxPhysicalVolume = new G4PVPlacement(
                0,                                      // No rotation
                G4ThreeVector(0.,0.,0.),                // Positioned at the center
                olboxLogicalVolume,                     // The Logical Volume
                "olbox",                                // Name
                worldLogicalVolume,                     // The World Volume
                false,                                  // No boolean operation
                0,                                      // copy number
                checkOverlaps);                         // Check overlaps


    //===================================== Aluminum Box =====================================
    
    //Create an aluminum shell for the detector
    G4VSolid* oalbox  = new G4Box("oalbox",60./2*mm, 60./2*mm, 45.8/2*mm);
    G4VSolid* ialbox  = new G4Box("ialbox",(51.+epsilon)/2*mm,(51.+epsilon)/2*mm,(45.8+epsilon)/2*mm);
    G4SubtractionSolid *aluminiumBox = new G4SubtractionSolid("oalboxh",oalbox,ialbox, 0, G4ThreeVector( 0.*mm, 0.*mm, 0.8*mm));

    // Its logical volume
    G4LogicalVolume* aluminiumBoxLogicalVolume = new G4LogicalVolume(
                aluminiumBox,                           // The Box
                G4_Al,                                  // Material
                "oalboxhLV");                           // Name
  
    G4VPhysicalVolume* aluminiumBoxPhysicalVolume = new G4PVPlacement(
                0,                                      // No Rotation
                G4ThreeVector(0.,0.,-0.4*mm),           // Position
                aluminiumBoxLogicalVolume,              // Logical Volume 
                "aluminiumBoxPhysicalVolume",           // Name           
                worldLogicalVolume,                     // Logical Volume
                false,                                  // No boolean opeartion
                0,                                      // Copy Number
                checkOverlaps);                         // Check overlaps


    //===================================== Scintillator Veto =====================================
    G4VSolid* ovetobox  = new G4Box("ovetobox",68./2*mm, 68./2*mm, 45.8/2*mm);
    G4VSolid* ivetobox  = new G4Box("ivetobox",(60.+epsilon)/2*mm,(60.+epsilon)/2*mm,(45.8+epsilon)/2*mm);
    G4SubtractionSolid *veto = new G4SubtractionSolid("vetoBox",ovetobox,ivetobox, 0, G4ThreeVector( 0.*mm, 0.*mm, 0*mm));

    G4LogicalVolume* vetoLogicalVolume = new G4LogicalVolume(
                veto,                                   // The Solid
                polystyrene,                            // Material
                "vetoLogicalVolume");                   // Name
  
    G4VPhysicalVolume* vetoPhysicalVolume = new G4PVPlacement(
                0,                                      // Rotation
                G4ThreeVector(0.,0.,-0.4*mm),           // Position
                vetoLogicalVolume,                      // Logical Volume   
                "vetoPhysicalVolume",                   // Name
                worldLogicalVolume,                     // The world volume
                false,                                  // No boolean action0
                0,                                      // Copy Number
                checkOverlaps);                         // Check for overlaps


    //===================================== Momentive Layer =====================================
    G4VSolid* oMomentivebox  = new G4Box("oMomentivebox",70./2*mm, 70./2*mm, 46.4/2*mm);
    G4VSolid* iMomentivebox  = new G4Box("iMomentivebox",(68.+epsilon)/2*mm,(68.+epsilon)/2*mm,(46.4+epsilon)/2*mm);
    G4SubtractionSolid *momentive = new G4SubtractionSolid("momentiveBox",oMomentivebox,iMomentivebox, 0, G4ThreeVector( 0.*mm, 0.*mm, 0*mm));
    

        G4LogicalVolume* momentiveLogicalVolume = new G4LogicalVolume(
                momentive,                              // Solid Volume
                RTV615,                                 // Material
                "momentiveLogicalVolume");              // Name

        G4VPhysicalVolume* oMomentiveboxPV = new G4PVPlacement(
                0,                                      // Rotation
                G4ThreeVector(0.,0.,-1.4*mm),           // Position
                momentiveLogicalVolume,                 // Logical Volume
                "momentivePhysicalVolume",              // Name
                worldLogicalVolume,                     // World Volume
                false,                                  // No boolean action
                0,                                      // Copy Number
                checkOverlaps);                         // Check for overlaps 

    //===================================== Fibreglass Enclosure =====================================
    G4VSolid* ofiberglass  = new G4Box("ofiberglass",71.2/2*mm, 71.2/2*mm, 47.6/2*mm);
    G4VSolid* ifiberglass  = new G4Box("ifiberglass",(70.+epsilon)/2*mm,(70.+epsilon)/2*mm,(47.6+epsilon)/2*mm);
    G4SubtractionSolid *fiberglass = new G4SubtractionSolid("ofiberglassh",ofiberglass,ifiberglass, 0, G4ThreeVector( 0.*mm, 0.*mm, 0*mm));

    G4LogicalVolume* fiberglassLogicalVolume = new G4LogicalVolume(
                fiberglass,                             // Solid Volume
                G4_Al,                                  // Material
                "fiberglassLogicalVolume");             // Name
    
    G4VPhysicalVolume* fiberglassPhysicalVolume = new G4PVPlacement(
                0,                                      // Rotation
                G4ThreeVector(0.,0.,-2.0*mm),           // Position
                fiberglassLogicalVolume,                // Logical Volume
                "fiberglassPhysicalVolume",             // Name
                worldLogicalVolume,                     // World Volume
                false,                                  // Boolean Crap
                0,                                      // Copy Number  
                checkOverlaps);                         // Check for Overlaps
        
    //==============================================================================================


    //===================================== Visualization attributes =====================================

    G4VisAttributes* blue       = new G4VisAttributes(G4Colour(0.0,0.0,1.0));
    blue->SetVisibility(true);
    G4VisAttributes* red        = new G4VisAttributes(G4Colour(1.0,0.0,0.0));
    red->SetVisibility(true);
    G4VisAttributes* green      = new G4VisAttributes(G4Colour(0.,1.0,0.));
    green->SetVisibility(true);
    G4VisAttributes* white      = new G4VisAttributes(G4Colour(1.,1.0,1.0));
    white->SetVisibility(true);
    G4VisAttributes* yellow     = new G4VisAttributes(G4Colour(0.0,1.0,1.0));
    yellow->SetVisibility(true);
    G4VisAttributes* nyu        = new G4VisAttributes(G4Colour(0.9,0.2,1.0));
    nyu->SetVisibility(true);
    G4VisAttributes* invisible  = new G4VisAttributes(G4Colour(1.0,1.0,1.0));
    invisible->SetVisibility(false);


    worldLogicalVolume          -> SetVisAttributes(invisible);
    crystalLogicalVolume        -> SetVisAttributes(blue);
    olboxLogicalVolume          -> SetVisAttributes(red);
    aluminiumBoxLogicalVolume   -> SetVisAttributes(green);
    vetoLogicalVolume           -> SetVisAttributes(white);
    momentiveLogicalVolume      -> SetVisAttributes(yellow);
    fiberglassLogicalVolume     -> SetVisAttributes(nyu);

    // Return the physical world volume
    return worldPhysicalVolume;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......