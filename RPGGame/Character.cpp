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
	if (level >= 10) {
		cout << "최대 레벨에 도달했습니다!" << endl;
		return;
	}

	if (exp >= 100) {
		level++;
		exp -= 100;

		maxHealth += 20; // 최대 체력 증가
		health = maxHealth; // 체력 회복

		attack += 5; // 공격력 증가
	}
}

void Character::useItem(int itemIndex)
{

}
