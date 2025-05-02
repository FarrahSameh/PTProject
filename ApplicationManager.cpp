#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddTriaAction.h"
#include <string.h>
using namespace std;


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

//-------------------Implementation of swap function:

int ApplicationManager::getSelectedCount() const 
{
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] && FigList[i]->IsSelected()) {
			count++;
		}
	}
	return count;
}
void ApplicationManager::executeSwap() 
{
	int selectedCount = getSelectedCount();

	if (selectedCount != 2)
	{
		pOut->PrintMessage("Too many figures selected. Please select only two.");
		return;
	}
	// finding the two selected figures
	CFigure* figures[2] = { nullptr, nullptr };
	int found = 0;

	for (int i = 0; i < FigCount && found < 2; i++) 
	{
		if (FigList[i] && FigList[i]->IsSelected()) 
		{
			figures[found++] = FigList[i];
		}
	}

	if (figures[0] && figures[1]) 
	{
		// Swap positions
		Point p1 = figures[0]->getPosition();
		Point p2 = figures[1]->getPosition();

		figures[0]->setPosition(p2);
		figures[1]->setPosition(p1);

		pOut->PrintMessage("The figures have been swapped successfully!");
		pOut->UpdateInterface();
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
	ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
