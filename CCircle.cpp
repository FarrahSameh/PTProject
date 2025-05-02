#include "CCircle.h"
#include <math.h>

CCircle::CCircle(Point c, Point e, GfxInfo FigGfxInfo) :
    CFigure(FigGfxInfo), p1(c), edge(e) {}

Point CCircle::getPosition() const 
{
    return p1;
}

void CCircle::setPosition(Point newCenter) {
    int dx = newCenter.x - p1.x;
    int dy = newCenter.y - p1.y;
    p1 = newCenter;
    edge.x += dx;
    edge.y += dy;
}

int CCircle::getRadius() const {
    int dx = edge.x - p1.x;
    int dy = edge.y - p1.y;
    return static_cast<int>(sqrt(dx * dx + dy * dy));
}

void CCircle::Draw(Output* pOut) const {
    pOut->DrawCircle(p1, getRadius(), FigGfxInfo, Selected);
}

bool CCircle::Contains(Point point) const 
{
    int dx = point.x - p1.x;
    int dy = point.y - p1.y;
    return (dx * dx + dy * dy) <= (getRadius() * getRadius());
}