#include "Goblin.h"
#include "Monster.h"

Monster01::Monster01(int level) {
    name = "Monster01";
    health = 40 + (level * 10);
    attack = 17 + (level * 3);
}

std::string Monster01::getName() const { return name; }
int Monster01::getHealth() const { return health; }
int Monster01::getAttack() const { return attack; }

void Monster01::takeDamage(int damage) { Monster::takeDamage(damage); }