#include "gameboard.h"

/// *** PUBLIC *** ///
Gameboard::Gameboard(Vector<Square*>& squares)
{
  squares_ = squares;
  player_ = 0;
}

Gameboard::~Gameboard()
{
  for(int i = 0; i < squares_.Length(); i++)
    if(squares_[i])   // Safety is number one priority
      delete squares_[i];
}   

// Getters / Setters
Deck& Gameboard::Cards() { return deck_; }

Vector<Player>& Gameboard::Players() { return players_; }

Player& Gameboard::Playing() const { return players_[player_ % players_.Length()]; }

int Gameboard::PlayerNumber() const { return player_; }
void Gameboard::SetPlayerNumber(int n) { player_ = n; }