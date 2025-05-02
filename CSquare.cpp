#include "CSquare.h"

CSquare::CSquare(Point P, int s, GfxInfo FigureGfxInfo) :
    CFigure(FigureGfxInfo), P1(P), side(s) {}

Point CSquare::getPosition() const {
    return P1;
}

void CSquare::setPosition(Point newCenter) 
{
    P1 = newCenter;
}

void CSquare::Draw(Output* pOut) const 
{
    Point topLeft = { P1.x - side / 2, P1.y - side / 2 };
    Point bottomRight = { P1.x + side / 2, P1.y + side / 2 };
    pOut->DrawRect(topLeft, bottomRight, FigGfxInfo, Selected);
}

bool CSquare::Contains(Point point) const {
    return (point.x >= P1.x - side / 2) && (point.x <= P1.x + side / 2) &&
        (point.y >= P1.y - side / 2) && (point.y <= P1.y + side / 2);
}