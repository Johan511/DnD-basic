#include "../include/charecter.hpp"
#include <array>
#include <memory>

using MatrixSize = int;

static constexpr MatrixSize N = static_cast<MatrixSize>(1000);

class Wall : public Entity {
public:
  Wall(MatrixSize x, MatrixSize y)
      : Entity(std::to_string(x) + "_" + std::to_string(y)){};
};

class Dungeon {
  //(0, _), (N+1, _), (_, 0), (N+1, _) are walls by default
  std::array<std::array<std::unique_ptr<Entity>, N + 2>, N + 2> matrix;

public:
  constexpr Dungeon() {
    // walls are kept in continuous memory block
    Wall *WallArray1 = static_cast<Wall *>(
        std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));
    Wall *WallArray2 = static_cast<Wall *>(
        std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));
    Wall *WallArray3 = static_cast<Wall *>(
        std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));
    Wall *WallArray4 = static_cast<Wall *>(
        std::aligned_alloc(alignof(Wall), sizeof(Wall) * (N + 2)));

    for (MatrixSize i = 0; i < N + 2; i++) {
      std::construct_at(reinterpret_cast<Wall *>(std::addressof(WallArray1[i])),
                        0, i);
      std::construct_at(reinterpret_cast<Wall *>(std::addressof(WallArray3[i])),
                        0, N + 1);

      std::construct_at(reinterpret_cast<Wall *>(std::addressof(WallArray2[i])),
                        i, 0);
      std::construct_at(reinterpret_cast<Wall *>(std::addressof(WallArray4[i])),
                        i, N + 1);
    }

    //(0, _), (N+1, _), (_, 0), (N+1, _) are walls by default
    for (MatrixSize i = 0; i < N + 2; i++) {
      matrix[0][i] = std::make_unique<Wall>(WallArray1[i]);
      matrix[0][N + 1] = std::make_unique<Wall>(WallArray3[i]);
      matrix[i][0] = std::make_unique<Wall>(WallArray2[i]);
      matrix[i][N + 1] = std::make_unique<Wall>(WallArray4[i]);
    }
  }
};