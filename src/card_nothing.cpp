#include "card_nothing.h"

#include "screen.h"

/// *** PUBLIC *** ///
CardNothing::CardNothing(const String& text) : Card(text) { }

// A nothing-card does nothing, logical(?)
void CardNothing::Do(Gameboard& gameboard) const
{
  screen::Wait(); 
}