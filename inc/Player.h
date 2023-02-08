#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Ship.h"
using namespace std;

class Player {
 private:
  //   static int kCur_playerId;
  int playerId_;
  int gold_;

  vector<Ship*> ships_;  // set default size of vector

 public:
  Player();
  ~Player();
  void AddShip(Ship* ship);
};

#endif
