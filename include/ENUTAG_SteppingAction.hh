#ifndef ENUTAG_STEPPINGACTION_HH
#define ENUTAG_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "ENUTAG_Construction.hh"
#include "ENUTAG_EventAction.hh"

class ENUTAG_SteppingAction : public G4UserSteppingAction {
public:
    ENUTAG_SteppingAction(ENUTAG_EventAction*);
    ~ENUTAG_SteppingAction();

    void UserSteppingAction(const G4Step*);

private:
    ENUTAG_EventAction* fEvtAction;
    G4double Emin;
};

#endif