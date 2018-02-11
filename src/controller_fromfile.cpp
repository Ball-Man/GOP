#include "controller.h"

#include <iostream>
#include <fstream>
#include "squares.h"
#include "random.h"
#include "include_squares.h"

bool Controller::FromFile(const String& squares_file, const String& cards_file)
{
  if(!gameboard_.Cards().FromFile(cards_file))
  {
    std::cout << "--- Missing file: " << cards_file << "\n";
    quit_ = true;
    return false;
  }

  std::ifstream squares_fin(squares_file.ToCString());
  Vector<Square*> tmp_squares;

  // Add random numbers of empty squares
  int empty_squares = rnd::RandInt(kMinSquares, kMaxSquares);
  for(int i = 0; i < empty_squares; i++)
    tmp_squares.Push(new SquareEmpty("Empty station, just wait for the next train..."));

  if(!squares_fin.is_open())
  {
    std::cout << "--- Missing file: " << squares_file << "\n";
    quit_ = true;
    return false;
  }

  while(!squares_fin.eof())
  {
    int type;
    String text;

    squares_fin >> type >> text;

    if(!squares_fin.eof())      // if correctly read
    {
      switch((Squares)type)     // Select which square type to create
      {
        
      }
    }
  }

  squares_fin.close();

  // Randomly insert squares into game
  while(tmp_squares.Length() > 0)
  {
    int pos = rnd::RandInt(0, tmp_squares.Length() - 1);
    gameboard_.Board().Push(tmp_squares[pos]);
    tmp_squares.Erase(pos);
  }

  return true;
}