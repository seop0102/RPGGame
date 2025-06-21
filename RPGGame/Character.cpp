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
			std::cout << "��� : ĳ���� �̸��� ����ֽ��ϴ�. �⺻ �̸����� �����մϴ�. \n";
			instance = new Charater("�÷��̾�");
		}
		else {
			instance = new Character(name);
		}
	}
	return instance;
}

void Character::displayStat()
{
	cout << "----- ���� â -----" << name << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << level << endl;
	cout << "ü��: " << health << "/" << maxHealth << endl;
	cout << "���ݷ�: " << attack << endl;
	cout << "����ġ: " << exp << endl;
	cout << "���: " << gold << endl;
}

void Character::levelUp()
{
	const int MAX_LEVEL = 10;
	const int EXP_TO_NEXT_LEVEL = level * 100;

	if (level >= 10) {
		cout << "�ִ� ������ �����߽��ϴ�!" << endl;
		return;
	}

	if (exp >= EXP_TO_NEXT_LEVEL) {
		level++;
		exp -= EXE_TO_NEXT_LEVEL;

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
