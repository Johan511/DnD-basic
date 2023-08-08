// Dungeon utilities
#include "../include/map.hpp"
namespace utility {

// y1 < t2
bool add_wall_row(Dungeon &d, MatrixSize x, MatrixSize y1, MatrixSize y2) {
  for (MatrixSize y = y1; y != y2; y++) {
    if (!d.is_empty(x, y))
      return false;
  }
  for (MatrixSize y = y1; y != y2; y++)
    d.add_entity(x, y, new Wall(x, y));
  return true;
}

bool add_wall_col(Dungeon &d, MatrixSize y, MatrixSize x1, MatrixSize x2) {
  for (MatrixSize x = x1; x != x2; x++) {
    if (!d.is_empty(x, y))
      return false;
  }
  for (MatrixSize x = x1; x != x2; x++)
    d.add_entity(x, y, new Wall(x, y));
  return true;
}

bool add_wall_line(Dungeon &d, MatrixSize x1, MatrixSize x2, MatrixSize y1,
                   MatrixSize y2) {
  if (x1 == x2) {
    return add_wall_row(d, x1, y1, y2);
  } else if (y1 == y2) {
    return add_wall_col(d, y1, x1, x2);
  }
  return false;
}
}; // namespace utility