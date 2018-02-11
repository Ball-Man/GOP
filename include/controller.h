#ifndef GOP_CONTROLLER_H_
#define GOP_CONTROLLER_H_

#include "sstring.h"
#include "gameboard.h"

// Class used to control the game itself
// (gameboard generation, file input, console output)
class Controller
{
 public:
  Controller();

  // Game initialization
  void Init();
  bool FromFile(const String& squares_file, const String& cards_file);

  // Game management
  void Do();
  void DrawGrid();
  void Win(const Player& player);

  // Getter
  bool Quit() const;

 private:
  static const String kSquaresFile;
  static const String kCardsFile;
  static const int kMinSquares = 40;
  static const int kMaxSquares = 53;

  Gameboard gameboard_;
  bool quit_;
};

#endif