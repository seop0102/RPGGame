#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
// #include "Item.h" // ���� Item Ŭ���� ���� �� �ּ� ���� 


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
			std::cout << "��� : ĳ���� �̸��� ����ֽ��ϴ�. �⺻ �̸����� �����մϴ�." << std::endl;
			instance = new Character("�÷��̾�");
		}
		else {
			instance = new Character(name);
		}
	}
	return instance;
}

void Character::displayStat()
{
	std::cout << "-----" << name << "�� ���� â---- - " << name << std::endl;
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "����: " << level << std::endl;
	std::cout << "ü��: " << health << "/" << maxHealth << std::endl;
	std::cout << "���ݷ�: " << attack << std::endl;
	std::cout << "����ġ: " << exp << std::endl;
	std::cout << "���: " << gold << std::endl;
}

void Character::levelUp()
{
	const int MAX_LEVEL = 10;
	const int EXP_TO_NEXT_LEVEL = level * 100;

	if (level >= 10) {
		std::cout << "�ִ� ������ �����߽��ϴ�!" << std::endl;
		return;
	}

	if (exp >= EXP_TO_NEXT_LEVEL) {
		level++;
		exp -= EXP_TO_NEXT_LEVEL;

		maxHealth += 20; // �ִ� ü�� ����
		health = maxHealth; // ü�� ȸ��
		attack += 5; // ���ݷ� ����

		std::cout << "���� �� :" << level << "��(��) �Ǿ����ϴ�." << std::endl;
		std::cout << "�ִ� ü�� +20, ���ݷ� +5 ����" << std::endl;
	}
	else {
		std::cout << "����ġ�� �����մϴ�. ���� ������ ���� " << (EXP_TO_NEXT_LEVEL - exp) << "����ġ�� �� �ʿ��մϴ�." << std::endl;
	}
}

void Character::useItem(int itemIndex)
{

}
