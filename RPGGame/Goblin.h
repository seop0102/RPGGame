#pragma once
#include "Monster.h"

//이름 바꿔야 함
class Goblin : public Monster {
public:
    Goblin(int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};