#ifndef GOP_CARD_H_
#define GOP_CARD_H_

#include "sstring.h"

class Gameboard;

// The card class is an abstract class used as model
// by the inheriting Card classes. The constructor
// is there for inheritance matter.
class Card
{
 public:
  Card(const String& text);

  virtual void Do(Gameboard& gameboard) = 0;   // Abstract method

  const String& Text() const;

 protected:
  String text_;
};

#endif