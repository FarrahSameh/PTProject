#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle							
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	STATUS,
	DRAW_CIRCLE,
	TO_SELECT,
	TO_SWAP,
	TO_ROTATE,
	TO_CHANGE_TO_BLACK,
	TO_CHANGE_TO_YELLOW,
	TO_CHANGE_TO_ORANGE,
	TO_CHANGE_TO_RED,
	TO_CHANGE_TO_GREEN,
	TO_CHANGE_TO_BLUE,
	TO_DELETE_FIGURE,
	TO_CLEAR_ALL,
	TO_COPY,
	TO_CUT,
	TO_PASTE,
	TO_SAVE_GRAPH,
	TO_LOAD_GRAPH,
	TO_PLAY,       //Switch interface to Play mode
	EXIT,			//Exit				
	TO_DRAW,
	TO_Play_Missing_Figures,
	To_Match_Figures,
	TO_RESTART,
	PLAYING_AREA,
	DRAW_SQUARE

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ 
	int x,y; 
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif