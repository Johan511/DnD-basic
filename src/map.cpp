#include "../include/charecter.hpp"
#include <array>
#include <iostream>
#include <memory>

using MatrixSize = int;

static constexpr MatrixSize N = static_cast<MatrixSize>(1000);

class Wall : public Entity {
public:
  MatrixSize x, y;
  Wall(MatrixSize x_, MatrixSize y_)
      : x(x_), y(y_), Entity(std::to_string(x_) + "_" + std::to_string(y_)){};
};

class Dungeon {
  Wall *WallArray1 = nullptr;
  Wall *WallArray2 = nullptr;
  Wall *WallArray3 = nullptr;
  Wall *WallArray4 = nullptr;
  //(0, _), (N+1, _), (_, 0), (N+1, _) are walls by default
  std::array<std::array<std::unique_ptr<Entity>, N + 2>, N + 2> matrix;

public:
  constexpr Dungeon() {
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
      std::construct_at(static_cast<Wall *>(std::addressof(WallArray1[i])), 0,
                        i);
      std::construct_at(static_cast<Wall *>(std::addressof(WallArray3[i])), 0,
                        N + 1);

      std::construct_at(static_cast<Wall *>(std::addressof(WallArray2[i])), i,
                        0);
      std::construct_at(static_cast<Wall *>(std::addressof(WallArray4[i])), i,
                        N + 1);
    }

    //(0, _), (N+1, _), (_, 0), (N+1, _) are walls by default
    for (MatrixSize i = 0; i < N + 2; i++) {
      matrix[0][i] = std::make_unique<Wall>(WallArray1[i]);
      matrix[0][N + 1] = std::make_unique<Wall>(WallArray3[i]);
      matrix[i][0] = std::make_unique<Wall>(WallArray2[i]);
      matrix[i][N + 1] = std::make_unique<Wall>(WallArray4[i]);
    }

    for (MatrixSize i = 1; i < N + 1; i++) {
      for (MatrixSize j = 1; j < N + 1; j++) {
        matrix[i][j] = nullptr;
      }
    }
  }

  bool add_entity(MatrixSize x, MatrixSize y, std::unique_ptr<Entity> &&uptr) {
    if (matrix[x][y] != nullptr)
      return false;

    matrix[x][y] = std::move(uptr);
  }

  ~Dungeon() {
    std::destroy(WallArray1, WallArray1 + N + 2);
    std::destroy(WallArray2, WallArray2 + N + 2);
    std::destroy(WallArray3, WallArray3 + N + 2);
    std::destroy(WallArray4, WallArray4 + N + 2);

    free(WallArray1);
    free(WallArray2);
    free(WallArray3);
    free(WallArray4);
  }
};

int main() { Dungeon(); }