#include "../include/attributes.hpp"
#include "../include/items.hpp"

#include <iostream>
#include <random>
#include <string>
#include <vector>

template <typename ClassTy> class Charectar {
protected:
  using Class = ClassTy;

  std::string const name;
  std::string const gender;

  std::vector<Item> items;

  Charectar(std::string &&name_) : name(std::move(name)){};

public:
  std::string const &get_name() { return name; }
  std::string const &get_gender() { return gender; }
  std::string const &get_class() { return Class::className; }
};

// any weapon/armour => magic too, but no other sort of magic
// as they increase in level => harder to kill (increase their hit dice)
// increased ability to get hits at lvl >= 4
class FightingMan : public Charectar<classes::Fighter> {};

// humans who elect to become
// magic-users must not wear armor and can carry only a
// dagger for protection, use any magic item
// only one spell at low levels, 2 at higher level
class MagicMan : public Charectar<classes::MagicUser> {};

// nothing stronger than leather armor and can not carry shields
// all the weapons of a fighting man including magic swords and magic daggers.
// lvl >= 3 can read 80% stuff
class Theif : public Charectar<classes::Thief> {};

// resistant to magicm, better saving throws against magical attack.
// 60ft night vision
// construction time is 1/3
// only one who can wield +3 magic war hammer
class Dwarf : public Charectar<classes::Fighter> {};

// can use all the weapons and armor, including magic ones
// can cast all spells
// 60ft night vision
/*
  Elves progress in level as both fighting men and
  magic-users, but since each game nets them experience in both categories
  equally, they progress more slowly than other characters
*/
class Elf : public Charectar<classes::MagicUser> {};

// TODO Cleric
// TODO halfling

int main() {
  AttributeManager a(abilities::Strength{});
  return 0;
}