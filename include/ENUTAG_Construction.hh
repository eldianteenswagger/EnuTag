#ifndef ENUTAG_CONSTRUCTION_HH
#define ENUTAG_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"

#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4SDManager.hh"

#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4Field.hh"
#include "G4FieldManager.hh"

#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4QuadrupoleMagField.hh"
#include "G4UniformMagField.hh"
#include "G4SubtractionSolid.hh"
#include "G4EllipticalTube.hh"

#include "ENUTAG_SensitiveDetector.hh"

#include<string>

class ENUTAG_Construction : public G4VUserDetectorConstruction
{
public:
    ENUTAG_Construction();
    virtual ~ENUTAG_Construction();
    virtual G4VPhysicalVolume *Construct();

private:

    G4LogicalVolume *logicDetector1;
    G4LogicalVolume *logicDetector2;
    G4LogicalVolume *logicDetector3;
    G4LogicalVolume *logicDetector4;
    G4LogicalVolume *logicDetector5;
    G4LogicalVolume *logicDSVD1;
    G4LogicalVolume *logicDSVD2;
    G4LogicalVolume *logicUSVD;

    G4Material *Material(std::string materialName);

    virtual void ConstructSDandField();

    void DefineRotations();
    void DefineMaterials();

    void DoDipole(G4int dipoleNumber, G4LogicalVolume* lWorld);
    void DoQuadrupole(G4int quadrupoleNumber, G4LogicalVolume* lWorld);
    void DoEC(G4int ECNumber, G4LogicalVolume* lWorld);
    void DoDrifts(G4LogicalVolume* lWorld);
    void DoTarget(G4LogicalVolume* lWorld);
    void DoDetectors(G4LogicalVolume* lWorld);
    void DoConcrete(G4LogicalVolume* lWorld);
    void DoSoil(G4LogicalVolume* lWorld);

};

#endif