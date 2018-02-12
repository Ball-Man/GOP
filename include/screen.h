#ifndef GOP_SCREEN_H_
#define GOP_SCREEN_H_

#include <sstring.h>
#include "card.h"

namespace screen
{

const int kGridWidth = 100;
const int kSepare = 100;
const int kCardWidth = 15;
const int kCardHeight = 10;

void Wait();
void Clear();

void Separe();
void Out(const String& string);
void DrawCard(const Card& card);

}; // Namespace screen

#endif