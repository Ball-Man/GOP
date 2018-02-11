#include <iostream>
#include "controller.h"

#include "sstring.h"

int main(int argc, char const *argv[])
{
  Controller controller;

  controller.Init();
  while(!controller.Quit())
    controller.Do();

  return 0;
}