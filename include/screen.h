#ifndef GOP_SCREEN_H_
#define GOP_SCREEN_H_

#include <sstring.h>

namespace screen
{

const int kGridWidth = 100;
const int kSepare = 100;

void Wait();
void Separe();
void Clear();
void Out(const String& string);

}; // Namespace screen

#endif