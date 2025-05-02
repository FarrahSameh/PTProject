#include "CTriangle.h"
#include "GUI/Input.h"
#include "Figures/CFigure.h"
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
    Corner1 = P1;
    Corner2 = P2;
    Corner3 = P3;
}

void CTriangle::Draw(Output* pOut) const 
{
    pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

Point CTriangle::getPosition() const 
{
    // Return centroid (average of all points)
    return Point((Corner1.x + Corner2.x + Corner3.x) / 3, (Corner1.y + Corner2.y + Corner3.y) / 3);
}

void CTriangle::setPosition(Point newCenter) 
{
    Point currentCenter = getPosition();
    int dx = newCenter.x - currentCenter.x;
    int dy = newCenter.y - currentCenter.y;

    Corner1.x += dx; 
    Corner1.y += dy;
    Corner2.x += dx; 
    Corner2.y += dy;
    Corner3.x += dx; 
    Corner3.y += dy;
}

bool CTriangle::Contains(Point point) const
{
    // Calculate barycentric coordinates
    float alpha = ((Corner2.y - Corner3.y) * (point.x - Corner3.x) + (Corner3.x - Corner2.x) * (point.y - Corner3.y));
    float beta = ((Corner3.y - Corner1.y) * (point.x - Corner3.x) + (Corner1.x - Corner3.x) * (point.y - Corner3.y));
    float gamma = 1.0f - alpha - beta;

    return alpha >= 0 && beta >= 0 && gamma >= 0;
}