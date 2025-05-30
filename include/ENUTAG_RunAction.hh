#ifndef ENUTAG_RUNACTION_HH
#define ENUTAG_RUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class ENUTAG_RunActionMessenger;

class ENUTAG_RunAction : public G4UserRunAction{
public:
    ENUTAG_RunAction();
    ~ENUTAG_RunAction();

    virtual void BeginOfRunAction(const G4Run *);
    virtual void EndOfRunAction(const G4Run *);

    void DefineFileName(G4String);

private:
    G4AnalysisManager *analysisManager;
    ENUTAG_RunActionMessenger* fMessenger;
    G4String fileName;
    void NTupleCreate(G4String);
    void DefineFile();
};

#endif