#include "square_stop.h"
#include "gameboard.h"

#include "screen.h"

SquareStop::SquareStop(const String& text) : Square(text) { }

void SquareStop::Do(Gameboard& gameboard) const
{
  gameboard.Playing().SetStopped(true);
  screen::Wait();
}