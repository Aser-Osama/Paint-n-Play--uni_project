#include "Tri.h"

Tri::Tri(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{

	ShpGfxInfo.ShapeType="Tri";
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Tri::~Tri()
{}

void Tri::Draw(GUI* pUI) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	pUI->DrawTri(Corner1, Corner2, Corner3, ShpGfxInfo);
}

void Square::Save(ofstream &outfile){
	outfile<<Corner1<<"\t"<<Corner2<<"\t"<<Corner3<<"\t";
}	//Save the shape parameters to the file
