#include <time.h>

#include <iostream>

#include "Board.h"
#include "Player.h"
#include "Ship.h"
#include "Ships.h"

using namespace std;

int main() {
  srand(time(0));

  vector<Player*> players;

  Player* player1 = new Player;
  players.push_back(player1);

  Board board1;
  vector<Ship*> bot_ships{new Submarine, new Cruiser, new Cruiser,
                          new Destroyer, new AircraftCarrier};

  // bot_ships[1]->Rotate();
  // bot_ships[4]->Rotate();

  // board1.PlaceShip(1, 1, bot_ships[0]);
  // board1.PlaceShip(5, 5, bot_ships[1]);
  // board1.PlaceShip(2, 6, bot_ships[2]);
  // board1.PlaceShip(8, 1, bot_ships[3]);
  // board1.PlaceShip(4, 8, bot_ships[4]);

  // randomly place ships
  while (bot_ships.size() > 0) {
    int row = (rand() % board1.GetSize()) + 1;
    int col = (rand() % board1.GetSize()) + 1;
    if (rand() % 2) bot_ships[0]->Rotate();

    if (board1.PlaceShip(row, col, bot_ships[0]))
      bot_ships.erase(bot_ships.begin());
  }

  // board1.FireOnSquare(1, 1);
  // board1.FireOnSquare(1, 2);
  // board1.FireOnSquare(1, 3);
  // board1.FireOnSquare(2, 1);
  // board1.FireOnSquare(4, 9);
  // board1.FireOnSquare(4, 8);

  cout << board1 << endl;

  return 0;
}
