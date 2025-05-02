#pragma once
#ifndef ADD_CIR_ACTION_H
#define ADD_CIR_ACTION_H

#include "Actions/Action.h"

//Add Circle Action class
class AddCirAction : public Action
{
private:
	Point P1, P2; 

	GfxInfo CirGfxInfo;
public:
	AddCirAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

};

#endif