#include "input.h"

#include <iostream>
#include <cmath>
#include "sstring.h"

bool input::ReadInt(int& out)
{
  out = 0;

  // Input
  String s;
  getline(std::cin, s);

  //Parse check
  for(int i = 0; i < s.Length(); i++)
    if(s[i] < '0' || s[i] > '9')
      return false;

  // Actual parse
  for(int i = 0; i < s.Length(); i++)
    out += (int)pow(10, i) * (s[s.Length() - i - 1] - '0');

  return true;
}

bool input::ReadChar(char& out)
{
  // Input
  String s;
  getline(std::cin, s);

  // Check if correct
  if(s.Length() == 0 || s.Length() > 1)
    return false;

  out = s[0];

  return true;
}