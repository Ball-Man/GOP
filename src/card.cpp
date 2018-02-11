#include "card.h"
#include "gameboard.h"

/// *** PUBLIC *** ///
Card::Card(const String& text)
{
  text_ = text;
}

const String& Card::Text() const { return text_; }