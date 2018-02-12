#include "controller.h"

#include <iostream>
#include "input.h"
#include "random.h"
#include "screen.h"

/// *** PUBLIC *** ///
Controller::Controller()
{
  quit_ = false;
}

void Controller::Init()
{
  // Init random
  rnd::Init();

  screen::Clear();

  if(!FromFile(kSquaresFile, kCardsFile, kGopFile))
    return;

  DrawGOP();

  // Input number of players
  int players;
  bool ok;
  do
  {
    std::cout << "Number of players(2 - 4): ";
    ok = input::ReadInt(players) && players >= 2 && players <= 4;  // Check if valid

    if(!ok)
      std::cout << "Invalid input!\n";
  } while(!ok);

  // Input player data
  for(int i = 0; i < players; i++)
  {
    String name;
    char symbol;

    screen::Separe();

    // Read name
    do
    {
      std::cout << "Player " << i + 1 << "\n\tName: ";
      getline(std::cin, name);

      // Check if correct
      ok = name != "";
      for(int i = 0; i < gameboard_.Players().Length(); i++)
        if(gameboard_.Players()[i].Name() == name)
          ok = false;

      if(!ok)
        std::cout << "\tInvalid input!\n"; 
    } while(!ok);
    
    // Read symbol
    do
    {
      std::cout << "\tSymbol(one character): ";

      // Check if correct
      ok = input::ReadChar(symbol);

      for(int i = 0; i < gameboard_.Players().Length(); i++)
        if(gameboard_.Players()[i].Symbol() == symbol)
          ok = false;
      
      if(!ok)
        std::cout << "\tInvalid input!\n";
    } while(!ok);

    gameboard_.Players().Push(Player(name, symbol));  // Add player
  }

  // Init first player
  gameboard_.SetPlayerNumber(rnd::RandInt(0, players - 1));

  screen::Clear();
  DrawGOP();
  std::cout << "Welcome to GOP;\nThe first player will be chosen randomly.\nThe first player who reaches the terminus wins.\npress ENTER to continue\n";
  screen::Separe();
  screen::Wait();
}

void Controller::Do()
{
  screen::Clear();
  DrawGrid();

  std::cout << "\nWhat do you do?\n\tdie: Push your luck\n\tquit: End the game with no winner\n>";

  String cmd;
  getline(std::cin, cmd);

  if(cmd == "die")
  {
    // It's important to roll 2 dies, since the probability for numbers are different
    int die1 = rnd::RandInt(1, 6),
        die2 = rnd::RandInt(1, 6);

    std::cout << "You rolled two dies:\n\tFirst die: " << die1 << "\n\tSecond die: " << die2 << "\n";

    screen::Wait(); // Suspance
    screen::Clear();

    gameboard_.Playing().StepForward(die1 + die2);  // Move player
    if(gameboard_.Playing().Position() >= gameboard_.Squares()) // Check if won the game
    {
      Win(gameboard_.Playing());
      quit_ = true;
      return;
    }

    // If not...
    DrawGOP();
    std::cout << gameboard_.OnSquare().Text() << "\n";
    screen::Separe();

    gameboard_.OnSquare().Do(gameboard_);
    screen::Wait();

    std::cout << "\nTime for the next player!";
    gameboard_.NextPlayer();

    screen::Wait();
  }
  else if(cmd == "quit")
    quit_ = true;
}

void Controller::DrawGrid()
{
  // Who's playing
  DrawGOP();
  std::cout << "Playing: " << gameboard_.Playing().Name() << " (" << gameboard_.Playing().Symbol() << ")\n";
  screen::Separe();

  int max_pos = 0;    // Calc who is winning
  String max_name;
  for(int i = 0; i < gameboard_.Players().Length(); i++)
  {
    Player& player = gameboard_.Players()[i];
    if(player.Position() > max_pos)
    {
      max_pos = player.Position();
      max_name = player.Name();
    }
  }

  std::cout << "Winning: " << max_name << "\n";

  screen::Separe();

  // Output coins
  std::cout << "Coins: ";
  for(int i = 0; i < gameboard_.Players().Length(); i++)
    std::cout << gameboard_.Players()[i].Name() << ": " << gameboard_.Players()[i].Coins()
      << " |";
  std::cout << "\n";

  const int square_width = 3;
  const int square_height = 3;
  int columns = kGridWidth / square_width;
  
  std::cout << "\n-";
  for(int i = 0; i < columns; i++)
    std::cout << "---";
  std::cout << "\n";

  int count = gameboard_.Squares();
  while(count > 0)
  {
    int n;
    if(count > columns)
    {
      n = columns;
      count -= n;
    }
    else
    {
      n = count;
      count = 0;
    }

    for(int x = 0; x < square_height; x++)
    {
      std::cout << (x == (square_height - 1) ? "-" : "|");

      int ref = gameboard_.Squares() - count - n;
      for(int i = 0; i < n; i++)
      {
        String out;
        switch(x)
        {
          case 0:
            out += (gameboard_.Players()[0].Position() == ref + i) ? gameboard_.Players()[0].Symbol() : ' ';
            out += (gameboard_.Players()[1].Position() == ref + i) ? gameboard_.Players()[1].Symbol() : ' ';
            out += '|';
            std::cout << out;
            break;
          case 1:
            out += (gameboard_.Players().Length() > 2 && gameboard_.Players()[2].Position() == ref + i) 
              ? gameboard_.Players()[2].Symbol() : ' ';
            out += (gameboard_.Players().Length() > 3 && gameboard_.Players()[3].Position() == ref + i) 
              ? gameboard_.Players()[3].Symbol() : ' ';
            out += '|';
            std::cout << out;
            break;
          case 2:
            std::cout << "---";
            break;
        }
      }

      std::cout << "\n";
    }
  }

}

void Controller::DrawGOP()
{
  screen::Separe();

  for(int i = 0; i < gop_.Length(); i++)
    std::cout << gop_[i] << "\n";

  screen::Separe();
}

void Controller::Win(const Player& player)
{
  screen::Clear();
  screen::Separe();

  std::cout << player.Name() << " won the game!\nSee you space cowboy...\n";

  screen::Separe();
  screen::Wait();
}

// Getter
bool Controller::Quit() const { return quit_; }

/// *** PRIVATE *** ///
const String Controller::kSquaresFile = "squares.mx";
const String Controller::kCardsFile = "cards.mx";
const String Controller::kGopFile = "gop.txt";