#include <iostream>
#include "sstring.h"
#include "vector.h"
#include "random.h"

int main(int argc, char const *argv[])
{
  rnd::Init();

  int n = rnd::RandInt(0, 10);
  std::cout << n << std::endl;

  return 0;
}