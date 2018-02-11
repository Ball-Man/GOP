#include <iostream>
#include "sstring.h"
#include "vector.h"
#include "random.h"

int main(int argc, char const *argv[])
{
  String b;
  getline(std::cin, b);

  std::cout << "Actual string: " << b << "\n";

  if("" == b)
    std::cout << "EMPTY" << std::endl;

  if(b == "ciao")
    std::cout << "ANCHE A TE" << std::endl;

  return 0;
}