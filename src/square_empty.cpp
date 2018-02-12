#include "square_empty.h"

#include "screen.h"

/// *** PUBLIC *** ///
SquareEmpty::SquareEmpty(const String& text) : Square(text) { }

// A nothing-card does nothing, logical(?)
void SquareEmpty::Do(Gameboard& gameboard) 
{
  screen::Wait(); 
}