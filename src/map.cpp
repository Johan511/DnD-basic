#include "../include/map.hpp"

constexpr Dungeon::Dungeon() {
  // walls are kept in continuous memory block
  WallArray1 = static_cast<Wall *>(
      std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));
  WallArray2 = static_cast<Wall *>(
      std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));
  WallArray3 = static_cast<Wall *>(
      std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));
  WallArray4 = static_cast<Wall *>(
      std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));

  for (MatrixSize i = 0; i < N + 2; i++) {
    std::construct_at(static_cast<Wall *>(std::addressof(WallArray1[i])), 0, i);
    std::construct_at(static_cast<Wall *>(std::addressof(WallArray3[i])), N + 1,
                      i);

    std::construct_at(static_cast<Wall *>(std::addressof(WallArray2[i])), i, 0);
    std::construct_at(static_cast<Wall *>(std::addressof(WallArray4[i])), i,
                      N + 1);
  }

  //(0, _), (N+1, _), (_, 0), (N+1, _) are walls by default
  for (MatrixSize i = 0; i < N + 2; i++) {
    matrix[0][i] = WallArray1 + i;
    matrix[0][N + 1] = WallArray3 + i;
    matrix[i][0] = WallArray2 + i;
    matrix[i][N + 1] = WallArray4 + i;
  }

  for (MatrixSize i = 1; i < N + 1; i++) {
    for (MatrixSize j = 1; j < N + 1; j++)
      matrix[i][j] = nullptr;
  }
}

Dungeon::~Dungeon() {
  std::destroy(WallArray1, WallArray1 + N + 2);
  std::destroy(WallArray2, WallArray2 + N + 2);
  std::destroy(WallArray3, WallArray3 + N + 2);
  std::destroy(WallArray4, WallArray4 + N + 2);

  free(WallArray1);
  free(WallArray2);
  free(WallArray3);
  free(WallArray4);

  for (MatrixSize i = 1; i < N + 1; i++) {
    for (MatrixSize j = 1; j < N + 1; j++) {
      delete matrix[i][j];
    }
  }
}

bool Dungeon::add_entity(MatrixSize x, MatrixSize y, Entity *ptr) {
  if (matrix[x][y] != nullptr)
    return false;

  matrix[x][y] = ptr;
  return true;
}
