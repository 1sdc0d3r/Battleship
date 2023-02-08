#include "Board.h"

#include <iostream>

using namespace std;

Board::Board() {
  board_.resize(size_);
  for (int i = 0; i < size_; ++i) {
    board_[i].resize(size_);
    for (int j = 0; j < size_; j++) {
      board_[i][j] = new Ship;
    }
  }
};

Board::~Board() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      delete board_[i][j];
      board_[i][j] = nullptr;
    };
  };
};

bool Board::PlaceShip(int row, int col, Ship* ship) {
  // rotated true is vertical
  --row;
  --col;

  Ship* squarePtr = GetSquare(row, col);
  // cout << "test" << squarePtr->GetType() << endl;
  int ship_size = ship->GetSize();
  // cout << "here: " << squarePtr->GetType() << endl;
  // cout << "here: " << ship->GetType() << endl;

  for (int i = 1; i <= ship_size; ++i) {
    if (squarePtr == nullptr || squarePtr->GetSize() != 0) {
      cout << "Invalid ship location at (" << row + i << "," << col + i << ")."
           << endl;
      return false;
    };
    if (ship->GetRotated())
      squarePtr = GetSquare(row + i, col);
    else
      squarePtr = GetSquare(row, col + i);
  };

  // past for loop is a valid ship placement to place ship in game grid
  while (ship_size > 0) {
    --ship_size;
    // board_[row][col] = nullptr;
    board_[row][col] = ship;

    if (ship->GetRotated())
      ++row;
    else
      ++col;
  }
  cout << "ship successfully placed" << endl;
  return true;
};

Ship* Board::GetSquare(int row, int col) const {
  if (row < size_ && col < size_ && row > -1 && col > -1)
    return board_[row][col];
  return nullptr;
};

bool Board::FireOnSquare(int row, int col) {
  --row;
  --col;
  pair<int, int> shot(row, col);

  Ship* squarePtr = GetSquare(row, col);

  if (squarePtr->GetMaxHp() == 0) {  // miss
    cout << "Miss" << endl;
    squarePtr->RemoveHp();
  } else if (squarePtr->GetMaxHp() > 0) {  // hit
    cout << "Hit" << endl;
  } else {
    cout << "invalid space" << endl;
    return false;
  };

  squarePtr->RemoveHp();
  squarePtr->AddHit(shot);

  return true;
};

std::ostream& operator<<(std::ostream& out, const Board& board) {
  // out << "  1  2  3" << endl;
  // out << "  -  -  -";
  for (int i = 0; i < board.size_; ++i) {
    out << "\n" << i + 1;
    if (i < board.size_ - 1) out << " ";
    out << "|";

    for (int j = 0; j < board.size_; ++j) {
      Ship* sqr = board.board_[i][j];
      if (sqr->GetHit(i, j)) {
        if (sqr->GetMaxHp() == 0)  // miss water
          out << "^  ";
        else if (sqr->GetCurHp() > 0 && sqr->GetMaxHp() != 0) {  // Hit Ship
          out << "x  ";
        } else if (sqr->GetCurHp() == 0 && sqr->GetMaxHp() != 0) {  // Sunk Ship
          out << "#  ";
        }
      } else if (sqr->GetCurHp() > 0 && sqr->GetMaxHp() != 0) {
        out << sqr->GetType()[0] << " ";
      } else {
        out << "  ";
      };
    };
  };
  out << endl << endl;
  return out;
};
