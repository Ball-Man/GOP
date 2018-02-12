#include "screen.h"

#include <iostream>
#include <cstdlib>
#include <limits>
#include "sstring.h"

void screen::Wait()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void screen::Separe()
{
  char s = '-';
  String separe;

  for(int i = 0; i < kSepare; i++)
    separe += s;

  std::cout << separe << "\n";
}

void screen::Clear()
{
  #ifdef __unix__
    std::system("clear");
  #endif

  #ifdef _WIN32
    std::system("cls");
  #endif
}

void screen::Out(const String& string)
{
  for(int i = 0; i < string.Length(); i++)
  {
    if(i % kGridWidth == 0 && i != 0)
      std::cout << "\n";
    std::cout << string[i];
  }
  std::cout << "\n";
}

void screen::DrawCard(const Card& card)
{
  for(int i = 0; i < kCardWidth + 4; i++)
      std::cout << "-";

  std::cout << "\n| ";
  for(int i = 0; i < kCardWidth * kCardHeight; i++)
  {
    if(i % kCardWidth == 0 && i != 0)
      std::cout << " |\n| ";

    if(i < card.Text().Length())
      std::cout << card.Text()[i];
    else
      std::cout << " ";
  }
  std::cout << " |\n";

  for(int i = 0; i < kCardWidth + 4; i++)
      std::cout << "-";

  std::cout << "\n";
}