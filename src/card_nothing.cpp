#include "card_nothing.h"

/// *** PUBLIC *** ///
CardNothing::CardNothing(const String& text) : Card(text) { }

// A nothing-card does nothing, logical(?)
void CardNothing::Do(Gameboard& gameboard) { }