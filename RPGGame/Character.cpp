#include "Character.h"

Character::Character(string name)
{
	this->name = name;
	level = 1;
	health = 200;
	maxHealth = 200;
	attack = 30;
	exp = 0;

}

void Character::displayStat()
{
	cout << "이름: " << name << endl;
	cout << "레벨: " << name << endl;
	cout << "체력: " << health << "/" << maxHealth << endl;
	cout << "공격력: " << attack << endl;
	cout << "경험치: " << exp << endl;
}

void Character::levelUp()
{

}

void Character::useItem(int itemIndex)
{

}
