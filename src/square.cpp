#include "square.h"
#include "gameboard.h"

/// *** PUBLIC *** ///
Square::Square(const String& text)
{
  text_ = text;
}

const String& Square::Text() const { return text_; }