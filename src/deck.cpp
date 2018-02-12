#include "deck.h"

#include <iostream>
#include <fstream>
#include "sstring.h"
#include "random.h"
#include "cards.h"
#include "include_cards.h"

/// *** PUBLIC *** ///
Deck::~Deck()
{
  // Clear cards from deck...
  for(int i = 0; i < deck_.Length(); i++)
    if(deck_[i])  // Check if not NULL
      delete deck_[i];

  // And from discards...
  for(int i = 0; i < discards_.Length(); i++)
    if(discards_[i])
      delete discards_[i];
}

// Deck management
void Deck::Shuffle()
{
  Vector<Card*> tmp;

  // Discard all cards
  while(deck_.Length() > 0)
    discards_.Push(deck_.Pop());

  // Randomly push cards in the new vector
  while(discards_.Length() > 0)
  {
    int index = rnd::RandInt(0, discards_.Length() - 1);

    tmp.Push(discards_[index]);
    discards_.Erase(index);
  }

  for(int i = 0; i < tmp.Length(); i++)  // Replace deck
    deck_.Push(tmp[i]);
}

const Card& Deck::Draw() 
{ 
  Card* pop = deck_.Pop();
  discards_.Push(pop);
  return *pop;
}

// Deck info
bool Deck::Empty() const { return deck_.Length() == 0; }

// Deck creation
bool Deck::FromFile(const String& filename) 
{
  std::ifstream fin(filename.ToCString());

  if(!fin.is_open())
    return false;

  // Load deck from file
  while(!fin.eof())
  {
    int type;
    String text;

    fin >> type;

    char c = '\0';
    fin.get();
    while(c != ';')
    {
      c = fin.get();
      if(c != ';')
        text += c;
    }
    fin.get();

    switch((Cards)type)
    {
      case Cards::NOTHING:
        deck_.Push(new CardNothing(text));
        break;

      case Cards::COINS:
      {
        int coins;
        fin >> coins;
        deck_.Push(new CardCoins(text, coins));
        break;
      }

      case Cards::LOSE_COINS:
      {
        int coins;
        fin >> coins;
        deck_.Push(new CardLoseCoins(text, coins));
        break;
      }

      case Cards::BUY_FORWARD:
      {
        int steps, price;
        fin >> steps, price;
        deck_.Push(new CardBuyForward(text, steps, price));
        break;
      }

      case Cards::WORST_FORWARD:
      {
        int steps;
        fin >> steps;
        deck_.Push(new CardWorstForward(text, steps));
        break;
      }

      case Cards::WORST_BACK:
      {
        int steps;
        fin >> steps;
        deck_.Push(new CardWorstBack(text, steps));
        break;
      }

      case Cards::BEST_FORWARD:
      {
        int steps;
        fin >> steps;
        deck_.Push(new CardBestForward(text, steps));
        break;
      }

      case Cards::EVERYONE_TO_ZERO:
      {
        deck_.Push(new CardEveryoneToZero(text));
        break;
      }
    }
  }

  Shuffle();

  return true;
}

