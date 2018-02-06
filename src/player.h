#ifndef GOP_PLAYER_H_
#define GOP_PLAYER_H_

#include "string.h"

// Class for player identification
class Player
{
 public:
  Player();
  Player(String& name, char s);

  // Position handling
  void StepForward(int steps);
  void StepBack(int steps);

  void SetPosition(int pos);
  int Position() const;

  // Money handling
  void AddCoins(int coins);
  void LoseCoins(int coins);

  void SetCoins(int coins);
  int Coins() const; 

  // Getters for player's symbol and name
  const String& Name() const;
  char Symbol() const;

 private:
  const int kDefaultCoins = 10;

  String name_;

  int pos_;
  int coins_;
  char s_;
};

#endif