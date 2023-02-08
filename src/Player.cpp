#include "Player.h"

#include "Ship.h"

static int kCur_playerId = 1;

Player::Player() {
  playerId_ = kCur_playerId++;
  ships_.resize(10);
};

Player::~Player(){};

void Player::AddShip(Ship* ship) {
  if (ships_.size() == ships_.capacity()) ships_.resize(ships_.size() + 5);
  if (ship->GetType() != "") ships_.push_back(ship);
};
