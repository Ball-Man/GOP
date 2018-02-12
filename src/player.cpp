#include "player.h"


/// *** PUBLIC *** ///
Player::Player()
{
  name_ = String();
  pos_ = 0;
  coins_ = kDefaultCoins;
  s_ = '\0';
  stopped_ = false;
}

Player::Player(String& name, char s) : Player()
{
  name_ = name;
  s_ = s;
}

// Postion handling
void Player::StepForward(int steps) { pos_ += steps; }
void Player::StepBack(int steps) { pos_ = (steps >= pos_) ? 0 : pos_ - steps; }

void Player::SetPosition(int pos) { pos_ = pos; }
int Player::Position() const { return pos_; }

// Money handling
void Player::AddCoins(int coins) { coins_ += coins; }
void Player::LoseCoins(int coins) { coins_ = (coins >= coins_) ? 0 : coins_ - coins; }

void Player::SetCoins(int coins) { coins_ = coins; }
int Player::Coins() const { return coins_; }

// Getters for player's symbol and name
const String& Player::Name() const { return name_; }
char Player::Symbol() const { return s_; }

// Stop
bool Player::Stopped() const { return stopped_; }
void Player::SetStopped(bool stopped) { stopped_ = stopped; }