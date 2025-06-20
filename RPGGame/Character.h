#pragma once

#include<string>
#include<vector>
#include<iostream>

class Item;

class Character {
private:

	static Character* instance;
	Character(std::string name);
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	std::string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int exp;
	int gold;

	std::vector<Item> inventory;

public:
	static Character* getInstance(std::string name = "");

	void displayStat();
	void levelUp();
	void useItem(int itemIndex);
	void takeDamage(int damage);

	// 게터 함수
	std::string getName() const { return name; }
	int getLevel() const { return level; }
	int getHealth() const { return health; }
	int getMaxHealth() const { return maxHealth; }
	int getAttack() const { return attack; }
	int getExp() const { return exp; }
	int getGold() const { return gold; }

	// 세터 함수
	void setHealth(int newHealth) { health = newHealth; }
	void addExp(int amount) { exp += amount; }
	void addGold(int amount) { gold += amount; }
	void removeGold(int amount) { gold -= amount; }

	~Character();

	// void addItem(const Item& item);
	// void removeItem(int index);
};