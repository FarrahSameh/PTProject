#pragma once
#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Actions/Action.h"

//Add Square Action class
class AddSqrAction : public Action
{
private:
	Point P1;
	int side = 100;

	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

};

#endif