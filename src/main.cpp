#include <iostream>
#include "sstring.h"
#include "vector.h"

int main(int argc, char const *argv[])
{
  String b;

  std::cin >> b;
  if("" == b)
    std::cout << "EMPTY" << std::endl;

  if(b == "ciao")
    std::cout << "ANCHE A TE" << std::endl;

  return 0;
}