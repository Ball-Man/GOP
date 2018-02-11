#include "gameboard.h"

#include <iostream>

/// *** PUBLIC *** ///
Gameboard::Gameboard() { }

Gameboard::~Gameboard()
{
  for(int i = 0; i < squares_.Length(); i++)
    if(squares_[i])
      delete squares_[i];
}   

// Getters / Setters
Deck& Gameboard::Cards() { return deck_; }

Vector<Player>& Gameboard::Players() { return players_; }
Vector<Square*>& Gameboard::Board() { return squares_; }

Player& Gameboard::Playing() const { return players_[player_ % players_.Length()]; }
Square& Gameboard::OnSquare() const { return *squares_[Playing().Position()]; }

int Gameboard::Squares() const { return squares_.Length(); }

int Gameboard::PlayerNumber() const { return player_; }
void Gameboard::SetPlayerNumber(int n) { player_ = n; }
void Gameboard::NextPlayer() { player_++; }