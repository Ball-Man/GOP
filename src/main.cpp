#include <iostream>
#include "string.h"
#include "vector.h"

int main(int argc, char const *argv[])
{
  Vector<int> v = Vector<int>(15, 2);
  
  v.Push(19);
  v.Push(12);
  v.Pop();

  for(int i = 0; i < v.Length(); i++)
    std::cout << v[i] << " ";

  std::cout << std::endl << "Cap: " << v.Capacity() << " Len: " << v.Length() << std::endl; 
  return 0;
}