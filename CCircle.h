#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Figures/CFigure.h"

class CCircle : public CFigure 
{
private:
    Point p1, edge;

public:
    CCircle(Point, Point, GfxInfo CirGfxInfo);
    virtual Point getPosition() const ;
    virtual void setPosition(Point point) ;
    virtual void Draw(Output* pOut) const override;
    virtual bool Contains(Point point) const ;
    int getRadius() const;
};

#endif