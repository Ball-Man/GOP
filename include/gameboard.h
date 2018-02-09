#ifndef GOP_GAMEBOARD_H_
#define GOP_GAMEBOARD_H_

#include <cstdint>
#include "player.h"
#include "deck.h"
#include "square.h"
#include "vector.h"

// The Gameboard class is used as a manager for
// the different game sections(players vs. squares vs. cards).
// It's not going to manage the whole game; An additional
// abstraction layer is put between the main cicle and Gameboard.
class Gameboard
{
 public:
  Gameboard(Vector<Square*>& squares);
  ~Gameboard();

  // Getters / Setters
  Deck& Cards();

  Vector<Player>& Players();

  Player& Playing() const;

  int PlayerNumber() const;
  void SetPlayerNumber(int n);

 private:
  Deck deck_;
  Vector<Square*> squares_;
  Vector<Player> players_;
  int player_;
};

#endif