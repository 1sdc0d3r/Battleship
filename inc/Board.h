#pragma once
#include <ostream>
#include <vector>

#include "Ship.h"

using std::pair;
using std::vector;

class Board {
 private:
  int size_ = 10;

 public:
  // vector<pair<int, int>> shots_;
  // not able to store 2 types of pointers in vector
  vector<vector<Ship*>> board_;

  Board();
  ~Board();

  bool PlaceShip(int row, int col, Ship* ship);
  // rotate horizontal if false -- vertical if true

  Ship* GetSquare(int row, int col) const;
  bool FireOnSquare(int row, int col);
  int GetSize() { return size_; }

  friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
