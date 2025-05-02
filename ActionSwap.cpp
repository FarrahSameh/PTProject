#include "ActionSwap.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"

using namespace std;

ActionSwap::ActionSwap(ApplicationManager* pApp) : Action(pApp) {}

void ActionSwap::ReadActionParameters() {}

void ActionSwap::Execute() 
{
    pManager->executeSwap();
}