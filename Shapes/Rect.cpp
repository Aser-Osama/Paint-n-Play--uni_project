#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{


	ShpGfxInfo.ShapeType="Rectangle";
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect(){}
//
//Point Rect::getBorders() {
//	return Corner1;
//}

string Rect::GetShapeType() const{
	return "RECT";
}
void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

void Rect::Save(ofstream &outfile){
	outfile<<Corner1.x<<"\t"<<Corner1.y<<"\t"<<Corner2.x<<"\t"<<Corner2.y<<"\t";
}	//Save the shape parameters to the file

bool Rect::isInside(int x, int y) const {
	return((x <= max(Corner1.x, Corner2.x)) && (y <= max(Corner1.y, Corner2.y)) && (x >= min(Corner1.x, Corner2.x)) && (y >= min(Corner1.y, Corner2.y)));
}