#pragma once
#include "operation.h"

class opDeleteShape : public operation{
public:
  opDeleteShape(controller *pCont);
  virtual ~opDeleteShape();
  virtual void Excute() = 0;
};
