#ifndef ENUTAG_ACTIONINITIALIZATION_HH
#define ENUTAG_ACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "ENUTAG_PrimaryGenerator.hh"
#include "ENUTAG_RunAction.hh"

class ENUTAG_ActionInitialization : public G4VUserActionInitialization
{
public:
    ENUTAG_ActionInitialization();
    ~ENUTAG_ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif