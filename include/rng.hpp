#include <random>

using RollTy = int;

// both min and max are inclusive
int roll(RollTy max);
int roll(RollTy max, RollTy min);

int multiple_rolls(int numRolls, RollTy max, RollTy min);
int multiple_rolls(int numRolls, RollTy max);
