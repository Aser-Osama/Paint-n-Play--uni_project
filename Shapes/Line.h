#pragma once
#include "Shape.h"
class Lines : public shape
{
private:
	Point End1;
	Point End2;
public:
	Lines(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Lines();
	virtual void Draw(GUI* pUI) const;
	//virtual void Save(ofstream &outfile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &infile) = 0;	//Load the shape parameters to the file



};

