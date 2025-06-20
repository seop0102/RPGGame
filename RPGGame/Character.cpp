#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
// #include "Item.h" // 추후 Item 클래스 정의 시 주석 해제 


Character* Character::instance = nullptr;

Character::Character(std::string name)
{
	this->name = name;
	level = 1;
	health = 200;
	maxHealth = 200;
	attack = 30;
	exp = 0; 
	gold = 0;
}

Character* Character::getInstance(std::string name)
{
	if (instance == nullptr)
	{
		if (name.empty())
		{
			std::cout << "경고 : 캐릭터 이름이 비어있습니다. 기본 이름으로 설정합니다. \n";
			instance = new Charater("플레이어");
		}
		else {
			instance = new Character(name);
		}
	}
	return instance;
}

void Character::displayStat()
{
	cout << "----- 상태 창 -----" << name << endl;
	cout << "이름: " << name << endl;
	cout << "레벨: " << level << endl;
	cout << "체력: " << health << "/" << maxHealth << endl;
	cout << "공격력: " << attack << endl;
	cout << "경험치: " << exp << endl;
	cout << "골드: " << gold << endl;
}

void Character::levelUp()
{
	const int MAX_LEVEL = 10;
	const int EXP_TO_NEXT_LEVEL = level * 100;

	if (level >= 10) {
		cout << "최대 레벨에 도달했습니다!" << endl;
		return;
	}

	if (exp >= EXP_TO_NEXT_LEVEL) {
		level++;
		exp -= EXE_TO_NEXT_LEVEL;

		maxHealth += 20; // 최대 체력 증가
		health = maxHealth; // 체력 회복
		attack += 5; // 공격력 증가

		std::cout << "레벨 업 :" << level << "이(가) 되었습니다." << std::endl;
		std::cout << "최대 체력 +20, 공격력 +5 증가" << std::endl;
	}
	else {
		std::cout << "경험치가 부족합니다. 다음 레벨업 까지 " << (EXP_TO_NEXT_LEVEL - exp) << "경험치가 더 필요합니다." << std::endl;
	}
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
	}
}

void Character::useItem(int itemIndex)
{

}
