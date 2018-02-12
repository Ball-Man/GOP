#include "controller.h"

#include <iostream>
#include <fstream>
#include "squares.h"
#include "random.h"
#include "include_squares.h"

bool Controller::FromFile(const String& squares_file, const String& cards_file, const String& gop_file)
{
  if(!gameboard_.Cards().FromFile(cards_file))
  {
    std::cout << "--- Missing file: " << cards_file << "\n";
    quit_ = true;
    return false;
  }


  // Read GOP logo
  std::ifstream gop_fin(gop_file.ToCString());
  if(!gop_fin.is_open())
  {
    std::cout << "--- Missing file: " << gop_file << "\n";
    quit_ = true;
    return false;
  }

  while(!gop_fin.eof())
  {
    String tmp;
    getline(gop_fin, tmp);
    gop_.Push(tmp);
  }

  gop_fin.close();

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

    squares_fin >> type;

    char c = '\0';
    squares_fin.get();
    while(c != ';')
    {
      c = squares_fin.get();
      if(c != ';')
        text += c;
    }
    squares_fin.get();

    switch((Squares)type)     // Select which square type to create
    {
      case Squares::FORWARD:
      {
        int steps;
        squares_fin >> steps;
        tmp_squares.Push(new SquareForward(text, steps));
        break;
      }

      case Squares::BACK:
      {
        int steps;
        squares_fin >> steps;
        tmp_squares.Push(new SquareBack(text, steps));
        break;
      }

      case Squares::STOP:
        tmp_squares.Push(new SquareStop(text));
        break;

      case Squares::COINS:
      {
        int coins;
        squares_fin >> coins;
        tmp_squares.Push(new SquareCoins(text, coins));
        break;
      }

      case Squares::REROLL:
        tmp_squares.Push(new SquareReroll(text));
        break;
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

  // Loop safety
  gameboard_.Board().Insert(new SquareEmpty("Empty station, just wait for the next train..."), 0);

  return true;
}