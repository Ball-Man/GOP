#include "square_empty.h"

/// *** PUBLIC *** ///
SquareEmpty::SquareEmpty(const String& text) : Square(text) { }

// A nothing-card does nothing, logical(?)
void SquareEmpty::Do(Gameboard& gameboard) { }