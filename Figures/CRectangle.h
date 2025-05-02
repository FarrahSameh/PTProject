#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo RectGfxInfo);
	virtual void Draw(Output* pOut) const override;
	virtual bool Contains(Point point) const override;
	virtual Point getPosition() const;
	virtual void setPosition(Point point);
};

#endif