#include "ENUTAG_Construction.hh"
#include<map>
#include<cmath>

ENUTAG_Construction::ENUTAG_Construction(){

}

ENUTAG_Construction::~ENUTAG_Construction(){
    
}

G4Material* ENUTAG_Construction::Material(std::string materialName){
    G4NistManager *nist = G4NistManager::Instance();
    std::map <std::string, G4Material* > materials {
        //predefined
        {"air",nist->FindOrBuildMaterial("G4_AIR")},
        {"graphite",nist->FindOrBuildMaterial("G4_GRAPHITE")},
        {"iron",nist->FindOrBuildMaterial("G4_Fe")},
        {"concrete",nist->FindOrBuildMaterial("G4_CONCRETE")},
        {"copper",nist->FindOrBuildMaterial("G4_Cu")},
        {"tungsten",nist->FindOrBuildMaterial("G4_W")},
        {"silicon",nist->FindOrBuildMaterial("G4_Si")},
        //defined
        {"vacuum", new G4Material("Galactic", 1., 1.01*g/mole,1.e-25*g/cm3,kStateGas, 2.73*kelvin, 3.e-18*pascal)},
        {"ENUTAG_graphite", new G4Material("myGraphite",6.,12.01*g/mole,1.85*g/cm3)}
        //{"steel",},
        //{"borated_concrete", new G4Material("boratedConcrete", density=1.97*g/cm3, ncomponents=15)}
    };
    return materials[materialName];
}

G4VPhysicalVolume *ENUTAG_Construction::Construct(){
    
    G4bool checkOverlaps = true;
    
    //PARAMETERS (to put in different function maybe)

    G4double PRHO = 8.5 * GeV / 0.299792458;
    G4double MID_ANGLE = 0.;

    G4double thicknessTarget = 1.3 * m / 2;
    G4double sideTarget = 0.1 * m / 2;
    G4double targetDiameter = 6 * mm / 2;
    G4double targetBlockLength = 1.3 * m / 2;
    G4double targetBlockSize = 0.1 * m / 2;

    G4double driftRadius = 0.1 * m / 2;
    G4double driftThick = 0.01 * m / 2;
    G4double drift1Length = 0.7 * m / 2;
    G4double drift2Length = 1.006962 * m / 2;
    G4double drift3Length = 0.826408 * m / 2;
    G4double drift4Length = 0.661739 * m / 2;
    G4double drift5Length = 0.855000 * m / 2;
    G4double drift6Length = 0.143000 * m / 2;
    G4double drift7Length = 0.400662 * m / 2;
    G4double drift8Length = 0.425953 * m / 2;
    G4double drift9Length = 0.516867 * m / 2;

    G4double driftBUFFLength = 0.25 * m / 2;
    G4double driftBUFFRadius = 0.12 * m / 2;

    G4double driftDecayLength = 25.0 * m / 2;
    G4double driftDecayRadius = 1.0 * m / 2;

    G4double quadrupoleThickness = 0.22 * m / 2;
    G4double quadrupole1Length = 1.027721 * m / 2;
    G4double quadrupole1Radius = 0.05173 * m / 2;
    G4double quadrupole2Length = 2.063079 * m / 2;  
    G4double quadrupole2Radius = 0.10499 * m / 2;
    G4double quadrupole3Length = 1.976843 * m / 2;  
    G4double quadrupole3Radius = 0.0953 * m / 2;
    G4double quadrupole5Length = 1.2 * m / 2;  
    G4double quadrupole5Radius = 0.05 * m / 2; //NOT SURE ABOUT THIS
    G4double quadrupole6Length = 1.080413 * m / 2;  
    G4double quadrupole6Radius = 0.0912 * m / 2;
    G4double quadrupole8Length = 1.240500 * m / 2;  
    G4double quadrupole8Radius = 0.10049 * m / 2;
    G4double quadrupole9Length = 0.800253 * m / 2;  
    G4double quadrupole9Radius = 0.10476 * m / 2;

    G4double dipoleThickness = 0.1 * m / 2;
    G4double dipoleWidth = 1. * m / 2;

    G4double driftDipole1Radius = 0.012 * m / 2;
    G4double driftDipole1Length = 0.6 * m / 2;
    G4double driftDipole2Radius = 0.012 * m / 2;
    G4double driftDipole2Length = 0.61 * m / 2;

    G4double dipole1Radius = 15.76 * m; //NOT SURE ABOUT THIS EITHER
    G4double dipole1InnerRadius = dipole1Radius - (0.2*m);
    G4double dipole1OuterRadius = dipole1Radius + (0.2*m);
    G4double dipole1Deg = 9.09/2 * deg;
    G4double dipole1Height = quadrupoleThickness;

    G4double dipole2Radius = 15.76 * m;
    G4double dipole2InnerRadius = dipole2Radius - (0.2*m);
    G4double dipole2OuterRadius = dipole2Radius + (0.2*m);
    G4double dipole2Deg = 9.09/2 * deg;
    G4double dipole2Height = quadrupoleThickness;

    G4double dipole3Radius = 15.76 * m;
    G4double dipole3InnerRadius = dipole3Radius - (0.2*m);
    G4double dipole3OuterRadius = dipole3Radius + (0.2*m);
    G4double dipole3Deg = 9.09/2 * deg;
    G4double dipole3Height = quadrupoleThickness;

    G4double dipole4Radius = 15.76 * m;
    G4double dipole4InnerRadius = dipole4Radius - (0.2*m);
    G4double dipole4OuterRadius = dipole4Radius + (0.2*m);
    G4double dipole4Deg = 9.09/2 * deg;
    G4double dipole4Height = quadrupoleThickness;

    G4double EC1Thickness = 0.45 * m / 2;
    G4double EC1Side = (quadrupole5Radius + quadrupoleThickness);
    G4double EC1holeX = 90 * mm / 2;
    G4double EC1holeY = 100 * mm / 2;
    G4double EC2Thickness = 0.25 * m / 2;
    G4double EC2Side = (quadrupole5Radius + quadrupoleThickness);
    G4double EC2holeX = 100 * mm / 2;
    G4double EC2holeY = 100 * mm / 2;
    G4double EC3Thickness = 0.25 * m / 2;
    G4double EC3Side = (quadrupole6Radius + quadrupoleThickness);
    G4double EC3holeX = 100 * mm / 2;
    G4double EC3holeY = 100 * mm / 2;
    G4double ECLASTThickness = 2.2 * m / 2;
    G4double ECLASTSide = (quadrupole9Radius + quadrupoleThickness);
    G4double ECLASTholeX = 130 * mm / 2;
    G4double ECLASTholeY = 110 * mm / 2;

    //Silicon stuff
    G4double SiThickness = 0.5 * mm;
    G4double Si1pos = 0.36 * m;
    G4double Si4pos = 0.25 * m;
    G4double SiRadius = driftRadius;

    G4double worldMargin = 0.1 * m;

    //POSITIONS
    //angle stuff
    double theta1 = (9.09/2) * M_PI / 180.;
    double theta2 = 2. * theta1;
    double theta3 = 3. * theta1;
    double theta4 = 4. * theta1;
    G4double dx1 = std::cos(theta1);
    G4double dz1 = std::sin(theta1);
    G4double dx2 = std::cos(theta2);
    G4double dz2 = std::sin(theta2);
    G4double dx3 = std::cos(theta3);
    G4double dz3 = std::sin(theta3);
    G4double dx4 = std::cos(theta4);
    G4double dz4 = std::sin(theta4);

    //x
    //dipoleNX = startX + (piecebeforeLength * dxN) - (dipoleNRadius * dz(N_1))
    G4double targetX = 0.;
    G4double drift1X = targetX + targetBlockLength + drift1Length;
    G4double quad1X = drift1X + drift1Length + quadrupole1Length;
    G4double drift2X = quad1X + quadrupole1Length + drift2Length;
    G4double quad2X = drift2X + drift2Length + quadrupole2Length;
    G4double drift3X = quad2X + quadrupole2Length + drift3Length;
    G4double quad3X = drift3X + drift3Length + quadrupole3Length;
    G4double drift4X = quad3X + quadrupole3Length + drift4Length;
    G4double dipole1X = drift4X + drift4Length;
    G4double driftDipole1X = dipole1X + (dipole1Radius * dz1) + (driftDipole1Length * dx1);
    G4double dipole2X = driftDipole1X + driftDipole1Length - (dipole2Radius * dz1);
    G4double drift5X = dipole2X + (dipole2Radius * dz2) + (drift5Length * dx2);
    G4double quad5X = drift5X + (drift5Length * dx2) + (quadrupole5Length * dx2);
    G4double coll1X = quad5X  + (quadrupole5Length * dx2) + (EC1Thickness * dx2);
    G4double drift6X = coll1X + (EC1Thickness * dx2) + (drift6Length * dx2);
    G4double coll2X = drift6X  + (drift6Length * dx2) + (EC2Thickness * dx2);
    G4double dipole3X = coll2X + (EC2Thickness * dx2) - (dipole3Radius * dz2);
    G4double driftDipole2X = dipole3X + (dipole3Radius * dz3) + (driftDipole2Length * dx3);
    G4double dipole4X = driftDipole2X + (driftDipole2Length * dx3) - (dipole4Radius * dz3);
    G4double drift7X = dipole4X + (dipole4Radius * dz4) + (drift7Length * dx4);
    G4double coll3X = drift7X  + (drift7Length * dx4) + (EC3Thickness * dx4);
    G4double quad6X = coll3X + (EC3Thickness * dx4) + (quadrupole6Length * dx4);
    G4double drift8X = quad6X + (quadrupole6Length * dx4) + (drift8Length * dx4);
    G4double coll4X = drift8X  + (drift8Length * dx4) + (EC3Thickness * dx4);
    G4double quad8X = coll4X + (EC3Thickness * dx4) + (quadrupole8Length * dx4);
    G4double drift9X = quad8X + (quadrupole8Length * dx4) + (drift9Length * dx4);
    G4double coll5X = drift9X  + (drift9Length * dx4) + (EC3Thickness * dx4);
    G4double quad9X = coll5X + (EC3Thickness * dx4) + (quadrupole9Length * dx4);
    G4double driftBUFFX = quad9X + (quadrupole9Length * dx4) + (driftBUFFLength * dx4);
    G4double collLASTX = driftBUFFX  + (driftBUFFLength * dx4) + (ECLASTThickness * dx4);
    G4double driftDecayX = collLASTX + (ECLASTThickness * dx4) + (driftDecayLength * dx4);

    G4double silicon1X = driftDipole2X + (Si1pos * dx3) - (driftDipole2Length * dx3);
    G4double silicon2X = driftDipole2X + ((driftDipole2Length - SiThickness)* dx3);
    G4double silicon3X = drift7X - ((drift7Length - SiThickness) * dx4);
    G4double silicon4X = silicon3X + (Si4pos * dx4);
    G4double silicon5X = driftBUFFX - ((driftBUFFLength - SiThickness) * dx4);
    G4double DSVD1X = driftDecayX - (driftDecayLength * dx4) + (SiThickness * dx4);
    G4double DSVD2X = driftDecayX + (driftDecayLength * dx4) - (SiThickness * dx4);
    G4double USVDX = targetX + targetBlockLength + SiThickness;

    //y
    G4double dipole1Y = dipole1Height;
    G4double dipole2Y = dipole2Height;
    G4double dipole3Y = dipole3Height;
    G4double dipole4Y = dipole4Height;

    //z
    G4double targetZ = 0.;
    G4double dipole1Z = targetZ + dipole1Radius;
    G4double driftDipole1Z = dipole1Z - (dipole1Radius *  dx1) + (driftDipole1Length * dz1);/**/
    G4double dipole2Z = driftDipole1Z + (dipole2Radius * dx1) + (driftDipole1Length * dz1);/**/
    G4double drift5Z = dipole2Z - (dipole2Radius *  dx2) + (drift5Length * dz2);/**/
    G4double quad5Z = drift5Z + (drift5Length * dz2) + (quadrupole5Length * dz2);
    G4double coll1Z = quad5Z + (quadrupole5Length * dz2) + (EC1Thickness * dz2);
    G4double drift6Z = coll1Z + (EC1Thickness * dz2) + (drift6Length * dz2);
    G4double coll2Z = drift6Z  + (drift6Length * dz2) + (EC2Thickness * dz2);
    G4double dipole3Z = coll2Z + (drift6Length * dz2) + (dipole3Radius * dx2);/**/
    G4double driftDipole2Z = dipole3Z - (dipole2Radius *  dx3) + (driftDipole2Length * dz3);/**/
    G4double dipole4Z = driftDipole2Z + (dipole4Radius * dx3) + (driftDipole2Length * dz3);/**/
    G4double drift7Z = dipole4Z - (dipole4Radius *  dx4) + (drift7Length * dz4);/**/
    G4double coll3Z = drift7Z  + (drift7Length * dz4) + (EC3Thickness * dz4);
    G4double quad6Z = coll3Z + (EC3Thickness * dz4) + (quadrupole6Length * dz4);
    G4double drift8Z = quad6Z + (quadrupole6Length * dz4) + (drift8Length * dz4);
    G4double coll4Z = drift8Z  + (drift8Length * dz4) + (EC3Thickness * dz4);
    G4double quad8Z = coll4Z + (EC3Thickness * dz4) + (quadrupole8Length * dz4);
    G4double drift9Z = quad8Z + (quadrupole8Length * dz4) + (drift9Length * dz4);
    G4double coll5Z = drift9Z  + (drift9Length * dz4) + (EC3Thickness * dz4);
    G4double quad9Z = coll5Z + (EC3Thickness * dz4) + (quadrupole9Length * dz4);
    G4double driftBUFFZ = quad9Z + (quadrupole9Length * dz4) + (driftBUFFLength * dz4);
    G4double collLASTZ = driftBUFFZ  + (driftBUFFLength * dz4) + (ECLASTThickness * dz4);
    G4double driftDecayZ = collLASTZ + (ECLASTThickness * dz4) + (driftDecayLength * dz4);

    G4double silicon1Z = driftDipole2Z + (Si1pos * dz3) - (driftDipole2Length * dz3);
    G4double silicon2Z = driftDipole2Z + ((driftDipole2Length - SiThickness)* dz3);
    G4double silicon3Z = drift7Z - ((drift7Length - SiThickness) * dz4);
    G4double silicon4Z = silicon3Z + (Si4pos * dz4);
    G4double silicon5Z = driftBUFFZ - ((driftBUFFLength - SiThickness) * dz4);
    G4double DSVD1Z = driftDecayZ - (driftDecayLength * dz4) + (SiThickness * dz4);
    G4double DSVD2Z = driftDecayZ + (driftDecayLength * dz4) - (SiThickness * dz4);
    G4double USVDZ = targetZ;

    G4double xWorld = 200. * m / 2;
    G4double yWorld = 200. * m / 2;
    G4double zWorld = 200. * m / 2;


    //Magnetic fields RICONTROLLARE UNITA' DI MISURA
    G4QuadrupoleMagField *Quad1Field = new G4QuadrupoleMagField( (-0.692447/PRHO) * tesla/(1.*m));
    G4QuadrupoleMagField *Quad2Field = new G4QuadrupoleMagField( (0.311347/PRHO )* tesla/(1.*m));
    G4QuadrupoleMagField *Quad3Field = new G4QuadrupoleMagField( (-0.194342/PRHO) * tesla/(1.*m));
    G4UniformMagField *Dipole1Field = new G4UniformMagField(G4ThreeVector(0.,1.798*tesla,0.)); //MAKES SENSE BUT I'M NOT SURE
    G4UniformMagField *Dipole2Field = new G4UniformMagField(G4ThreeVector(0.,1.798*tesla,0.));
    G4QuadrupoleMagField *Quad5Field = new G4QuadrupoleMagField( (0.639267/PRHO) * tesla/(1.*m));
    G4UniformMagField *Dipole3Field = new G4UniformMagField(G4ThreeVector(0.,1.798*tesla,0.));
    G4UniformMagField *Dipole4Field = new G4UniformMagField(G4ThreeVector(0.,1.798*tesla,0.));
    G4QuadrupoleMagField *Quad6Field = new G4QuadrupoleMagField( (0.458804/PRHO) * tesla/(1.*m));
    G4QuadrupoleMagField *Quad8Field = new G4QuadrupoleMagField( (-0.419312/PRHO) * tesla/(1.*m));
    G4QuadrupoleMagField *Quad9Field = new G4QuadrupoleMagField( (0.305695/PRHO) * tesla/(1.*m));
    
    //WORLD
    G4Box *solidWorld = new G4Box(
        "solidWorld", 
        xWorld,
        yWorld,
        zWorld);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(
        solidWorld,
        Material("vacuum"),
        "logicWorld");
    G4PVPlacement *physWorld = new G4PVPlacement(
        0,
        G4ThreeVector(0.,0.,0.),
        logicWorld,
        "physWorld",
        0,
        false,
        checkOverlaps);
    
    //rotation for tubes
    G4RotationMatrix* TubeRotation = new G4RotationMatrix();
    TubeRotation->rotateY(90.*deg);
    //rotations for dipoles
    G4RotationMatrix* DipoleRotation = new G4RotationMatrix();
    DipoleRotation->rotateX(90.*deg);
    //rotation for driftDipole1
    G4RotationMatrix* driftDipole11Rotation = new G4RotationMatrix();
    driftDipole11Rotation->rotateY(90.*deg);driftDipole11Rotation->rotateY(dipole1Deg);
    //rotation for after first dipole
    G4RotationMatrix* NewTubeRotation = new G4RotationMatrix();
    NewTubeRotation->rotateY(90.*deg);NewTubeRotation->rotateY(dipole1Deg+dipole2Deg);
    //rotation for driftDipole2
    G4RotationMatrix* driftDipole22Rotation = new G4RotationMatrix();
    driftDipole22Rotation->rotateY(90.*deg);driftDipole22Rotation->rotateY(dipole1Deg+dipole2Deg+dipole3Deg);
    //rotation for after second dipole
    G4RotationMatrix* NewNewTubeRotation = new G4RotationMatrix();
    NewNewTubeRotation->rotateY(90.*deg);NewNewTubeRotation->rotateY(dipole1Deg+dipole2Deg+dipole3Deg+dipole4Deg);
        
    //SOLID BLOCKS
    //target
    G4Tubs *solidTarget = new G4Tubs("solidTarget",0.,targetDiameter,thicknessTarget,0.*deg,360.*deg);
        //steel around target
    G4Box *solidTargetBlock1 = new G4Box("solidTargetBlock1",targetBlockLength,targetBlockSize,targetBlockSize*1.5);
    G4Box *solidTargetBlock2 = new G4Box("solidTargetBlock2",targetBlockLength,targetBlockSize,targetBlockSize*1.5);
    G4Box *solidTargetBlock3 = new G4Box("solidTargetBlock3",targetBlockLength,targetBlockSize,targetBlockSize);
    G4Box *solidTargetBlock4 = new G4Box("solidTargetBlock4",targetBlockLength,targetBlockSize,targetBlockSize);
    //drift1
    G4Tubs *solidDrift1 = new G4Tubs("solidDrift1",driftRadius,driftRadius+driftThick,drift1Length,0.*deg,360*deg);
    //quadrupole1
    G4Tubs *solidQuadrupole1 = new G4Tubs("solidQuadrupole1",quadrupole1Radius,quadrupole1Radius+quadrupoleThickness,quadrupole1Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField1 = new G4Tubs("solidQuadrupole1",0.,quadrupole1Radius,quadrupole1Length,0.*deg,360.*deg);
    //drift2
    G4Tubs *solidDrift2 = new G4Tubs("solidDrift2",driftRadius,driftRadius+driftThick,drift2Length,0.*deg,360*deg);
    //quadrupole2
    G4Tubs *solidQuadrupole2 = new G4Tubs("solidQuadrupole2",quadrupole2Radius,quadrupole2Radius+quadrupoleThickness,quadrupole2Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField2 = new G4Tubs("solidQuadrupole2",0.,quadrupole2Radius,quadrupole2Length,0.*deg,360.*deg);
    //drift3
    G4Tubs *solidDrift3 = new G4Tubs("solidDrift3",driftRadius,driftRadius+driftThick,drift3Length,0.*deg,360*deg);
    //quadrupole3
    G4Tubs *solidQuadrupole3 = new G4Tubs("solidQuadrupole3",quadrupole3Radius,quadrupole3Radius+quadrupoleThickness,quadrupole3Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField3 = new G4Tubs("solidQuadrupole3",0.,quadrupole3Radius,quadrupole3Length,0.*deg,360.*deg);
    //drift4
    G4Tubs *solidDrift4 = new G4Tubs("solidDrift4",driftRadius,driftRadius+driftThick,drift4Length,0.*deg,360*deg);
    //dipole1
    G4Tubs *solidDipole1up = new G4Tubs("solidDipole1up",dipole1InnerRadius,dipole1OuterRadius,dipoleThickness,90.*deg - dipole1Deg,dipole1Deg);
    G4Tubs *solidDipole1down = new G4Tubs("solidDipole1down",dipole1InnerRadius,dipole1OuterRadius,dipoleThickness,90.*deg - dipole1Deg,dipole1Deg);
    G4Tubs *solidDipole1Field = new G4Tubs("solidDipole1Field",dipole1InnerRadius,dipole1OuterRadius,dipole1Height-dipoleThickness,90.*deg - dipole1Deg,dipole1Deg);
    //driftDipole1
    G4Tubs *solidDriftDipole1 = new G4Tubs("solidDriftDipole1",driftRadius,driftRadius+driftThick,driftDipole1Length,0.*deg,360*deg);
    //dipole2
    G4Tubs *solidDipole2up = new G4Tubs("solidDipole2up",dipole2InnerRadius,dipole2OuterRadius,dipoleThickness,90.*deg - (2. * dipole2Deg),dipole2Deg);
    G4Tubs *solidDipole2down = new G4Tubs("solidDipole2down",dipole2InnerRadius,dipole2OuterRadius,dipoleThickness,90.*deg - (2. * dipole2Deg),dipole2Deg);
    G4Tubs *solidDipole2Field = new G4Tubs("solidDipole2Field",dipole2InnerRadius,dipole2OuterRadius,dipole2Height-dipoleThickness,90.*deg - (2. * dipole2Deg),dipole2Deg);
    //drift5
    G4Tubs *solidDrift5 = new G4Tubs("solidDrift5",driftRadius,driftRadius+driftThick,drift5Length,0.*deg,360*deg);
    //quadrupole5
    G4Tubs *solidQuadrupole5 = new G4Tubs("solidQuadrupole5",quadrupole5Radius,quadrupole5Radius+quadrupoleThickness,quadrupole5Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField5 = new G4Tubs("solidQuadrupole5",0.,quadrupole5Radius,quadrupole5Length,0.*deg,360.*deg);
    //elliptic_collimator1
    G4Box *firstECBlock1 = new G4Box("solidECBlock1",EC1Side,EC1Side,EC1Thickness);
    G4EllipticalTube *subtractECBlock1 = new G4EllipticalTube("solidSubtractEC1",EC1holeX,EC1holeY,EC1Thickness+2);
    G4SubtractionSolid *solidEC1 = new G4SubtractionSolid("solidEC1",firstECBlock1,subtractECBlock1);
    //drift6
    G4Tubs *solidDrift6 = new G4Tubs("solidDrift6",driftRadius,driftRadius+driftThick,drift6Length,0.*deg,360*deg);
    //elliptic_collimator2
    G4Box *firstECBlock2 = new G4Box("solidECBlock2",EC2Side,EC2Side,EC2Thickness);
    G4EllipticalTube *subtractECBlock2 = new G4EllipticalTube("solidSubtractEC2",EC2holeX,EC2holeY,EC2Thickness+2);
    G4SubtractionSolid *solidEC2 = new G4SubtractionSolid("solidEC2",firstECBlock2,subtractECBlock2);
    //dipole3
    G4Tubs *solidDipole3up = new G4Tubs("solidDipole3up",dipole3InnerRadius,dipole3OuterRadius,dipoleThickness,90.*deg - (3. * dipole3Deg),dipole3Deg);
    G4Tubs *solidDipole3down = new G4Tubs("solidDipole3down",dipole3InnerRadius,dipole3OuterRadius,dipoleThickness,90.*deg - (3. * dipole3Deg),dipole3Deg);
    G4Tubs *solidDipole3Field = new G4Tubs("solidDipole3Field",dipole3InnerRadius,dipole3OuterRadius,dipole3Height-dipoleThickness,90.*deg - (3. * dipole3Deg),dipole3Deg);
    //driftDipole2
    G4Tubs *solidDriftDipole2 = new G4Tubs("solidDriftDipole2",driftRadius,driftRadius+driftThick,driftDipole2Length,0.*deg,360*deg);
    //Silicon1&2
    G4Tubs *solidSilicon = new G4Tubs("solidSilicon",0.,SiRadius,SiThickness,0.*deg,360*deg);
    //dipole4
    G4Tubs *solidDipole4up = new G4Tubs("solidDipole4up",dipole4InnerRadius,dipole4OuterRadius,dipoleThickness,90.*deg - (4. * dipole4Deg),dipole4Deg);
    G4Tubs *solidDipole4down = new G4Tubs("solidDipole4down",dipole4InnerRadius,dipole4OuterRadius,dipoleThickness,90.*deg - (4. * dipole4Deg),dipole4Deg);
    G4Tubs *solidDipole4Field = new G4Tubs("solidDipole4Field",dipole4InnerRadius,dipole4OuterRadius,dipole4Height-dipoleThickness,90.*deg - (4. * dipole4Deg),dipole4Deg);
    //Silicon3&4
    //drift7
    G4Tubs *solidDrift7 = new G4Tubs("solidDrift7",driftRadius,driftRadius+driftThick,drift7Length,0.*deg,360*deg);
    //EC3(used3times)
    G4Box *firstECBlock3 = new G4Box("solidECBlock3",EC3Side,EC3Side,EC3Thickness);
    G4EllipticalTube *subtractECBlock3 = new G4EllipticalTube("solidSubtractEC3",EC3holeX,EC3holeY,EC3Thickness+2);
    G4SubtractionSolid *solidEC3 = new G4SubtractionSolid("solidEC3",firstECBlock3,subtractECBlock3);
    //quadrupole6
    G4Tubs *solidQuadrupole6 = new G4Tubs("solidQuadrupole6",quadrupole6Radius,quadrupole6Radius+quadrupoleThickness,quadrupole6Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField6 = new G4Tubs("solidQuadrupole6",0.,quadrupole6Radius,quadrupole6Length,0.*deg,360.*deg);
    //drift8
    G4Tubs *solidDrift8 = new G4Tubs("solidDrift8",driftRadius,driftRadius+driftThick,drift8Length,0.*deg,360*deg);
    //EC4 Omitted (defined as solidEC3)
    //quadrupole8 (7 skipped as in BDSIM model)
    G4Tubs *solidQuadrupole8 = new G4Tubs("solidQuadrupole8",quadrupole8Radius,quadrupole8Radius+quadrupoleThickness,quadrupole8Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField8 = new G4Tubs("solidQuadrupole8",0.,quadrupole8Radius,quadrupole8Length,0.*deg,360.*deg);
    //drift9
    G4Tubs *solidDrift9 = new G4Tubs("solidDrift9",driftRadius,driftRadius+driftThick,drift9Length,0.*deg,360*deg);
    //EC5 Omitted (defined as solidEC3)
    //quadrupole9
    G4Tubs *solidQuadrupole9 = new G4Tubs("solidQuadrupole9",quadrupole9Radius,quadrupole9Radius+quadrupoleThickness,quadrupole9Length,0.*deg,360.*deg);
    G4Tubs *solidQuadrupoleField9 = new G4Tubs("solidQuadrupole9",0.,quadrupole9Radius,quadrupole9Length,0.*deg,360.*deg);
    //silicon5
    //driftBuff
    G4Tubs *solidDriftBUFF = new G4Tubs("solidDriftBUFF",driftBUFFRadius,driftBUFFRadius+driftThick,driftBUFFLength,0.*deg,360*deg);
    //ECLAST
    G4Box *firstECBlockLAST = new G4Box("solidECBlockLAST",ECLASTSide,ECLASTSide,ECLASTThickness);
    G4EllipticalTube *subtractECBlockLAST = new G4EllipticalTube("solidSubtractECLAST",ECLASTholeX,ECLASTholeY,ECLASTThickness+2);
    G4SubtractionSolid *solidECLAST = new G4SubtractionSolid("solidECLAST",firstECBlockLAST,subtractECBlockLAST);
    //driftDecay
    G4Tubs *solidDriftDecay = new G4Tubs("solidDriftDecay",driftDecayRadius,driftDecayRadius+driftThick,driftDecayLength,0.*deg,360*deg);
    //downstream virtual detectors
    G4Tubs *solidDSVD = new G4Tubs("solidDSVD",0.,driftDecayRadius,SiThickness,0.*deg,360.*deg);
    G4Tubs *solidUSVD = new G4Tubs("solidUSVD",0.,driftRadius,SiThickness,0.*deg,360.*deg);


    //LOGIC BLOCKS
    //G4Material* targetMaterial=Material("ENUTAG_graphite");
    /*if(mode=="pion"){targetMaterial=Material("vacuum");}
    else{targetMaterial=Material("ENUTAG_graphite");}*/
    G4LogicalVolume *logicTarget = new G4LogicalVolume(solidTarget, Material("ENUTAG_graphite"), "logicTarget");
    
    G4LogicalVolume *logicTargetBlock1 = new G4LogicalVolume(solidTargetBlock1, Material("iron"), "logicTargetBlock1");
    G4LogicalVolume *logicTargetBlock2 = new G4LogicalVolume(solidTargetBlock2, Material("iron"), "logicTargetBlock2");
    G4LogicalVolume *logicTargetBlock3 = new G4LogicalVolume(solidTargetBlock3, Material("iron"), "logicTargetBlock3");
    G4LogicalVolume *logicTargetBlock4 = new G4LogicalVolume(solidTargetBlock4, Material("iron"), "logicTargetBlock4");
    
    G4LogicalVolume *logicDrift1 = new G4LogicalVolume(solidDrift1, Material("iron"), "logicDrift1");

    G4LogicalVolume *logicQuadrupole1 = new G4LogicalVolume(solidQuadrupole1, Material("iron"), "logicQuadrupole1");
    G4LogicalVolume *logicQuadrupoleField1 = new G4LogicalVolume(solidQuadrupoleField1, Material("vacuum"), "logicQuadrupoleField1");
    G4FieldManager *Quadrupole1FieldMgr = new G4FieldManager();
    Quadrupole1FieldMgr->SetDetectorField(Quad1Field);
    Quadrupole1FieldMgr->CreateChordFinder(Quad1Field);
    logicQuadrupoleField1->SetFieldManager(Quadrupole1FieldMgr, true);

    G4LogicalVolume *logicDrift2 = new G4LogicalVolume(solidDrift2, Material("iron"), "logicDrift2");

    G4LogicalVolume *logicQuadrupole2 = new G4LogicalVolume(solidQuadrupole2, Material("iron"), "logicQuadrupole2");
    G4LogicalVolume *logicQuadrupoleField2 = new G4LogicalVolume(solidQuadrupoleField2, Material("vacuum"), "logicQuadrupoleField2");
    G4FieldManager *Quadrupole2FieldMgr = new G4FieldManager();
    Quadrupole2FieldMgr->SetDetectorField(Quad2Field);
    Quadrupole2FieldMgr->CreateChordFinder(Quad2Field);
    logicQuadrupoleField2->SetFieldManager(Quadrupole2FieldMgr, true);

    G4LogicalVolume *logicDrift3 = new G4LogicalVolume(solidDrift3, Material("iron"), "logicDrift3");

    G4LogicalVolume *logicQuadrupole3 = new G4LogicalVolume(solidQuadrupole3, Material("iron"), "logicQuadrupole3");
    G4LogicalVolume *logicQuadrupoleField3 = new G4LogicalVolume(solidQuadrupoleField3, Material("vacuum"), "logicQuadrupoleField3");
    G4FieldManager *Quadrupole3FieldMgr = new G4FieldManager();
    Quadrupole3FieldMgr->SetDetectorField(Quad3Field);
    Quadrupole3FieldMgr->CreateChordFinder(Quad3Field);
    logicQuadrupoleField3->SetFieldManager(Quadrupole3FieldMgr, true);

    G4LogicalVolume *logicDrift4 = new G4LogicalVolume(solidDrift4, Material("iron"), "logicDrift4");

    G4LogicalVolume *logicDipole1up = new G4LogicalVolume(solidDipole1up, Material("copper"), "logicDipole1up");
    G4LogicalVolume *logicDipole1down = new G4LogicalVolume(solidDipole1down, Material("copper"), "logicDipole1down");
    G4LogicalVolume *logicDipole1Field = new G4LogicalVolume(solidDipole1Field, Material("vacuum"), "logicDipole1Field");
    G4FieldManager *Dipole1FieldMgr = new G4FieldManager();
    Dipole1FieldMgr->SetDetectorField(Dipole1Field);
    Dipole1FieldMgr->CreateChordFinder(Dipole1Field);
    logicDipole1Field->SetFieldManager(Dipole1FieldMgr, true);

    G4LogicalVolume *logicDriftDipole1 = new G4LogicalVolume(solidDriftDipole1, Material("iron"), "logicDriftDipole1");

    G4LogicalVolume *logicDipole2up = new G4LogicalVolume(solidDipole2up, Material("copper"), "logicDipole2up");
    G4LogicalVolume *logicDipole2down = new G4LogicalVolume(solidDipole2down, Material("copper"), "logicDipole2down");
    G4LogicalVolume *logicDipole2Field = new G4LogicalVolume(solidDipole2Field, Material("vacuum"), "logicDipole2Field");
    G4FieldManager *Dipole2FieldMgr = new G4FieldManager();
    Dipole2FieldMgr->SetDetectorField(Dipole2Field);
    Dipole2FieldMgr->CreateChordFinder(Dipole2Field);
    logicDipole2Field->SetFieldManager(Dipole2FieldMgr, true);

    G4LogicalVolume *logicDrift5 = new G4LogicalVolume(solidDrift5, Material("iron"), "logicDrift5");

    G4LogicalVolume *logicQuadrupole5 = new G4LogicalVolume(solidQuadrupole5, Material("iron"), "logicQuadrupole5");
    G4LogicalVolume *logicQuadrupoleField5 = new G4LogicalVolume(solidQuadrupoleField5, Material("vacuum"), "logicQuadrupoleField5");

    G4LogicalVolume *logicEC1 = new G4LogicalVolume(solidEC1, Material("tungsten"), "logicEC1");

    G4LogicalVolume *logicDrift6 = new G4LogicalVolume(solidDrift6, Material("iron"), "logicDrift6");

    G4LogicalVolume *logicEC2 = new G4LogicalVolume(solidEC2, Material("tungsten"), "logicEC2");

    G4LogicalVolume *logicDipole3up = new G4LogicalVolume(solidDipole3up, Material("copper"), "logicDipole3up");
    G4LogicalVolume *logicDipole3down = new G4LogicalVolume(solidDipole3down, Material("copper"), "logicDipole3down");
    G4LogicalVolume *logicDipole3Field = new G4LogicalVolume(solidDipole3Field, Material("vacuum"), "logicDipole3Field");
    G4FieldManager *Dipole3FieldMgr = new G4FieldManager();
    Dipole3FieldMgr->SetDetectorField(Dipole3Field);
    Dipole3FieldMgr->CreateChordFinder(Dipole3Field);
    logicDipole3Field->SetFieldManager(Dipole3FieldMgr, true);

    G4LogicalVolume *logicDriftDipole2 = new G4LogicalVolume(solidDriftDipole2, Material("iron"), "logicDriftDipole2");

    //G4LogicalVolume *logicSilicon1 = new G4LogicalVolume(solidSilicon, Material("silicon"), "logicSilicon1");
    //G4LogicalVolume *logicSilicon2 = new G4LogicalVolume(solidSilicon, Material("silicon"), "logicSilicon2");

    G4LogicalVolume *logicDipole4up = new G4LogicalVolume(solidDipole4up, Material("copper"), "logicDipole4up");
    G4LogicalVolume *logicDipole4down = new G4LogicalVolume(solidDipole4down, Material("copper"), "logicDipole4down");
    G4LogicalVolume *logicDipole4Field = new G4LogicalVolume(solidDipole4Field, Material("vacuum"), "logicDipole4Field");
    G4FieldManager *Dipole4FieldMgr = new G4FieldManager();
    Dipole4FieldMgr->SetDetectorField(Dipole4Field);
    Dipole4FieldMgr->CreateChordFinder(Dipole4Field);
    logicDipole4Field->SetFieldManager(Dipole4FieldMgr, true);

    //G4LogicalVolume *logicSilicon3 = new G4LogicalVolume(solidSilicon, Material("silicon"), "logicSilicon3");
    //G4LogicalVolume *logicSilicon4 = new G4LogicalVolume(solidSilicon, Material("silicon"), "logicSilicon4");

    G4LogicalVolume *logicDrift7 = new G4LogicalVolume(solidDrift7, Material("iron"), "logicDrift7");

    G4LogicalVolume *logicEC3 = new G4LogicalVolume(solidEC3, Material("tungsten"), "logicEC3");

    G4LogicalVolume *logicQuadrupole6 = new G4LogicalVolume(solidQuadrupole6, Material("iron"), "logicQuadrupole6");
    G4LogicalVolume *logicQuadrupoleField6 = new G4LogicalVolume(solidQuadrupoleField6, Material("vacuum"), "logicQuadrupoleField6");

    G4LogicalVolume *logicDrift8 = new G4LogicalVolume(solidDrift8, Material("iron"), "logicDrift8");

    G4LogicalVolume *logicQuadrupole8 = new G4LogicalVolume(solidQuadrupole8, Material("iron"), "logicQuadrupole8");
    G4LogicalVolume *logicQuadrupoleField8 = new G4LogicalVolume(solidQuadrupoleField8, Material("vacuum"), "logicQuadrupoleField8");

    G4LogicalVolume *logicDrift9 = new G4LogicalVolume(solidDrift9, Material("iron"), "logicDrift9");

    G4LogicalVolume *logicQuadrupole9 = new G4LogicalVolume(solidQuadrupole9, Material("iron"), "logicQuadrupole9");
    G4LogicalVolume *logicQuadrupoleField9 = new G4LogicalVolume(solidQuadrupoleField9, Material("vacuum"), "logicQuadrupoleField9");

    //G4LogicalVolume *logicSilicon5 = new G4LogicalVolume(solidSilicon, Material("silicon"), "logicSilicon5");

    G4LogicalVolume *logicDriftBUFF = new G4LogicalVolume(solidDriftBUFF, Material("iron"), "logicDriftBUFF");

    G4LogicalVolume *logicECLAST = new G4LogicalVolume(solidECLAST, Material("tungsten"), "logicECLAST");

    G4LogicalVolume *logicDriftDecay = new G4LogicalVolume(solidDriftDecay, Material("iron"), "logicDriftDecay");


    //PHYS BLOCKS
    G4VPhysicalVolume *physTarget = new G4PVPlacement(TubeRotation,G4ThreeVector(-targetX,0.,0.),logicTarget,"physTarget",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physTargetBlock1 = new G4PVPlacement(0,G4ThreeVector(0.,sideTarget+targetBlockSize,0.),logicTargetBlock1,"physTargetBlock1",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physTargetBlock2 = new G4PVPlacement(0,G4ThreeVector(0.,(sideTarget+targetBlockSize)*(-1),0.),logicTargetBlock2,"physTargetBlock2",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physTargetBlock3 = new G4PVPlacement(0,G4ThreeVector(0.,0.,sideTarget+targetBlockSize),logicTargetBlock3,"physTargetBlock3",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physTargetBlock4 = new G4PVPlacement(0,G4ThreeVector(0.,0.,(sideTarget+targetBlockSize)*(-1)),logicTargetBlock4,"physTargetBlock4",logicWorld,false,checkOverlaps);
    
    G4VPhysicalVolume *physDrift1 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift1X,0.,0.),logicDrift1,"physDrift1",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole1 = new G4PVPlacement(TubeRotation,G4ThreeVector(quad1X,0.,0.),logicQuadrupole1,"physQuadrupole1",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField1 = new G4PVPlacement(TubeRotation,G4ThreeVector(quad1X,0.,0.),logicQuadrupoleField1,"physQuadrupoleField1",logicWorld,false,checkOverlaps);
    
    G4VPhysicalVolume *physDrift2 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift2X,0.,0.),logicDrift2,"physDrift2",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole2 = new G4PVPlacement(TubeRotation,G4ThreeVector(quad2X,0.,0.),logicQuadrupole2,"physQuadrupole2",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField2 = new G4PVPlacement(TubeRotation,G4ThreeVector(quad2X,0.,0.),logicQuadrupoleField2,"physQuadrupoleField2",logicWorld,false,checkOverlaps);
    
    G4VPhysicalVolume *physDrift3 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift3X,0.,0.),logicDrift3,"physDrift3",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole3 = new G4PVPlacement(TubeRotation,G4ThreeVector(quad3X,0.,0.),logicQuadrupole3,"physQuadrupole3",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField3 = new G4PVPlacement(TubeRotation,G4ThreeVector(quad3X,0.,0.),logicQuadrupoleField3,"physQuadrupoleField3",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDrift4 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift4X,0.,0.),logicDrift4,"physDrift4",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDipole1up = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole1X,dipole1Y,dipole1Z),logicDipole1up,"physDipole1up",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole1down = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole1X,(-1)*dipole1Y,dipole1Z),logicDipole1down,"physDipole1down",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole1Field = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole1X,0.,dipole1Z),logicDipole1Field,"physDipole1Field",logicWorld,false,checkOverlaps);
    
    G4VPhysicalVolume *physDriftDipole1 = new G4PVPlacement(driftDipole11Rotation,G4ThreeVector(driftDipole1X,0.,driftDipole1Z),logicDriftDipole1,"physDriftDipole1",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDipole2up = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole2X,dipole2Y,dipole2Z),logicDipole2up,"physDipole2up",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole2down = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole2X,(-1)*dipole2Y,dipole2Z),logicDipole2down,"physDipole2down",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole2Field = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole2X,0.,dipole2Z),logicDipole2Field,"physDipole2Field",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDrift5 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(drift5X,0.,drift5Z),logicDrift5,"physDrift5",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole5 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(quad5X,0.,quad5Z),logicQuadrupole5,"physQuadrupole5",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField5 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(quad5X,0.,quad5Z),logicQuadrupoleField5,"physQuadrupoleField5",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physEC1 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(coll1X,0.,coll1Z),logicEC1,"physEC1",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDrift6 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(drift6X,0.,drift6Z),logicDrift6,"physDrift6",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physEC2 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(coll2X,0.,coll2Z),logicEC2,"physEC2",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDipole3up = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole3X,dipole3Y,dipole3Z),logicDipole3up,"physDipole3up",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole3down = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole3X,(-1)*dipole3Y,dipole3Z),logicDipole3down,"physDipole3down",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole3Field = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole3X,0.,dipole3Z),logicDipole3Field,"physDipole3Field",logicWorld,false,checkOverlaps);
    
    G4VPhysicalVolume *physDriftDipole2 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(driftDipole2X,0.,driftDipole2Z),logicDriftDipole2,"physDriftDipole2",logicWorld,false,checkOverlaps);

    //G4VPhysicalVolume *physSilicon1 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(silicon1X,0.,silicon1Z),logicSilicon1,"physSilicon1",logicWorld,false,checkOverlaps);
    //G4VPhysicalVolume *physSilicon2 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(silicon2X,0.,silicon2Z),logicSilicon2,"physSilicon2",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDipole4up = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole4X,dipole4Y,dipole4Z),logicDipole4up,"physDipole4up",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole4down = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole4X,(-1)*dipole4Y,dipole4Z),logicDipole4down,"physDipole4down",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipole4Field = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipole4X,0.,dipole4Z),logicDipole4Field,"physDipole4Field",logicWorld,false,checkOverlaps);
    
    //G4VPhysicalVolume *physSilicon3 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon3X,0.,silicon3Z),logicSilicon3,"physSilicon3",logicWorld,false,checkOverlaps);
    //G4VPhysicalVolume *physSilicon4 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon4X,0.,silicon4Z),logicSilicon4,"physSilicon4",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDrift7 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(drift7X,0.,drift7Z),logicDrift7,"physDrift7",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physEC3 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(coll3X,0.,coll3Z),logicEC3,"physEC3",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole6 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(quad6X,0.,quad6Z),logicQuadrupole6,"physQuadrupole6",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField6 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(quad6X,0.,quad6Z),logicQuadrupoleField6,"physQuadrupoleField6",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDrift8 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(drift8X,0.,drift8Z),logicDrift8,"physDrift8",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physEC4 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(coll4X,0.,coll4Z),logicEC3,"physEC4",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole8 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(quad8X,0.,quad8Z),logicQuadrupole8,"physQuadrupole8",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField8 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(quad8X,0.,quad8Z),logicQuadrupoleField8,"physQuadrupoleField8",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDrift9 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(drift9X,0.,drift9Z),logicDrift9,"physDrift9",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physEC5 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(coll5X,0.,coll5Z),logicEC3,"physEC5",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physQuadrupole9 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(quad9X,0.,quad9Z),logicQuadrupole9,"physQuadrupole9",logicWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField9 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(quad9X,0.,quad9Z),logicQuadrupoleField9,"physQuadrupoleField9",logicWorld,false,checkOverlaps);

    //G4VPhysicalVolume *physSilicon5 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon5X,0.,silicon5Z),logicSilicon5,"physSilicon5",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDriftBUFF = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(driftBUFFX,0.,driftBUFFZ),logicDriftBUFF,"physDriftBUFF",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physECLAST = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(collLASTX,0.,collLASTZ),logicECLAST,"physECLAST",logicWorld,false,checkOverlaps);

    G4VPhysicalVolume *physDriftDecay = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(driftDecayX,0.,driftDecayZ),logicDriftDecay,"physDriftDecay",logicWorld,false,checkOverlaps);

    //detector definition
    logicDetector1 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector1");
    G4VPhysicalVolume *physDetector1 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(silicon1X,0.,silicon1Z),logicDetector1,"physDetector1",logicWorld,false,checkOverlaps,1);
    
    logicDetector2 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector2");
    G4VPhysicalVolume *physDetector2 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(silicon2X,0.,silicon2Z),logicDetector2,"physDetector2",logicWorld,false,checkOverlaps,2);
    
    logicDetector3 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector3");
    G4VPhysicalVolume *physDetector3 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon3X,0.,silicon3Z),logicDetector3,"physDetector3",logicWorld,false,checkOverlaps,3);
    
    logicDetector4 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector4");
    G4VPhysicalVolume *physDetector4 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon4X,0.,silicon4Z),logicDetector4,"physDetector4",logicWorld,false,checkOverlaps,4);
    
    logicDetector5 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector5");
    G4VPhysicalVolume *physDetector5 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon5X,0.,silicon5Z),logicDetector5,"physDetector5",logicWorld,false,checkOverlaps,5);

    logicDSVD1 = new G4LogicalVolume(solidDSVD,Material("vacuum"),"logicDSVD1");
    G4VPhysicalVolume *physDSVD1 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(DSVD1X,0.,DSVD1Z),logicDSVD1,"physDSVD1",logicWorld,false,checkOverlaps,6);

    logicDSVD2 = new G4LogicalVolume(solidDSVD,Material("vacuum"),"logicDSVD2");
    G4VPhysicalVolume *physDSVD2 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(DSVD2X,0.,DSVD2Z),logicDSVD2,"physDSVD2",logicWorld,false,checkOverlaps,7);

    logicUSVD = new G4LogicalVolume(solidUSVD,Material("vacuum"),"logicUSVD");
    G4VPhysicalVolume *physUSVD = new G4PVPlacement(TubeRotation,G4ThreeVector(USVDX,0.,USVDZ),logicUSVD,"physUSVD",logicWorld,false,checkOverlaps,8);

    return physWorld;

}

void ENUTAG_Construction::ConstructSDandField(){
    ENUTAG_SensitiveDetector *sensDet1 = new ENUTAG_SensitiveDetector("sensDet1");
    ENUTAG_SensitiveDetector *sensDet2 = new ENUTAG_SensitiveDetector("sensDet2");
    ENUTAG_SensitiveDetector *sensDet3 = new ENUTAG_SensitiveDetector("sensDet3");
    ENUTAG_SensitiveDetector *sensDet4 = new ENUTAG_SensitiveDetector("sensDet4");
    ENUTAG_SensitiveDetector *sensDet5 = new ENUTAG_SensitiveDetector("sensDet5");
    ENUTAG_SensitiveDetector *sensDSVD1 = new ENUTAG_SensitiveDetector("sensDSVD1");
    ENUTAG_SensitiveDetector *sensDSVD2 = new ENUTAG_SensitiveDetector("sensDSVD2");
    ENUTAG_SensitiveDetector *sensUSVD = new ENUTAG_SensitiveDetector("sensUSVD");
    logicDetector1->SetSensitiveDetector(sensDet1);
    logicDetector2->SetSensitiveDetector(sensDet2);
    logicDetector3->SetSensitiveDetector(sensDet3);
    logicDetector4->SetSensitiveDetector(sensDet4);
    logicDetector5->SetSensitiveDetector(sensDet5);
    logicDSVD1->SetSensitiveDetector(sensDSVD1);
    logicDSVD2->SetSensitiveDetector(sensDSVD2);
    logicUSVD->SetSensitiveDetector(sensUSVD);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet1);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet2);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet3);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet4);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet5);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDSVD1);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDSVD2);
    G4SDManager::GetSDMpointer()->AddNewDetector(sensUSVD);
}