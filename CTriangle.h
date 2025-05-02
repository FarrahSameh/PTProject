#ifndef CTRIA_H
#define CTRIA_H

#include "Figures/CFigure.h"
#include "GUI/Input.h"

class CTriangle : public CFigure
{
private:
    Point Corner1;
    Point Corner2;
    Point Corner3;
public:
    CTriangle(Point, Point, Point, GfxInfo TriaGfxInfo);
    virtual void Draw(Output* pOut) const override;
    virtual bool Contains(Point point) const;
    virtual Point getPosition() const;
    virtual void setPosition(Point point);
};

#endif