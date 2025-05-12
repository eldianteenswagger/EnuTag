#ifndef ENUTAG_EVENTACTION_HH
#define ENUTAG_EVENTACTION_HH

#include"G4UserEventAction.hh"
#include"G4Event.hh"
#include"ENUTAG_RunAction.hh"

class ENUTAG_EventAction : public G4UserEventAction{
private:
    G4int nEvent;
public:
    ENUTAG_EventAction(ENUTAG_RunAction*);
    ~ENUTAG_EventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    //void incrementCounter();
    //void printCounter();
};

#endif