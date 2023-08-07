#include "./attributes.hpp"
#include "./items.hpp"
#include "./rng.hpp"

#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#pragma once

class Entity {
protected:
  std::string const name = "";
  Entity(std::string &&name_) : name(std::move(name_)){};
  Entity() : name("_"){};

public:
  virtual ~Entity(){};
};