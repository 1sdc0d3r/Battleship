#pragma once
#include "Ship.h"

class Submarine : public Ship {
 public:
  Submarine() {
    type_ = "Submarine";
    size_ = 2;
    movement_spd_ = 2;
    cur_hp_ = 2;
    max_hp_ = 2;
  };
  ~Submarine(){};
};
class Cruiser : public Ship {
 public:
  Cruiser() {
    type_ = "Cruiser";
    size_ = 3;
    movement_spd_ = 3;
    cur_hp_ = 3;
    max_hp_ = 3;
  };
  ~Cruiser(){};
};
class Destroyer : public Ship {
 public:
  Destroyer() {
    type_ = "Destroyer";
    size_ = 4;
    movement_spd_ = 2;
    cur_hp_ = 4;
    max_hp_ = 4;
  };
  ~Destroyer(){};
};
class AircraftCarrier : public Ship {
 public:
  AircraftCarrier() {
    type_ = "Aircraft Carrier";
    size_ = 5;
    movement_spd_ = 1;
    cur_hp_ = 5;
    max_hp_ = 5;
  };
  ~AircraftCarrier(){};
};
