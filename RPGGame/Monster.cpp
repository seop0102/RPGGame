#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>

// �޴� ������
// 30%Ȯ���� ������ ��� �߰� �ؾ� ��


void Monster::takeDamage(int damage) 
{
    health -= damage;
    if (health <= 0) 
    {
        health = 0;
    }
}

void Monster::setHealth(int health)
{
	this->health = health;
}

void Monster::setAttack(int attack)
{
	this->attack = attack;
}

//���� ����
void Monster::status() const 
{
    std::cout << "[ " << name << " ]\n"
        << "ü�� : " << health
        << " ���ݷ� : " << attack << "\n";
}

// 1~100 ������ ���� ��� ��ȯ(�ӽ�)
int Monster::getGold() const 
{
    return rand() % 100 + 1;
}


Item* Monster::dropItem() const
{
        srand(time(0));
        int chance = rand() % 100;
        Item* item = nullptr;

        if (chance < 30)
        {
                int randItem = rand() % 3; // 0: ����, 1: ��, 2: �Ҹ�ǰ
                switch (randItem)
                {
                case 0:
                {
                        int randWeapon = rand() % 2;
                        if (randWeapon == 0)
                        {
                                item = new WeaponItem("ö��", ItemTier::NORAML, 3, 100);
                        }
                        else
                        {
                                item = new WeaponItem("������", ItemTier::RARE, 4, 100);
                        }
                        return item;
                }
                case 1:
                {
                        int randArmor = rand() % 2;
                        if (randArmor == 0)
                        {
                                item = new ArmorItem("����", ItemTier::RARE, 5, 0, 100);
                        }
                        else
                        {
                                item = new ArmorItem("����", ItemTier::EPIC, 10, 3, 100);
                        }
                        return item;
                }
                case 2:
                {
                        int randEdible = rand() % 2;
                        if (randEdible == 0)
                        {
                                item = new EdibleItem("ȸ�� ����", ItemTier::NORAML, 50, 2, 0, 100);
                        }
                        else
                        {
                                item = new EdibleItem("ȸ�� ����", ItemTier::RARE, 100, 4, 0, 100);
                        }
                        return item;
                }
                }
        }
        else
        {
                return item;
        }
}
