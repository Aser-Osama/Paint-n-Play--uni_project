#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddLine.h"
#include "operations\opExit.h"
#include "operations\opAddTri.h"
#include "operations\opAddCirc.h"
#include "operations\opAddSquare.h"
#include "operations\OpAddOval.h"
#include "operations\opSave.h"
#include "operations\opLoad.h"
#include "operations\opSelect.h"
#include "operations\opAddiPoly.h"
#include "operations\opAddrPoly.h"
#include "operations\opDeleteShape.h"

//Constructor
controller::controller()
{
	pGr = new Graph;
	pUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;

		case DRAW_TRI:
			pOp = new opAddTri(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCirc(this);
			break;
		case DRAW_SQUARE:
			pOp = new opAddSquare(this);
				break;
		case DRAW_OVAL:
			pOp = new opAddOval(this);
			break;
		case DRAW_IPOLY:
			pOp = new opAddiPoly(this);
			break;
		case DRAW_RPOLY:
			pOp = new opAddrPoly(this);
			break;
		case DRAWING_AREA:
			pOp = new opSelect(this);
			break;
		case DELETE_SHAPE:
			pOp = new opDeleteShape(this);
			break;
		case LOAD:
			///create load operation
			//pOp = new opLoad(this);
			break;	

		case SAVE:
			
			pOp = new opSave(this); //create save operation 
			break;

		case EXIT:
			///create Exitoperation here
			pOp = new opExit(this); 
			break;

		case STATUS:	//a click on the status bar ==> no operation
			break;

	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGr->Draw(pUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGr;
}



//Destructor
controller::~controller()
{
	delete pUI;
	delete pGr;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}
