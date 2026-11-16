#ifndef ARCADE_TROLL_H
#define ARCADE_TROLL_H

#include "monster.h"

/// A large, powerful monster.
class Troll : public Monster {
public:
  Troll();

  int attack_damage() const override;

  /// @return a description of the Troll
  std::string describe() const override;
};

#endif // ARCADE_TROLL_H
