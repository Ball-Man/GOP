#ifndef GOP_SQAURE_EMPTY_H_
#define GOP_SQAURE_EMPTY_H_

#include "square.h"

class SquareEmpty : public Square
{
 public:
  SquareEmpty(const String& name);

  void Do(Gameboard& gameboard) const;
  
};

#endif