#pragma once

#include<string>
#include<vector>
#include<iostream>


class Item;

class Character {
private:
	std::string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int exp;
	int gold;

	std::vector<Item> inventory;

public:
	Character(std::string name);

	void displayStat();
	void levelUp();
	void useItem(int itemIndex);
	void takeDamage(int damage);

	std::string getName() const { return name; }
	int getLevel() const { return level; }
	int getHealth() const { return health; }
	int getMaxHealth() const { return maxHealth; }
	int getAttack() const { return attack; }
	int getExp() const { retrun exp; }
	int getGold() const { return gold; }

	void setHealth(int newHealth) { exp += amount; }
	void addExp(int amount) { gold += amount; }
	void removeGold(int amount) { gold -= amount; }

	// void addItem(const Item& item);
	// void removeItem(int index);
};