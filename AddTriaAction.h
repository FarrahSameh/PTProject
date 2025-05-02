#ifndef ADD_TRIA_ACTION_H
#define ADD_TRIA_ACTION_H

#include "Actions/Action.h"

//Add Triangle Action class
class AddTriaAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriaGfxInfo;
public:
	AddTriaAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif

