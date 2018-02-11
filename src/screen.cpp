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
  std::system("clear");
}