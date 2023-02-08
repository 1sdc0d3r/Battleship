#pragma once

#include <string>
using std::pair;
using std::string;
using std::vector;

class Ship {
 protected:
  // later have damage be recorded for which placement in size [0,1,1,0]
  // cur_hp set by adding array of hp left (this if for movement later)
  //  int id_{0};
  string type_ = "";  // leave empty until miss for "splash"
  int size_{0};
  bool rotated_{false};
  // bool sunken_{false};
  int movement_spd_{0};
  int max_hp_{0};  // 0 for water
  int cur_hp_{1};
  
  vector<pair<int, int>> hits_;  // in public for testing

 public:
  Ship(){};
  // Ship(string type);
  virtual ~Ship(){};

  // int inline GetId() { return id_; };

  void inline SetSize(int size) { this->size_ = size; };
  int inline GetSize() { return size_; };

  void inline SetType(string type) { this->type_ = type; };
  string inline GetType() { return type_; };

  void inline Rotate() { rotated_ = !rotated_; }
  bool GetRotated() { return rotated_; };

  void inline RemoveHp() { cur_hp_--; };
  int inline GetCurHp() { return cur_hp_; };
  int inline GetMaxHp() { return max_hp_; };

  void inline AddHit(pair<int, int> hit) { hits_.push_back(hit); }
  bool inline GetHit(int row, int col) {
    if (count(hits_.begin(), hits_.end(), pair<int, int>(row, col)))
      return true;
    return false;
  };
};
