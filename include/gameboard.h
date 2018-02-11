#ifndef GOP_GAMEBOARD_H_
#define GOP_GAMEBOARD_H_

#include "vector.h"
#include "player.h"
#include "deck.h"
#include "square.h"

// The Gameboard class is used as a manager for
// the different game sections(players vs. squares vs. cards).
// It's not going to manage the whole game; An additional
// abstraction layer is put between the main cicle and Gameboard.
class Gameboard
{
 public:
  Gameboard();
  Gameboard(const Gameboard& gameboard) = delete;   // No copies
  ~Gameboard();

  Gameboard& operator =(const Gameboard& gameboard) = delete;   // Quote: No copies

  // Getters / Setters
  Deck& Cards();

  Vector<Player>& Players();
  Vector<Square*>& Board();

  Player& Playing() const;
  Square& OnSquare() const;

  int Squares() const;

  int PlayerNumber() const;
  void SetPlayerNumber(int n);
  void NextPlayer();

 private:
  Deck deck_;
  Vector<Square*> squares_;
  Vector<Player> players_;
  int player_;
};

#endif