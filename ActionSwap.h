#ifndef ACTIONSWAP_H
#define ACTIONSWAP_H

#include "Actions/Action.h"

class ActionSwap : public Action 
{
public:
    ActionSwap(ApplicationManager* pApp);

    virtual void Execute();
    virtual void ReadActionParameters();
};

#endif
