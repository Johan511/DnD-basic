#include "../include/charecter.hpp"

std::string const classes::Fighter::className = "Fighter";
std::string const classes::MagicUser::className = "MagicUser";
std::string const classes::Thief::className = "Thief";

template <typename Class, typename DerivedCharecter>
class Charectar : public Entity {
protected:
  using HealthTy = int;
  static constexpr ItemCostTy GOLD_MULTIPLIER = static_cast<ItemCostTy>(10);

  //////////////////////////
  std::string const gender;
  //////////////////////////

  //////////////////////////
  std::vector<Item> items;
  ItemCostTy gold;
  HealthTy health = 0;
  HealthTy maxHealth;
  //////////////////////////

  // modifiers
  std::vector<std::function<double(DerivedCharecter const &)>> dmgModifiers;

  Charectar(std::string &&name_, std::string &&gender_, HealthTy maxHealth_)
      : Entity(std::move(name_)), gender(std::move(gender_)),
        maxHealth(maxHealth_) {
    health = roll(maxHealth);
    gold = GOLD_MULTIPLIER * multiple_rolls(3, 6, 1);
  };

public:
  std::string const &get_name() { return name; }
  std::string const &get_gender() { return gender; }
  std::string const &get_class() { return Class::className; }
};

// any weapon/armour => magic too, but no other sort of magic
// as they increase in level => harder to kill (increase their hit dice)
// increased ability to get hits at lvl >= 4
class FightingMan : public Charectar<classes::Fighter, FightingMan> {
  FightingMan(std::string &&name, std::string gender)
      : Charectar<classes::Fighter, FightingMan>(std::move(name),
                                                 std::move(gender), 8) {}
};

// resistant to magicm, better saving throws against magical attack.
// 60ft night vision
// construction time is 1/3
// only one who can wield +3 magic war hammer
class Dwarf : public Charectar<classes::Fighter, Dwarf> {
public:
  Dwarf(std::string &&name, std::string gender)
      : Charectar<classes::Fighter, Dwarf>(std::move(name), std::move(gender),
                                           8) {}
};

// humans who elect to become
// magic-users must not wear armor and can carry only a
// dagger for protection, use any magic item
// only one spell at low levels, 2 at higher level
class MagicMan : public Charectar<classes::MagicUser, MagicMan> {
  MagicMan(std::string &&name, std::string gender)
      : Charectar<classes::MagicUser, MagicMan>(std::move(name),
                                                std::move(gender), 6) {}
};

// can use all the weapons and armor, including magic ones
// can cast all spells
// 60ft night vision
/*
  Elves progress in level as both fighting men and
  magic-users, but since each game nets them experience in both categories
  equally, they progress more slowly than other characters
*/
class Elf : public Charectar<classes::MagicUser, Elf> {
  Elf(std::string &&name, std::string gender)
      : Charectar<classes::MagicUser, Elf>(std::move(name), std::move(gender),
                                           6) {}
};

// nothing stronger than leather armor and can not carry shields
// all the weapons of a fighting man including magic swords and magic daggers.
// lvl >= 3 can read 80% stuff
class Theif : public Charectar<classes::Thief, Theif> {
  Theif(std::string &&name, std::string gender)
      : Charectar<classes::Thief, Theif>(std::move(name), std::move(gender),
                                         6) {}
};

// TODO Cleric
// TODO halfling

int main() {
  AttributeManager a(abilities::Strength{});
  return 0;
}