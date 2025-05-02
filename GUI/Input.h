#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration
class Point;    // forward declaration
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action

	//--------------------------implementation of swap function: 
	//getting indices of two selected figures
	void getTwoSelectedFigures(int& indx1, int& indx2);
	//checking the point is within the figure
	bool isPointInFigure(int findx,  Point& pt);


	~Input();
};

#endif