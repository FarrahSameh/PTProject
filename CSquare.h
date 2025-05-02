#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H

#include "Figures/CFigure.h"

class CSquare : public CFigure 
{
private:
    Point P1;
    int side;

public:
    CSquare(Point, int, GfxInfo SqrGfxInfo);
    virtual Point getPosition() const ;
    virtual void setPosition(Point point) ;
    virtual void Draw(Output* pOut) const override;
    virtual bool Contains(Point point) const ;
};

#endif