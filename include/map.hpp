#include "./charecter.hpp"
#include <array>
#include <iostream>
#include <memory>

#pragma once

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
  std::array<std::array<Entity *, N + 2>, N + 2> matrix;

public:
  constexpr Dungeon();
  bool add_entity(MatrixSize x, MatrixSize y, Entity *ptr);
  bool is_empty(MatrixSize x, MatrixSize y);
  ~Dungeon();
};