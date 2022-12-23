#pragma once

#include "operation.h"
#include "..\GUI\GUI.h"
#include "..\Shapes\Graph.h"
//Add Rectangle operation class
class opDrag : public operation
{
Point movePoint;
vector<shape*> selShapes;
int count=0;
public:
	opDrag(controller* pCont);
	virtual ~opDrag();
	//Add copy to the controller
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
