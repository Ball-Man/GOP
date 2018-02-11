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

  screen::Separe();

  if(!FromFile(kSquaresFile, kCardsFile))
    return;

  // Input number of players
  int players;
  bool ok;
  do
  {
    std::cout << "Number of players(2 - 4): ";
    ok = input::ReadInt(players) && players >= 2 && players <= 4;  // Check if valid

    if(!ok)
    {
      screen::Clear();
      std::cout << "Invalid input!\n";
    }
  } while(!ok);

  // Input player data
  for(int i = 0; i < players; i++)
  {
    String name;
    char symbol;

    screen::Separe();

    // Read name
    std::cout << "Player " << i + 1 << "\n\tName: "; 
    getline(std::cin, name);
    
    // Read symbol
    do
    {
      std::cout << "\tSymbol(one character): ";
      ok = input::ReadChar(symbol);
      if(!ok)
        std::cout << "\tInvalid input!\n";
    } while(!ok);

    gameboard_.Players().Push(Player(name, symbol));  // Add player
  }

  // Init first player
  gameboard_.SetPlayerNumber(rnd::RandInt(0, players - 1));

  screen::Clear();
  screen::Separe();
  std::cout << "The first player will be chosen randomly.\npress ENTER to continue\n";
  screen::Separe();
  screen::Wait();
}

void Controller::Do()
{
  screen::Clear();
  DrawGrid();

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
    screen::Separe();
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