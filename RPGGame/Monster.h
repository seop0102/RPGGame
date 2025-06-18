#pragma once
#include <string>

class Monster {
protected:
    std::string name;
    int health;
    int attack;

public:
    virtual ~Monster() = default;

    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int damage);

    virtual void status() const;

    virtual int getGold() const;
};