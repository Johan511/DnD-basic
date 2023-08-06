using ItemCostTy = int;

class Item {
protected:
  //   ItemCostTy const cost; // keep cost at static constexpr in derived class
  ItemCostTy const cost;

  ItemCostTy get_cost() { return cost; }

  constexpr Item(ItemCostTy cost_) : cost(cost_){};
};

class Dagger : Item {
  static constexpr ItemCostTy cost_ = 3;

public:
  Dagger() : Item(cost_){};
};
class HandAxe : Item {
  static constexpr ItemCostTy cost_ = 3;

public:
  HandAxe() : Item(cost_){};
};
class Mace : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  Mace() : Item(cost_){};
};
class Sword : Item {
  static constexpr ItemCostTy cost_ = 10;

public:
  Sword() : Item(cost_){};
};
class BattleAxe : Item {
  static constexpr ItemCostTy cost_ = 7;

public:
  BattleAxe() : Item(cost_){};
};
class MorningStar : Item {
  static constexpr ItemCostTy cost_ = 6;

public:
  MorningStar() : Item(cost_){};
};
class Flail : Item {
  static constexpr ItemCostTy cost_ = 8;

public:
  Flail() : Item(cost_){};
};
class Spear : Item {
  static constexpr ItemCostTy cost_ = 2;

public:
  Spear() : Item(cost_){};
};
class PoleArm : Item {
  static constexpr ItemCostTy cost_ = 7;

public:
  PoleArm() : Item(cost_){};
};
class Halberd : Item {
  static constexpr ItemCostTy cost_ = 7;

public:
  Halberd() : Item(cost_){};
};
class TwoHandedSword : Item {
  static constexpr ItemCostTy cost_ = 15;

public:
  TwoHandedSword() : Item(cost_){};
};
class Lance : Item {
  static constexpr ItemCostTy cost_ = 4;

public:
  Lance() : Item(cost_){};
};
class Pike : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  Pike() : Item(cost_){};
};
class ShortBow : Item {
  static constexpr ItemCostTy cost_ = 25;

public:
  ShortBow() : Item(cost_){};
};
class LongBow : Item {
  static constexpr ItemCostTy cost_ = 40;

public:
  LongBow() : Item(cost_){};
};
class CompositeBow : Item {
  static constexpr ItemCostTy cost_ = 50;

public:
  CompositeBow() : Item(cost_){};
};
class LightCrossbow : Item {
  static constexpr ItemCostTy cost_ = 15;

public:
  LightCrossbow() : Item(cost_){};
};
class HeavyCrossbow : Item {
  static constexpr ItemCostTy cost_ = 25;

public:
  HeavyCrossbow() : Item(cost_){};
};
class Arrows20 : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  Arrows20() : Item(cost_){};
};
class Quarrels30 : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  Quarrels30() : Item(cost_){};
};
class SilverTippedArrow : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  SilverTippedArrow() : Item(cost_){};
};
class Mule : Item {
  static constexpr ItemCostTy cost_ = 20;

public:
  Mule() : Item(cost_){};
};
class DraftHorse : Item {
  static constexpr ItemCostTy cost_ = 30;

public:
  DraftHorse() : Item(cost_){};
};
class LightHorse : Item {
  static constexpr ItemCostTy cost_ = 40;

public:
  LightHorse() : Item(cost_){};
};
class WarhorseMedium : Item {
  static constexpr ItemCostTy cost_ = 100;

public:
  WarhorseMedium() : Item(cost_){};
};
class WarhorseHeavy : Item {
  static constexpr ItemCostTy cost_ = 200;

public:
  WarhorseHeavy() : Item(cost_){};
};
class Saddle : Item {
  static constexpr ItemCostTy cost_ = 25;

public:
  Saddle() : Item(cost_){};
};
class SaddleBags : Item {
  static constexpr ItemCostTy cost_ = 10;

public:
  SaddleBags() : Item(cost_){};
};
class Cart : Item {
  static constexpr ItemCostTy cost_ = 100;

public:
  Cart() : Item(cost_){};
};
class Wagon : Item {
  static constexpr ItemCostTy cost_ = 200;

public:
  Wagon() : Item(cost_){};
};
class Raft : Item {
  static constexpr ItemCostTy cost_ = 40;

public:
  Raft() : Item(cost_){};
};
class SmallBoat : Item {
  static constexpr ItemCostTy cost_ = 100;

public:
  SmallBoat() : Item(cost_){};
};
class LeatherArmor : Item {
  static constexpr ItemCostTy cost_ = 15;

public:
  LeatherArmor() : Item(cost_){};
};
class ChainTypeMail : Item {
  static constexpr ItemCostTy cost_ = 30;

public:
  ChainTypeMail() : Item(cost_){};
};
class PlateMail : Item {
  static constexpr ItemCostTy cost_ = 50;

public:
  PlateMail() : Item(cost_){};
};
class Helmet : Item {
  static constexpr ItemCostTy cost_ = 10;

public:
  Helmet() : Item(cost_){};
};
class Shield : Item {
  static constexpr ItemCostTy cost_ = 10;

public:
  Shield() : Item(cost_){};
};
class HorseArmor : Item {
  static constexpr ItemCostTy cost_ = 150;

public:
  HorseArmor() : Item(cost_){};
};
class Rope : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  Rope() : Item(cost_){};
};
class Pole : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  Pole() : Item(cost_){};
};
class IronSpikes12 : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  IronSpikes12() : Item(cost_){};
};
class SmallSack : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  SmallSack() : Item(cost_){};
};
class LargeSack : Item {
  static constexpr ItemCostTy cost_ = 2;

public:
  LargeSack() : Item(cost_){};
};
class LeatherBackPack : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  LeatherBackPack() : Item(cost_){};
};
class WaterOrWineSkin : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  WaterOrWineSkin() : Item(cost_){};
};
class Torches6 : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  Torches6() : Item(cost_){};
};
class Lantern : Item {
  static constexpr ItemCostTy cost_ = 10;

public:
  Lantern() : Item(cost_){};
};
class FlaskOfOil : Item {
  static constexpr ItemCostTy cost_ = 2;

public:
  FlaskOfOil() : Item(cost_){};
};
class TinderBox : Item {
  static constexpr ItemCostTy cost_ = 3;

public:
  TinderBox() : Item(cost_){};
};
class StakesAndMallet : Item {
  static constexpr ItemCostTy cost_ = 3;

public:
  StakesAndMallet() : Item(cost_){};
};
class SteelMirror : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  SteelMirror() : Item(cost_){};
};
class SilverMirror : Item {
  static constexpr ItemCostTy cost_ = 15;

public:
  SilverMirror() : Item(cost_){};
};
class WoodenCross : Item {
  static constexpr ItemCostTy cost_ = 2;

public:
  WoodenCross() : Item(cost_){};
};
class SilverCross : Item {
  static constexpr ItemCostTy cost_ = 25;

public:
  SilverCross() : Item(cost_){};
};
class HolyWater : Item {
  static constexpr ItemCostTy cost_ = 25;

public:
  HolyWater() : Item(cost_){};
};
class Wolvesbane : Item {
  static constexpr ItemCostTy cost_ = 10;

public:
  Wolvesbane() : Item(cost_){};
};
class Garlic : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  Garlic() : Item(cost_){};
};
class Wine : Item {
  static constexpr ItemCostTy cost_ = 1;

public:
  Wine() : Item(cost_){};
};
class IronRations : Item {
  static constexpr ItemCostTy cost_ = 15;

public:
  IronRations() : Item(cost_){};
};
class StandardRations : Item {
  static constexpr ItemCostTy cost_ = 5;

public:
  StandardRations() : Item(cost_){};
};
