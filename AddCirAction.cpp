#include "AddCirAction.h"
#include "CCircle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


AddCirAction::AddCirAction(ApplicationManager* pApp) :Action(pApp) {}

void AddCirAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);


	CirGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CirGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CirGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCirAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CirGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}
//bhh