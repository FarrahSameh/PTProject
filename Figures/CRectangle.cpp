#include "CRectangle.h"
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

Point CRectangle::getPosition() const 
{
    return Point((Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2); 
}

void CRectangle::setPosition(Point newCenter) 
{
    Point currentCenter = getPosition();
    int dx = newCenter.x - currentCenter.x;
    int dy = newCenter.y - currentCenter.y;

    Corner1.x += dx;
    Corner1.y += dy;
    Corner2.x += dx; 
    Corner2.y += dy;
}

bool CRectangle::Contains(Point point) const 
{
    return (point.x >= min(Corner1.x, Corner2.x)) && (point.x <= max(Corner1.x, Corner2.x)) &&
        (point.y >= min(Corner1.y, Corner2.y)) && (point.y <= max(Corner1.y, Corner2.y));
}