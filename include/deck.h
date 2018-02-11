#ifndef GOP_DECK_H_
#define GOP_DECK_H_

#include "card.h"
#include "vector.h"

// The Deck class contains a defined number of cards
// and manages them similarly to a data structure,
// miming a real deck's behavior.
class Deck
{
  public:
    ~Deck();

    // Deck management
    void Shuffle();
    const Card& Draw();

    // Deck info
    bool Empty() const;

    // Deck creation
    bool FromFile(const String& filename);

  private:
    Vector<Card*> deck_;
    Vector<Card*> discards_;
};

#endif