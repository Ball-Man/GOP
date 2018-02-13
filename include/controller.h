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
  bool FromFile(const String& squares_file, const String& cards_file, const String& gop_file);

  // Game management
  void Do();
  void DrawGrid();
  void Win(const Player& player);

  // GOP logo
  void DrawGOP();

  // Getter
  bool Quit() const;

 private:
  static const String kSquaresFile;
  static const String kCardsFile;
  static const String kGopFile;
  static const int kMinSquares = 20;
  static const int kMaxSquares = 50;

  Vector<String> gop_;
  Gameboard gameboard_;
  bool quit_;
};

#endif