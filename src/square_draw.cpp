#include "square_draw.h"
#include "gameboard.h"

#include "screen.h"
#include "card.h"

SquareDraw::SquareDraw(const String& text) : Square(text) { }
void SquareDraw::Do(Gameboard& gameboard) const
{
  if(gameboard.Cards().Empty())
    gameboard.Cards().Shuffle();

  const Card& card = gameboard.Cards().Draw();
  screen::Wait();

  screen::DrawCard(card);
  card.Do(gameboard);
}