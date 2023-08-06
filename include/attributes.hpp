#include <cstdint>
#include <string>

#pragma once

using AttrNumTy = int;

typedef enum RollTy_ { ONE, TWO, THREE, FOUR, FIVE, SIX } RollTy;
constexpr RollTy RollMaxSize = static_cast<RollTy>(6);

namespace abilities {
class Strength {};
class Intelligence {};
class Wisdom {};
class Constitution {};
class Dexterity {};
class Charisma {};
}; // namespace abilities

namespace classes {
class Fighter {
  using PrimeRequisite = abilities::Strength;

public:
  static const std::string className;
};
const std::string Fighter::className = "Fighter";

class MagicUser {
  using PrimeRequisite = abilities::Intelligence;

public:
  static const std::string className;
};
const std::string MagicUser::className = "MagicUser";

class Thief {
  using PrimeRequisite = abilities::Dexterity;

public:
  static const std::string className;
};
const std::string Thief::className = "Thief";

}; // namespace classes

class Attributes {
  // Specific Attributes
  enum AttrIndex {
    STRENGTH,
    INTELLIGENCE,
    WISDOM,
    CONSTITUTION,
    DEXTERITY,
    CHARISMA
  };

  friend class AttributeManager;

  AttrNumTy attributes[6] = {};
};

class AttributeManager {
private:
  Attributes attr;
  // when init reduced to 0 then all attributes are initialised
  // else we are in UB
  std::uint8_t init = (1 << 7 - 1);
  Attributes::AttrIndex const PrimeRequisite;

  template <typename PrimReqTy>
  constexpr Attributes::AttrIndex get_PrimeRequisite(PrimReqTy) {
    // no branching due to constexpr
    if constexpr (std::is_same<abilities::Strength, PrimReqTy>::value)
      return static_cast<Attributes::AttrIndex>(Attributes::STRENGTH);

    else if constexpr (std::is_same<abilities::Intelligence, PrimReqTy>::value)
      return static_cast<Attributes::AttrIndex>(Attributes::INTELLIGENCE);

    else if constexpr (std::is_same<abilities::Dexterity, PrimReqTy>::value)
      return static_cast<Attributes::AttrIndex>(Attributes::DEXTERITY);
  }

public:
  template <typename PrimReqTy>
  constexpr AttributeManager(PrimReqTy x)
      : PrimeRequisite(get_PrimeRequisite(x)) {}

  /////////////////////////////////////////////////////

  void set_idx(Attributes::AttrIndex idx, AttrNumTy x) {
    attr.attributes[idx] = x;
  }

  void set_strength(AttrNumTy x) {
    init &= (1 << Attributes::STRENGTH);
    set_idx(Attributes::STRENGTH, x);
  }
  void set_intelligence(AttrNumTy x) {
    init &= (1 << Attributes::INTELLIGENCE);
    set_idx(Attributes::INTELLIGENCE, x);
  }
  void set_wisdom(AttrNumTy x) {
    init &= (1 << Attributes::WISDOM);
    set_idx(Attributes::WISDOM, x);
  }
  void set_constitution(AttrNumTy x) {
    init &= (1 << Attributes::CONSTITUTION);
    set_idx(Attributes::CONSTITUTION, x);
  }
  void set_dexterity(AttrNumTy x) {
    init &= (1 << Attributes::DEXTERITY);
    set_idx(Attributes::DEXTERITY, x);
  }
  void set_charisma(AttrNumTy x) {
    init &= (1 << Attributes::CHARISMA);
    set_idx(Attributes::CHARISMA, x);
  }
  void set_prime_req(AttrNumTy x) { set_idx(PrimeRequisite, x); }

  //////////////////////////////////////////////////////

  AttrNumTy get_idx(Attributes::AttrIndex idx) const {
    return attr.attributes[idx];
  }

  AttrNumTy get_strength() const { return get_idx(Attributes::STRENGTH); }
  AttrNumTy get_intelligence() const {
    return get_idx(Attributes::INTELLIGENCE);
  }
  AttrNumTy get_wisdom() const { return get_idx(Attributes::WISDOM); }
  AttrNumTy get_constitution() const {
    return get_idx(Attributes::CONSTITUTION);
  }
  AttrNumTy get_dexterity() const { return get_idx(Attributes::DEXTERITY); }
  AttrNumTy get_charisma() const { return get_idx(Attributes::CHARISMA); }
  AttrNumTy get_prime_req() const { return get_idx(PrimeRequisite); }

  //////////////////////////////////////////////////////

  /*
  Constitution and charisma can not be altered, and
  dexterity can not be reduced.
  */

  // ratio is from:to, assumed to be integral
  bool transfer_attribute(Attributes::AttrIndex from, Attributes::AttrIndex to,
                          int ratio) {
    AttrNumTy currFrom = get_idx(from);
    AttrNumTy currTo = get_idx(to);

    //  In no case can any ability be lowered below 9
    if (currFrom >= ratio + 9) {
      set_idx(from, currFrom - ratio);
      set_idx(to, currTo + 1);
      return true;
    }
    return false;
  }

  // only for magic-users and clerics
  bool str_to_prime_req(int ratio = 3) {
    return transfer_attribute(Attributes::STRENGTH, PrimeRequisite, ratio);
  }

  // pg 6
  // only for fighting men, clerics, halflings and dwarves
  // thieves too
  bool intell_to_prime_req(int ratio = 2) {
    return transfer_attribute(Attributes::INTELLIGENCE, PrimeRequisite, ratio);
  }

  // pg 6
  // only for fighting men, halflings and dwarves ratio = 3
  // for magic-users ratio is 2
  bool wisdom_to_prime_req(int ratio) {
    return transfer_attribute(Attributes::WISDOM, PrimeRequisite, ratio);
  }
};