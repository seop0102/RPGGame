#pragma once

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Item;

class Character {

private:
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int exp;
	int gold;

	vector<Item> inventory;

public:
	Character(string name);

	void displayStat();
	void levelUp();
	void useItem(int itemIndex);

};