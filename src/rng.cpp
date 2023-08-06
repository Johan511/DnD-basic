#include "../include/rng.hpp"

// both min and max are inclusive
int roll(RollTy max, RollTy min) { return rand() % (max - min + 1) + min; }
int roll(RollTy max) { return rand() % (max - 1 + 1) + 1; }

int multiple_rolls(int numRolls, RollTy max, RollTy min) {
  RollTy sum = static_cast<RollTy>(0);
  while (numRolls--) {
    sum += roll(max, min);
  }
  return sum;
}

int multiple_rolls(int numRolls, RollTy max) {
  RollTy sum = static_cast<RollTy>(0);
  while (numRolls--) {
    sum += roll(max, 1);
  }
  return sum;
}
