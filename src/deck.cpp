#include "deck.h"

#include "random.h"

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

  deck_ = tmp;  // Replace deck
}

const Card& Deck::Draw() { return *deck_.Pop(); }

// Deck info
bool Deck::Empty() const { return deck_.Length() == 0; }

// Deck creation
bool Deck::FromFile(const String& filename) { /* TODO: Add from file implementation */ return true; }

