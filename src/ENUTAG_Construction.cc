#include "ENUTAG_Construction.hh"
#include<map>
#include<cmath>

    //ALL PARAMETERS ARE externs

    G4bool checkOverlaps = true;

    //PARAMETERS (to put in different function maybe)
    G4double PRHO = 8.5 * GeV / 0.299792458;
    G4double MID_ANGLE = 0.;

    G4double thicknessTarget = 1.3 * m / 2;
    G4double sideTarget = 0.1 * m / 2;
    G4double targetDiameter = 6 * mm / 2;
    G4double targetBlockLength = 3.0 * m / 2;
    G4double targetBlockSize = 0.12 * m / 2;

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
    G4double quadrupole5Radius = 0.05 * m / 2;
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
    G4double EC6Thickness = 2.2 * m / 2;
    G4double EC6Side = (quadrupole9Radius + quadrupoleThickness);
    G4double EC6holeX = 130 * mm / 2;
    G4double EC6holeY = 110 * mm / 2;

    //Silicon stuff
    G4double SiThickness = 0.5 * mm;
    G4double Si1pos = 0.36 * m;
    G4double Si4pos = 0.25 * m;
    G4double SiRadius = driftRadius;

    //Shielding stuff
    G4double concreteSTwidth = 1.5 * m / 2;
    G4double concreteUTwidth = 1.39 * m / 2;
    G4double concreteFTwidth = concreteSTwidth + concreteSTwidth + concreteSTwidth;
    G4double concreteFTheight = 0.6 * m / 2;
    G4double concreteLength = 8.0 * m / 2;

    G4double concreteBigLength = 42.6 * m / 2;
    G4double concreteBigWidth1 = 0.9 * m / 2;
    G4double concreteBigWidth2 = 2.0 * m / 2;

    G4double CD1radius = 19.56 * m;
    G4double CD2radius = 19.62 * m;
    G4double CD1InnerRadius = CD1radius - concreteFTwidth;
    G4double CD1OuterRadius = CD1radius + concreteFTwidth;
    G4double CD2InnerRadius = CD2radius - concreteFTwidth;
    G4double CD2OuterRadius = CD2radius + concreteFTwidth;

    G4double concrete1Length = drift5Length + quadrupole5Length + EC1Thickness + drift6Length + EC2Thickness;
    G4double concrete2Length = drift7Length + EC3Thickness + quadrupole6Length + drift8Length + EC3Thickness + quadrupole8Length + drift9Length + EC3Thickness + quadrupole9Length + driftBUFFLength + EC6Thickness;

    //world stuff
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
    G4double EC1X = quad5X  + (quadrupole5Length * dx2) + (EC1Thickness * dx2);
    G4double drift6X = EC1X + (EC1Thickness * dx2) + (drift6Length * dx2);
    G4double EC2X = drift6X  + (drift6Length * dx2) + (EC2Thickness * dx2);
    G4double dipole3X = EC2X + (EC2Thickness * dx2) - (dipole3Radius * dz2);
    G4double driftDipole2X = dipole3X + (dipole3Radius * dz3) + (driftDipole2Length * dx3);
    G4double dipole4X = driftDipole2X + (driftDipole2Length * dx3) - (dipole4Radius * dz3);
    G4double drift7X = dipole4X + (dipole4Radius * dz4) + (drift7Length * dx4);
    G4double EC3X = drift7X  + (drift7Length * dx4) + (EC3Thickness * dx4);
    G4double quad6X = EC3X + (EC3Thickness * dx4) + (quadrupole6Length * dx4);
    G4double drift8X = quad6X + (quadrupole6Length * dx4) + (drift8Length * dx4);
    G4double EC4X = drift8X  + (drift8Length * dx4) + (EC3Thickness * dx4);
    G4double quad8X = EC4X + (EC3Thickness * dx4) + (quadrupole8Length * dx4);
    G4double drift9X = quad8X + (quadrupole8Length * dx4) + (drift9Length * dx4);
    G4double EC5X = drift9X  + (drift9Length * dx4) + (EC3Thickness * dx4);
    G4double quad9X = EC5X + (EC3Thickness * dx4) + (quadrupole9Length * dx4);
    G4double driftBUFFX = quad9X + (quadrupole9Length * dx4) + (driftBUFFLength * dx4);
    G4double EC6X = driftBUFFX  + (driftBUFFLength * dx4) + (EC6Thickness * dx4);
    G4double driftDecayX = EC6X + (EC6Thickness * dx4) + (driftDecayLength * dx4);

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
    G4double EC1Z = quad5Z + (quadrupole5Length * dz2) + (EC1Thickness * dz2);
    G4double drift6Z = EC1Z + (EC1Thickness * dz2) + (drift6Length * dz2);
    G4double EC2Z = drift6Z  + (drift6Length * dz2) + (EC2Thickness * dz2);
    G4double dipole3Z = EC2Z + (drift6Length * dz2) + (dipole3Radius * dx2);/**/
    G4double driftDipole2Z = dipole3Z - (dipole2Radius *  dx3) + (driftDipole2Length * dz3);/**/
    G4double dipole4Z = driftDipole2Z + (dipole4Radius * dx3) + (driftDipole2Length * dz3);/**/
    G4double drift7Z = dipole4Z - (dipole4Radius *  dx4) + (drift7Length * dz4);/**/
    G4double EC3Z = drift7Z  + (drift7Length * dz4) + (EC3Thickness * dz4);
    G4double quad6Z = EC3Z + (EC3Thickness * dz4) + (quadrupole6Length * dz4);
    G4double drift8Z = quad6Z + (quadrupole6Length * dz4) + (drift8Length * dz4);
    G4double EC4Z = drift8Z  + (drift8Length * dz4) + (EC3Thickness * dz4);
    G4double quad8Z = EC4Z + (EC3Thickness * dz4) + (quadrupole8Length * dz4);
    G4double drift9Z = quad8Z + (quadrupole8Length * dz4) + (drift9Length * dz4);
    G4double EC5Z = drift9Z  + (drift9Length * dz4) + (EC3Thickness * dz4);
    G4double quad9Z = EC5Z + (EC3Thickness * dz4) + (quadrupole9Length * dz4);
    G4double driftBUFFZ = quad9Z + (quadrupole9Length * dz4) + (driftBUFFLength * dz4);
    G4double EC6Z = driftBUFFZ  + (driftBUFFLength * dz4) + (EC6Thickness * dz4);
    G4double driftDecayZ = EC6Z + (EC6Thickness * dz4) + (driftDecayLength * dz4);

    G4double silicon1Z = driftDipole2Z + (Si1pos * dz3) - (driftDipole2Length * dz3);
    G4double silicon2Z = driftDipole2Z + ((driftDipole2Length - SiThickness)* dz3);
    G4double silicon3Z = drift7Z - ((drift7Length - SiThickness) * dz4);
    G4double silicon4Z = silicon3Z + (Si4pos * dz4);
    G4double silicon5Z = driftBUFFZ - ((driftBUFFLength - SiThickness) * dz4);
    G4double DSVD1Z = driftDecayZ - (driftDecayLength * dz4) + (SiThickness * dz4);
    G4double DSVD2Z = driftDecayZ + (driftDecayLength * dz4) - (SiThickness * dz4);
    G4double USVDZ = targetZ;

    //target iron blocks 
    G4double targetY = 0.;
    G4double targetBlockX_offset = -0. * m;
    G4double targetBlockY_offset = (0.12 * m) + targetBlockSize;
    G4double targetBlock1X = targetX + targetBlockX_offset;
    G4double targetBlock1Y = targetY + targetBlockY_offset;
    G4double targetBlock1Z = targetZ;
    G4double targetBlock2X = targetX + targetBlockX_offset;
    G4double targetBlock2Y = targetY - targetBlockY_offset;
    G4double targetBlock2Z = targetZ;

    //shielding positions
    G4double concrete_t_X_offset = 1.0 * m;
    G4double concrete_t_Y_offset = 1.501 * m;
    G4double concrete_t_Z_offset = 1.45 * m;
    //as reference
    G4double quad2Y = 0. * m;
    G4double quad2Z = 0. * m;

    G4double rtX = quad2X + concrete_t_X_offset - quadrupole1Length;
    G4double rtY = quad2Y;// + concrete_t_Y_offset;
    G4double rtZ = quad2Z + concrete_t_Z_offset;
    G4double ltX = quad2X + concrete_t_X_offset - quadrupole1Length;
    G4double ltY = quad2Y;// + concrete_t_Y_offset;
    G4double ltZ = quad2Z - concrete_t_Z_offset;
    G4double utX = quad2X + concrete_t_X_offset - quadrupole1Length;
    G4double utY = quad2Y + concrete_t_Z_offset;
    G4double utZ = quad2Z;

    G4double concrete_tf_Xoffset = 1. * m;
    G4double concrete_tf_Yoffset = -1.1 * m;

    G4double ftX = quad2X + concrete_tf_Xoffset - quadrupole1Length;
    G4double ftY = quad2Y + concrete_tf_Yoffset;
    G4double ftZ = quad2Z;

    G4double dipole1refY = 0.;
    G4double bigUpper1X = dipole1X;
    G4double bigUpper1Y = dipole1refY + (1.3 * m);
    G4double bigUpper1Z = dipole1Z - (0.2 * m) - dipole1Radius; 
    G4double bigLower1X = dipole1X;
    G4double bigLower1Y = dipole1refY - (1.3 * m);
    G4double bigLower1Z = dipole1Z - (0.2 * m) - dipole1Radius;
    G4double bigUpper2X = dipole1X;
    G4double bigUpper2Y = dipole1refY + (1.0 * m);
    G4double bigUpper2Z = dipole1Z - (1.7 * m) - dipole1Radius; 
    G4double bigLower2X = dipole1X;
    G4double bigLower2Y = dipole1refY - (1.0 * m);
    G4double bigLower2Z = dipole1Z - (1.7 * m) - dipole1Radius;

    G4double D1X = dipole1X;
    G4double D1Z = CD1radius;
    G4double concrete1X = dipole2X + (dipole2Radius * dz2) + (concrete1Length * dx2);
    G4double concrete1Z = dipole2Z - (dipole2Radius * dx2) + (concrete1Length * dz2);
    G4double D2X = concrete1X + (concrete1Length * dx2) - (CD2radius * dz2);
    G4double D2Z = concrete1Z + (concrete1Length * dz2) + (CD2radius * dx2);
    G4double concrete2X = (EC6X + (EC6Thickness * dx4) + drift7X - (drift7Length * dx4)) * 0.5;
    G4double concrete2Z = (EC6Z + (EC6Thickness * dz4) + drift7Z - (drift7Length * dz4)) * 0.5;

    //world stuff
    G4double xWorld = 200. * m / 2;
    G4double yWorld = 200. * m / 2;
    G4double zWorld = 200. * m / 2;

    //tubes
    G4RotationMatrix* TubeRotation = new G4RotationMatrix();
    //rotations for dipoles
    G4RotationMatrix* DipoleRotation = new G4RotationMatrix();
    //driftDipole1
    G4RotationMatrix* driftDipole11Rotation = new G4RotationMatrix();
    //after first dipole
    G4RotationMatrix* NewTubeRotation = new G4RotationMatrix();
    //driftDipole2
    G4RotationMatrix* driftDipole22Rotation = new G4RotationMatrix();
    //after second dipole
    G4RotationMatrix* NewNewTubeRotation = new G4RotationMatrix();
    //Concretes
    G4RotationMatrix* Concrete1Rotation = new G4RotationMatrix();
    G4RotationMatrix* Concrete2Rotation = new G4RotationMatrix();

    //field parameters
    G4double quadrupole1Field = -0.692447;
    G4double quadrupole2Field = 0.311347;
    G4double quadrupole3Field = -0.194342;
    //G4double quadrupole4Field = -0.692447;//
    G4double quadrupole5Field = 0.639267;
    G4double quadrupole6Field = 0.458804;
    //G4double quadrupole7Field = -0.692447;//
    G4double quadrupole8Field = -0.419312;
    G4double quadrupole9Field = 0.305695;

    G4double dipoleField = 1.789;

    //custom materials
    G4Material* my_vacuum = new G4Material("Galactic", 1., 1.01*g/mole,1.e-25*g/cm3,kStateGas, 2.73*kelvin, 3.e-18*pascal);
    G4Material* my_graphite = new G4Material("myGraphite",6.,12.01*g/mole,1.85*g/cm3);

ENUTAG_Construction::ENUTAG_Construction(){}
ENUTAG_Construction::~ENUTAG_Construction(){}

void ENUTAG_Construction::DefineRotations(){
    //tubes
    TubeRotation->rotateY(90.*deg);
    //rotations for dipoles
    DipoleRotation->rotateX(90.*deg);
    //driftDipole1
    driftDipole11Rotation->rotateY(90.*deg);
    driftDipole11Rotation->rotateY(dipole1Deg);
    //after first dipole
    NewTubeRotation->rotateY(90.*deg);
    NewTubeRotation->rotateY(dipole1Deg+dipole2Deg);
    //driftDipole2
    driftDipole22Rotation->rotateY(90.*deg);
    driftDipole22Rotation->rotateY(dipole1Deg+dipole2Deg+dipole3Deg);
    //after second dipole
    NewNewTubeRotation->rotateY(90.*deg);
    NewNewTubeRotation->rotateY(dipole1Deg+dipole2Deg+dipole3Deg+dipole4Deg);
    //Concrete1&2
    Concrete1Rotation->rotateY(2.*dipole1Deg);
    Concrete2Rotation->rotateY(4.*dipole1Deg);
    return;
}

G4Material* ENUTAG_Construction::Material(std::string materialName){
    G4NistManager *nist = G4NistManager::Instance();
    //map
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
        {"vacuum", my_vacuum},
        {"ENUTAG_graphite", my_graphite}
    };
    return materials[materialName];
}

G4VPhysicalVolume *ENUTAG_Construction::Construct(){
    
    //WORLD

    G4cout << "Generating world..." << G4endl;

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

    //define rotations before placing

    G4cout << "Defining rotations..." << G4endl;

    DefineRotations();
    
    //PLACING...

    G4cout << "Placing elements..." << G4endl;

    DoQuadrupole(1,logicWorld);
    DoQuadrupole(2,logicWorld);
    DoQuadrupole(3,logicWorld);
    DoDipole(1,logicWorld);
    DoDipole(2,logicWorld);
    DoQuadrupole(5,logicWorld);
    DoEC(1,logicWorld);
    DoEC(2,logicWorld);
    DoDipole(3,logicWorld);
    DoDipole(4,logicWorld);
    DoEC(3,logicWorld);
    DoQuadrupole(6,logicWorld);
    DoEC(4,logicWorld);
    DoQuadrupole(8,logicWorld);
    DoEC(5,logicWorld);
    DoQuadrupole(9,logicWorld);
    DoEC(6,logicWorld);

    DoDrifts(logicWorld);
    DoTarget(logicWorld);
    DoDetectors(logicWorld);
    DoShielding(logicWorld);

    G4cout << "...done!" << G4endl;

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

void ENUTAG_Construction::DoDipole(G4int dipoleNumber, G4LogicalVolume* lWorld){

    //parameters
    G4double dipoleInnerRadius;
    G4double dipoleOuterRadius;
    G4double dipoleDeg;
    G4double dipoleX;
    G4double dipoleY;
    G4double dipoleZ;
    G4double dipoleHeight;

    switch(dipoleNumber){
        case 1:{
            dipoleInnerRadius = dipole1InnerRadius;
            dipoleOuterRadius = dipole1OuterRadius;
            dipoleDeg = dipole1Deg;
            dipoleX = dipole1X;
            dipoleY = dipole1Y;
            dipoleZ = dipole1Z;
            dipoleHeight = dipole1Height;
            break;}
        case 2:{
            dipoleInnerRadius = dipole2InnerRadius;
            dipoleOuterRadius = dipole2OuterRadius;
            dipoleDeg = dipole2Deg;
            dipoleX = dipole2X;
            dipoleY = dipole2Y;
            dipoleZ = dipole2Z;
            dipoleHeight = dipole2Height;
            break;}
        case 3:{
            dipoleInnerRadius = dipole3InnerRadius;
            dipoleOuterRadius = dipole3OuterRadius;
            dipoleDeg = dipole3Deg;
            dipoleX = dipole3X;
            dipoleY = dipole3Y;
            dipoleZ = dipole3Z;
            dipoleHeight = dipole3Height;
            break;}
        case 4:{
            dipoleInnerRadius = dipole4InnerRadius;
            dipoleOuterRadius = dipole4OuterRadius;
            dipoleDeg = dipole4Deg;
            dipoleX = dipole4X;
            dipoleY = dipole4Y;
            dipoleZ = dipole4Z;
            dipoleHeight = dipole4Height;
            break;}
        default:{
            dipoleInnerRadius = 0.;
            dipoleOuterRadius = 0.;
            dipoleDeg = 0.;
            dipoleX = 0.;
            dipoleY = 0.;
            dipoleZ = 0.;
            dipoleHeight = 0.;
            break;}
    }

    //solid parts
    G4Tubs *solidDipoleup = new G4Tubs("solidDipoleup",dipoleInnerRadius,dipoleOuterRadius,dipoleThickness,90.*deg - (dipoleNumber * dipoleDeg),dipoleDeg);
    G4Tubs *solidDipoledown = new G4Tubs("solidDipoledown",dipoleInnerRadius,dipoleOuterRadius,dipoleThickness,90.*deg - (dipoleNumber * dipoleDeg),dipoleDeg);

    G4LogicalVolume *logicDipoleup = new G4LogicalVolume(solidDipoleup, Material("copper"), "logicDipoleup");
    G4LogicalVolume *logicDipoledown = new G4LogicalVolume(solidDipoledown, Material("copper"), "logicDipoledown");

    //magnetic field
    G4Tubs *solidDipoleField = new G4Tubs("solidDipoleField",dipoleInnerRadius,dipoleOuterRadius,dipoleHeight-dipoleThickness,90.*deg - (dipoleNumber * dipoleDeg),dipoleDeg);
    G4LogicalVolume *logicDipoleField = new G4LogicalVolume(solidDipoleField, Material("vacuum"), "logicDipoleField");
    G4UniformMagField *DipoleField = new G4UniformMagField(G4ThreeVector(0.,dipoleField*tesla,0.));
    G4FieldManager *DipoleFieldMgr = new G4FieldManager();
    DipoleFieldMgr->SetDetectorField(DipoleField);
    DipoleFieldMgr->CreateChordFinder(DipoleField);
    logicDipoleField->SetFieldManager(DipoleFieldMgr, true);

    //placement
    G4VPhysicalVolume *physDipoleup = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipoleX,dipoleY,dipoleZ),logicDipoleup,"physDipoleup",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipoledown = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipoleX,(-1)*dipoleY,dipoleZ),logicDipoledown,"physDipoledown",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDipoleField = new G4PVPlacement(DipoleRotation,G4ThreeVector(dipoleX,0.,dipoleZ),logicDipoleField,"physDipoleField",lWorld,false,checkOverlaps);

    G4cout << "Dipole " <<  dipoleNumber  << " built;" << G4endl;
    
    return;
}

void ENUTAG_Construction::DoQuadrupole(G4int quadrupoleNumber, G4LogicalVolume* lWorld){

    //parameters
    G4double quadrupoleRadius;
    G4double quadrupoleLength;
    G4double quadrupoleField;
    G4double quadX;
    G4double quadZ;
    G4RotationMatrix* rotation;

    switch(quadrupoleNumber){
        case 1:{
            quadrupoleRadius = quadrupole1Radius;
            quadrupoleLength = quadrupole1Length;
            quadrupoleField = quadrupole1Field;
            quadX = quad1X;
            quadZ = targetZ;
            rotation = TubeRotation;
            break;}
        case 2:{
            quadrupoleRadius = quadrupole2Radius;
            quadrupoleLength = quadrupole2Length;
            quadrupoleField = quadrupole2Field;
            quadX = quad2X;
            quadZ = targetZ;
            rotation = TubeRotation;
            break;}
        case 3:{
            quadrupoleRadius = quadrupole3Radius;
            quadrupoleLength = quadrupole3Length;
            quadrupoleField = quadrupole3Field;
            quadX = quad3X;
            quadZ = targetZ;
            rotation = TubeRotation;
            break;}
        case 5:{
            quadrupoleRadius = quadrupole5Radius;
            quadrupoleLength = quadrupole5Length;
            quadrupoleField = quadrupole5Field;
            quadX = quad5X;
            quadZ = quad5Z;
            rotation = NewTubeRotation;
            break;}
        case 6:{
            quadrupoleRadius = quadrupole6Radius;
            quadrupoleLength = quadrupole6Length;
            quadrupoleField = quadrupole6Field;
            quadX = quad6X;
            quadZ = quad6Z;
            rotation = NewNewTubeRotation;
            break;}
        case 8:{
            quadrupoleRadius = quadrupole8Radius;
            quadrupoleLength = quadrupole8Length;
            quadrupoleField = quadrupole8Field;
            quadX = quad8X;
            quadZ = quad8Z;
            rotation = NewNewTubeRotation;
            break;}
        case 9:{
            quadrupoleRadius = quadrupole9Radius;
            quadrupoleLength = quadrupole9Length;
            quadrupoleField = quadrupole9Field;
            quadX = quad9X;
            quadZ = quad9Z;
            rotation = NewNewTubeRotation;
            break;}
        default:{
            quadrupoleRadius = 1.;
            quadrupoleLength = 1.;
            quadrupoleField = 1.;
            quadX = 1.;
            quadZ = 1.;
            rotation = TubeRotation;
            break;}
    }
    //solid parts
    G4Tubs *solidQuadrupole = new G4Tubs("solidQuadrupole",quadrupoleRadius,quadrupoleRadius+quadrupoleThickness,quadrupoleLength,0.*deg,360.*deg);
    G4LogicalVolume *logicQuadrupole = new G4LogicalVolume(solidQuadrupole, Material("iron"), "logicQuadrupole");

    //magnetic field
    G4Tubs *solidQuadrupoleField = new G4Tubs("solidQuadrupole",0.,quadrupoleRadius,quadrupoleLength,0.*deg,360.*deg);
    G4LogicalVolume *logicQuadrupoleField = new G4LogicalVolume(solidQuadrupoleField, Material("vacuum"), "logicQuadrupoleField");
    G4QuadrupoleMagField *QuadField = new G4QuadrupoleMagField( (quadrupoleField/PRHO) * tesla/(1.*m));
    G4FieldManager *QuadrupoleFieldMgr = new G4FieldManager();
    QuadrupoleFieldMgr->SetDetectorField(QuadField);
    QuadrupoleFieldMgr->CreateChordFinder(QuadField);
    logicQuadrupoleField->SetFieldManager(QuadrupoleFieldMgr, true);

    //placement
    G4VPhysicalVolume *physQuadrupole = new G4PVPlacement(rotation,G4ThreeVector(quadX,0.,quadZ),logicQuadrupole,"physQuadrupole",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physQuadrupoleField = new G4PVPlacement(rotation,G4ThreeVector(quadX,0.,quadZ),logicQuadrupoleField,"physQuadrupoleField",lWorld,false,checkOverlaps);

    G4cout << "Quadrupole " <<  quadrupoleNumber  << " built;" << G4endl;

    return;
}

void ENUTAG_Construction::DoEC(G4int ECNumber, G4LogicalVolume* lWorld){

    //parameters
    G4double ECSide;
    G4double ECThickness;
    G4double ECholeX;
    G4double ECholeY;
    G4double ECX;
    G4double ECZ;
    G4RotationMatrix* rotation;

    switch(ECNumber){
        case 1:{
            ECSide = EC1Side;
            ECThickness = EC1Thickness;
            ECholeX = EC1holeX;
            ECholeY = EC1holeY;
            ECX = EC1X;
            ECZ = EC1Z;
            rotation = NewTubeRotation;
            break;
        }
        case 2:{
            ECSide = EC2Side;
            ECThickness = EC2Thickness;
            ECholeX = EC2holeX;
            ECholeY = EC2holeY;
            ECX = EC2X;
            ECZ = EC2Z;
            rotation = NewTubeRotation;
            break;
        }
        case 3:{
            ECSide = EC3Side;
            ECThickness = EC3Thickness;
            ECholeX = EC3holeX;
            ECholeY = EC3holeY;
            ECX = EC3X;
            ECZ = EC3Z;
            rotation = NewNewTubeRotation;
            break;
        }
        case 4:{
            ECSide = EC3Side;
            ECThickness = EC3Thickness;
            ECholeX = EC3holeX;
            ECholeY = EC3holeY;
            ECX = EC4X;
            ECZ = EC4Z;
            rotation = NewNewTubeRotation;
            break;
        }
        case 5:{
            ECSide = EC3Side;
            ECThickness = EC3Thickness;
            ECholeX = EC3holeX;
            ECholeY = EC3holeY;
            ECX = EC5X;
            ECZ = EC5Z;
            rotation = NewNewTubeRotation;
            break;
        }
        case 6:{
            ECSide = EC6Side;
            ECThickness = EC6Thickness;
            ECholeX = EC6holeX;
            ECholeY = EC6holeY;
            ECX = EC6X;
            ECZ = EC6Z;
            rotation = NewNewTubeRotation;
            break;
        }
        default:{

            break;
        }
    }
    //solid parts
    G4Box *firstECBlock = new G4Box("solidECBlock",ECSide,ECSide,ECThickness);
    G4EllipticalTube *subtractECBlock = new G4EllipticalTube("solidSubtractEC",ECholeX,ECholeY,ECThickness+2);
    G4SubtractionSolid *solidEC = new G4SubtractionSolid("solidEC",firstECBlock,subtractECBlock);
    G4LogicalVolume *logicEC = new G4LogicalVolume(solidEC, Material("tungsten"), "logicEC");
    //placement
    G4VPhysicalVolume *physEC = new G4PVPlacement(rotation,G4ThreeVector(ECX,0.,ECZ),logicEC,"physEC",lWorld,false,checkOverlaps);

    G4cout << "Collimator " <<  ECNumber  << " built;" << G4endl;

    return;
}

void ENUTAG_Construction::DoDrifts(G4LogicalVolume* lWorld){

    //SOLID
    //drift1
    G4Tubs *solidDrift1 = new G4Tubs("solidDrift1",driftRadius,driftRadius+driftThick,drift1Length,0.*deg,360*deg);
    //drift2
    G4Tubs *solidDrift2 = new G4Tubs("solidDrift2",driftRadius,driftRadius+driftThick,drift2Length,0.*deg,360*deg);
    //drift3
    G4Tubs *solidDrift3 = new G4Tubs("solidDrift3",driftRadius,driftRadius+driftThick,drift3Length,0.*deg,360*deg);
    //drift4
    G4Tubs *solidDrift4 = new G4Tubs("solidDrift4",driftRadius,driftRadius+driftThick,drift4Length,0.*deg,360*deg);
    //driftDipole1
    G4Tubs *solidDriftDipole1 = new G4Tubs("solidDriftDipole1",driftRadius,driftRadius+driftThick,driftDipole1Length,0.*deg,360*deg);
    //drift5
    G4Tubs *solidDrift5 = new G4Tubs("solidDrift5",driftRadius,driftRadius+driftThick,drift5Length,0.*deg,360*deg);
    //drift6
    G4Tubs *solidDrift6 = new G4Tubs("solidDrift6",driftRadius,driftRadius+driftThick,drift6Length,0.*deg,360*deg);
    //driftDipole2
    G4Tubs *solidDriftDipole2 = new G4Tubs("solidDriftDipole2",driftRadius,driftRadius+driftThick,driftDipole2Length,0.*deg,360*deg);
    //drift7
    G4Tubs *solidDrift7 = new G4Tubs("solidDrift7",driftRadius,driftRadius+driftThick,drift7Length,0.*deg,360*deg);
    //drift8
    G4Tubs *solidDrift8 = new G4Tubs("solidDrift8",driftRadius,driftRadius+driftThick,drift8Length,0.*deg,360*deg);
    //drift9
    G4Tubs *solidDrift9 = new G4Tubs("solidDrift9",driftRadius,driftRadius+driftThick,drift9Length,0.*deg,360*deg);
    //driftBuff
    G4Tubs *solidDriftBUFF = new G4Tubs("solidDriftBUFF",driftBUFFRadius,driftBUFFRadius+driftThick,driftBUFFLength,0.*deg,360*deg);
    //driftDecay
    G4Tubs *solidDriftDecay = new G4Tubs("solidDriftDecay",driftDecayRadius,driftDecayRadius+driftThick,driftDecayLength,0.*deg,360*deg);

    //LOGIC
    G4LogicalVolume *logicDrift1 = new G4LogicalVolume(solidDrift1, Material("iron"), "logicDrift1");
    G4LogicalVolume *logicDrift2 = new G4LogicalVolume(solidDrift2, Material("iron"), "logicDrift2");
    G4LogicalVolume *logicDrift3 = new G4LogicalVolume(solidDrift3, Material("iron"), "logicDrift3");
    G4LogicalVolume *logicDrift4 = new G4LogicalVolume(solidDrift4, Material("iron"), "logicDrift4");
    G4LogicalVolume *logicDriftDipole1 = new G4LogicalVolume(solidDriftDipole1, Material("iron"), "logicDriftDipole1");
    G4LogicalVolume *logicDrift5 = new G4LogicalVolume(solidDrift5, Material("iron"), "logicDrift5");
    G4LogicalVolume *logicDrift6 = new G4LogicalVolume(solidDrift6, Material("iron"), "logicDrift6");
    G4LogicalVolume *logicDriftDipole2 = new G4LogicalVolume(solidDriftDipole2, Material("iron"), "logicDriftDipole2");
    G4LogicalVolume *logicDrift7 = new G4LogicalVolume(solidDrift7, Material("iron"), "logicDrift7");
    G4LogicalVolume *logicDrift8 = new G4LogicalVolume(solidDrift8, Material("iron"), "logicDrift8");
    G4LogicalVolume *logicDrift9 = new G4LogicalVolume(solidDrift9, Material("iron"), "logicDrift9");
    G4LogicalVolume *logicDriftBUFF = new G4LogicalVolume(solidDriftBUFF, Material("iron"), "logicDriftBUFF");
    G4LogicalVolume *logicDriftDecay = new G4LogicalVolume(solidDriftDecay, Material("iron"), "logicDriftDecay");

    //PHYS
    G4VPhysicalVolume *physDrift1 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift1X,0.,0.),logicDrift1,"physDrift1",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift2 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift2X,0.,0.),logicDrift2,"physDrift2",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift3 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift3X,0.,0.),logicDrift3,"physDrift3",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift4 = new G4PVPlacement(TubeRotation,G4ThreeVector(drift4X,0.,0.),logicDrift4,"physDrift4",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDriftDipole1 = new G4PVPlacement(driftDipole11Rotation,G4ThreeVector(driftDipole1X,0.,driftDipole1Z),logicDriftDipole1,"physDriftDipole1",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift5 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(drift5X,0.,drift5Z),logicDrift5,"physDrift5",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift6 = new G4PVPlacement(NewTubeRotation,G4ThreeVector(drift6X,0.,drift6Z),logicDrift6,"physDrift6",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDriftDipole2 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(driftDipole2X,0.,driftDipole2Z),logicDriftDipole2,"physDriftDipole2",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift7 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(drift7X,0.,drift7Z),logicDrift7,"physDrift7",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift8 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(drift8X,0.,drift8Z),logicDrift8,"physDrift8",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDrift9 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(drift9X,0.,drift9Z),logicDrift9,"physDrift9",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDriftBUFF = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(driftBUFFX,0.,driftBUFFZ),logicDriftBUFF,"physDriftBUFF",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physDriftDecay = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(driftDecayX,0.,driftDecayZ),logicDriftDecay,"physDriftDecay",lWorld,false,checkOverlaps);

    G4cout << "Drifts built;" << G4endl;

    return;
};

void ENUTAG_Construction::DoTarget(G4LogicalVolume* lWorld){

    //SOLID
    G4Tubs *solidTarget = new G4Tubs("solidTarget",0.,targetDiameter,thicknessTarget,0.*deg,360.*deg);
    //steel around target
    G4Box *solidTargetBlock = new G4Box("solidTargetBlock",targetBlockLength,2.*targetBlockSize,targetBlockSize);

    //LOGIC
    /*if(mode=="pion"){targetMaterial=Material("vacuum");}
    else{targetMaterial=Material("ENUTAG_graphite");}*/
    G4LogicalVolume *logicTarget = new G4LogicalVolume(solidTarget, Material("graphite"), "logicTarget");
    G4LogicalVolume *logicTargetBlock = new G4LogicalVolume(solidTargetBlock, Material("iron"), "logicTargetBlock");
    
    //PHYS
    G4VPhysicalVolume *physTarget = new G4PVPlacement(TubeRotation,G4ThreeVector(targetX,targetY,targetZ),logicTarget,"physTarget",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physTargetBlock1 = new G4PVPlacement(0,G4ThreeVector(targetBlock1X,targetBlock1Y,targetBlock1Z),logicTargetBlock,"physTargetBlock1",lWorld,false,checkOverlaps);
    G4VPhysicalVolume *physTargetBlock2 = new G4PVPlacement(0,G4ThreeVector(targetBlock2X,targetBlock2Y,targetBlock2Z),logicTargetBlock,"physTargetBlock2",lWorld,false,checkOverlaps);

    G4cout << "Target built;" << G4endl;

    return;
};

void ENUTAG_Construction::DoDetectors(G4LogicalVolume* lWorld){

    //SOLID
    //Silicon
    G4Tubs *solidSilicon = new G4Tubs("solidSilicon",0.,SiRadius,SiThickness,0.*deg,360*deg);
    //downstream virtual detectors
    G4Tubs *solidDSVD = new G4Tubs("solidDSVD",0.,driftDecayRadius,SiThickness,0.*deg,360.*deg);
    G4Tubs *solidUSVD = new G4Tubs("solidUSVD",0.,driftRadius,SiThickness,0.*deg,360.*deg);

    //LOGIC
    logicDetector1 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector1");
    logicDetector2 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector2");
    logicDetector3 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector3");
    logicDetector4 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector4");
    logicDetector5 = new G4LogicalVolume(solidSilicon,Material("silicon"),"logicDetector5");
    logicDSVD1 = new G4LogicalVolume(solidDSVD,Material("vacuum"),"logicDSVD1");
    logicDSVD2 = new G4LogicalVolume(solidDSVD,Material("vacuum"),"logicDSVD2");
    logicUSVD = new G4LogicalVolume(solidUSVD,Material("vacuum"),"logicUSVD");

    //PHYS
    G4VPhysicalVolume *physDetector1 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(silicon1X,0.,silicon1Z),logicDetector1,"physDetector1",lWorld,false,checkOverlaps,1);
    G4VPhysicalVolume *physDetector2 = new G4PVPlacement(driftDipole22Rotation,G4ThreeVector(silicon2X,0.,silicon2Z),logicDetector2,"physDetector2",lWorld,false,checkOverlaps,2);
    G4VPhysicalVolume *physDetector3 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon3X,0.,silicon3Z),logicDetector3,"physDetector3",lWorld,false,checkOverlaps,3);
    G4VPhysicalVolume *physDetector4 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon4X,0.,silicon4Z),logicDetector4,"physDetector4",lWorld,false,checkOverlaps,4);
    G4VPhysicalVolume *physDetector5 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(silicon5X,0.,silicon5Z),logicDetector5,"physDetector5",lWorld,false,checkOverlaps,5);
    G4VPhysicalVolume *physDSVD1 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(DSVD1X,0.,DSVD1Z),logicDSVD1,"physDSVD1",lWorld,false,checkOverlaps,6);
    G4VPhysicalVolume *physDSVD2 = new G4PVPlacement(NewNewTubeRotation,G4ThreeVector(DSVD2X,0.,DSVD2Z),logicDSVD2,"physDSVD2",lWorld,false,checkOverlaps,7);
    G4VPhysicalVolume *physUSVD = new G4PVPlacement(TubeRotation,G4ThreeVector(USVDX,0.,USVDZ),logicUSVD,"physUSVD",lWorld,false,checkOverlaps,8);
    
    G4cout << "Detectors built;" << G4endl;

    return;
};

void ENUTAG_Construction::DoShielding(G4LogicalVolume* lWorld){

    //SOLID
    //concrete blocks
    G4Box *solidConcreteST = new G4Box("solidConcreteST",concreteLength,2.*concreteSTwidth,concreteSTwidth);
    //G4Box *solidConcreteUT = new G4Box("solidConcreteUT",concreteLength,concreteUTwidth,concreteUTwidth);
    G4Box *solidConcreteFT = new G4Box("solidConcreteFT",concreteLength,concreteFTheight,concreteFTwidth);
    G4Box *solidConcrete1 = new G4Box("solidConcreteFT",concrete1Length,concreteFTheight,concreteFTwidth);
    G4Box *solidConcrete2 = new G4Box("solidConcreteFT",concrete2Length,concreteFTheight,concreteFTwidth);

    /*G4Box *solidConcreteBig1 = new G4Box("solidConcreteFT",concreteBigLength,concreteBigWidth1,concreteBigWidth1);
    G4Box *solidConcreteBig2 = new G4Box("solidConcreteFT",concreteBigLength,concreteBigWidth2,concreteBigWidth2);*/

    G4Tubs *solidConcreteD1 = new G4Tubs("solidConcreteD1",CD1InnerRadius,CD1OuterRadius,concreteFTheight,90. * deg - (2. * dipole1Deg),2. * dipole1Deg);
    G4Tubs *solidConcreteD2 = new G4Tubs("solidConcreteD2",CD2InnerRadius,CD2OuterRadius,concreteFTheight,90. * deg - (4. * dipole1Deg),2. * dipole1Deg);

    //LOGIC
    G4LogicalVolume *logicConcreteST = new G4LogicalVolume(solidConcreteST,Material("concrete"),"logicConcreteST");
    //G4LogicalVolume *logicConcreteUT = new G4LogicalVolume(solidConcreteUT,Material("concrete"),"logicConcreteUT");
    G4LogicalVolume *logicConcreteFT = new G4LogicalVolume(solidConcreteFT,Material("concrete"),"logicConcreteFT");
    G4LogicalVolume *logicConcreteD1 = new G4LogicalVolume(solidConcreteD1,Material("concrete"),"logicConcreteD1");
    G4LogicalVolume *logicConcrete1 = new G4LogicalVolume(solidConcrete1,Material("concrete"),"logicConcrete1");
    G4LogicalVolume *logicConcreteD2 = new G4LogicalVolume(solidConcreteD2,Material("concrete"),"logicConcreteD2");
    G4LogicalVolume *logicConcrete2 = new G4LogicalVolume(solidConcrete2,Material("concrete"),"logicConcrete2");

    /*G4LogicalVolume *logicConcreteBig1 = new G4LogicalVolume(solidConcreteBig1,Material("concrete"),"logicConcreteBig1");
    G4LogicalVolume *logicConcreteBig2 = new G4LogicalVolume(solidConcreteBig2,Material("concrete"),"logicConcreteBig2");*/

    //PHYS
    G4PVPlacement *physRTConcrete = new G4PVPlacement(0,G4ThreeVector(rtX,rtY,rtZ),logicConcreteST,"physRTConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physLTConcrete = new G4PVPlacement(0,G4ThreeVector(ltX,ltY,ltZ),logicConcreteST,"physLTConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physUTConcrete = new G4PVPlacement(0,G4ThreeVector(utX,utY,utZ),logicConcreteFT,"physUTConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physFTConcrete = new G4PVPlacement(0,G4ThreeVector(ftX,ftY,ftZ),logicConcreteFT,"physFTConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physD1upConcrete = new G4PVPlacement(DipoleRotation,G4ThreeVector(D1X,utY,D1Z),logicConcreteD1,"physD1upConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physD1dnConcrete = new G4PVPlacement(DipoleRotation,G4ThreeVector(D1X,ftY,D1Z),logicConcreteD1,"physD1dnConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcrete1up = new G4PVPlacement(Concrete1Rotation,G4ThreeVector(concrete1X,utY,concrete1Z),logicConcrete1,"physConcrete1up",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcrete1dn = new G4PVPlacement(Concrete1Rotation,G4ThreeVector(concrete1X,ftY,concrete1Z),logicConcrete1,"physConcrete1dn",lWorld,false,checkOverlaps);
    G4PVPlacement *physD2upConcrete = new G4PVPlacement(DipoleRotation,G4ThreeVector(D2X,utY,D2Z),logicConcreteD2,"physD2upConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physD2dnConcrete = new G4PVPlacement(DipoleRotation,G4ThreeVector(D2X,ftY,D2Z),logicConcreteD2,"physD2dnConcrete",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcrete2up = new G4PVPlacement(Concrete2Rotation,G4ThreeVector(concrete2X,utY,concrete2Z),logicConcrete2,"physConcrete2up",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcrete2dn = new G4PVPlacement(Concrete2Rotation,G4ThreeVector(concrete2X,ftY,concrete2Z),logicConcrete2,"physConcrete2dn",lWorld,false,checkOverlaps);

    /*G4PVPlacement *physConcreteBigUpper1 = new G4PVPlacement(BigConcrete1Rotation,G4ThreeVector(bigUpper1X,bigUpper1Y,bigUpper1Z),logicConcreteBig1,"physConcreteBigUpper1",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcreteBigLower1 = new G4PVPlacement(BigConcrete1Rotation,G4ThreeVector(bigLower1X,bigLower1Y,bigLower1Z),logicConcreteBig1,"physConcreteBigLower1",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcreteBigUpper2 = new G4PVPlacement(BigConcrete1Rotation,G4ThreeVector(bigUpper2X,bigUpper2Y,bigUpper2Z),logicConcreteBig2,"physConcreteBigUpper2",lWorld,false,checkOverlaps);
    G4PVPlacement *physConcreteBigLower2 = new G4PVPlacement(BigConcrete1Rotation,G4ThreeVector(bigLower2X,bigLower2Y,bigLower2Z),logicConcreteBig2,"physConcreteBigLower2",lWorld,false,checkOverlaps);
*/
    G4cout << "Shieldings built;" << G4endl;

    return;
};