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
	cout << "�̸�: " << name << endl;
	cout << "����: " << name << endl;
	cout << "ü��: " << health << "/" << maxHealth << endl;
	cout << "���ݷ�: " << attack << endl;
	cout << "����ġ: " << exp << endl;
}

void Character::levelUp()
{

}

void Character::useItem(int itemIndex)
{

}
