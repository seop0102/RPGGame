#include "Character.h"
#include "Item.h"
#include "IClass.h"
#include "Utils.h"
#include "Monster.h"
#include "ICombatant.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <map>

Character::Character(std::string name, IClass* selectedClass)
	: name(name),
	level(1),
	health(200),
	maxHealth(200),
	attack(30),
	defense(10), // �⺻ ���� ���� (�ʿ��)
	criticalChance(10), // �⺻ ġ��Ÿ Ȯ�� (�ʿ��)
	hitChance(85), // �⺻ ���߷� ���� (�ʿ��)
	dodgeChance(5), // �⺻ ȸ���� ���� (�ʿ��)
	exp(0),
	gold(0),
	equippedWeapon(nullptr), equippedArmor(nullptr)
{
	characterClass = selectedClass;
}

void Character::displayStat()
{
	std::cout << "--------���� â--------" << std::endl;
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "����: " << level << std::endl;
	std::cout << "ü��: " << health << "/" << maxHealth << std::endl;
	std::cout << "���ݷ�: " << attack << std::endl;
	std::cout << "����ġ: " << exp << std::endl;
	std::cout << "���: " << gold << std::endl;
	std::cout << "----------------------" << std::endl;
}

void Character::levelUp()
{
	const int MAX_LEVEL = 10;
	const int EXP_TO_NEXT_LEVEL = level * 100;

	if (level >= MAX_LEVEL) {
		std::cout << "10������ �����߽��ϴ�!" << std::endl;
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

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
	}
}

// ��� �߰� �Լ�
void Character::addGold(int amount)
{
    gold += amount;
    std::cout << amount << " G�� ȹ���߽��ϴ�. ���� ���: " << gold << std::endl;
}

// ����ġ �߰� �Լ�
void Character::addExp(int amount)
{
    exp += amount;
    std::cout << amount << " ����ġ�� ȹ���߽��ϴ�. ���� ����ġ: " << exp << std::endl;
    // ����ġ ȹ�� �� ������ üũ
    levelUp();
}

// ��� ���� �Լ�
void Character::removeGold(int amount)
{
    if (gold >= amount) {
        gold -= amount;
        std::cout << amount << " G�� ����߽��ϴ�. ���� ���: " << gold << std::endl;
    }
    else {
        std::cout << "��尡 �����մϴ�." << std::endl;
    }
}

// ������ �߰� �Լ�
void Character::addItem(Item* item)
{
	if (inventory.size() >= 10) { // �κ��丮 �ִ� 10�� ������
		showInventory();
		std::cout << "�κ��丮�� ���� á���ϴ�. �ٸ� �������� �����ðڽ��ϱ�?" << std::endl;
		
		//������ �߰� ����
		int index = 0;
		item; // ������ ���� ���
		swap(item, inventory[index]); // ������ �����۰� ��ü

		delete item;
	
	}

    inventory.push_back(item);
    std::cout << item->getName() << "��(��) �κ��丮�� �߰��߽��ϴ�." << std::endl;
}

// ������ ���� �Լ�
void Character::removeItem(int index)
{
    if (index >= 0 && index < inventory.size()) {
        std::cout << inventory[index]->getName() << "��(��) �κ��丮���� �����߽��ϴ�." << std::endl;
        inventory.erase(inventory.begin() + index);
    }
    else {
        std::cout << "�߸��� ������ �ε����Դϴ�." << std::endl;
    }
}

void Character::showInventory() const
{
	for (Item* i : inventory)
	{
		//������ ���� ���
	}

}

void Character::equipWeapon(WeaponItem* weapon) {
	if (equippedWeapon != nullptr)
	{
		swap(equippedWeapon, weapon); // ���� ����� ��ü
	}
	else
	{
		equippedWeapon = weapon; // ���� ����
	}
}

void Character::equipArmor(ArmorItem* armor)
{
	if (equippedWeapon != nullptr)
	{
		swap(equippedArmor, armor); // ���� ���� ��ü
	}
	else
	{
		equippedArmor = armor; // �� ����
	}
}

void Character::useItem(int itemindex) {
    if (inventory.empty() || itemindex < 0 || itemindex >= inventory.size())
    {
	    std::cout << "�߸��� ������ �ε����Դϴ�." << std::endl;
	    return;
    }

    EdibleItem* edible = dynamic_cast<EdibleItem*>(inventory[itemindex]);

    if (edible)
    {
	    edible->use(); // ������ ���
    }
    else
    {
	    std::cout << "����� �� ���� �������Դϴ�." << std::endl;
	    return;

    }

    removeItem(itemindex); // ������ ��� �� �κ��丮���� ����
}



std::vector<std::string> Character::getActiveSkills() const {
	if (characterClass) return characterClass->getActiveSkills();
	return {};
}

void Character::useSkill(const std::string& skillName, Character& self, Monster& target) { // <-- std::string ���� Ȯ��
	if (characterClass) {
		// ��ų ��� Ƚ�� Ȯ�� (��: 1ȸ�� ��ų)
		// ���� Ű�� std::string�̹Ƿ�, skillName���� ���� ����
		if (skillUsages.count(skillName) && skillUsages[skillName] > 0) { // <-- std::string Ű ���� Ȯ��
			characterClass->useSkill(skillName, self, target); // ���� ��ų ȿ�� ����

			// 1ȸ�� ��ų�� ��� �� Ƚ�� ���� (��ų �̸��� string���� ��)
			if (skillName == "����" || skillName == "��Ƽ��" || skillName == "���� ȭ��") {
				skillUsages[skillName]--; // <-- std::string Ű ���� Ȯ��
				std::cout << skillName << " ���! ���� Ƚ��: " << skillUsages[skillName] << "ȸ." << std::endl;
			}
		}
		else if (skillUsages.count(skillName) && skillUsages[skillName] == 0) {
			std::cout << "��ų '" << skillName << "'�� ��� Ƚ���� ��� �����߽��ϴ�." << std::endl;
		}
		else { // ������ ��ų (�⺻ ���� ��)
			characterClass->useSkill(skillName, self, target);
		}
	}
}
void Character::applyPassiveSkill(Character& self) {
	if (characterClass) characterClass->applyPassiveSkill(self);
}

std::string Character::getClassName() const {
	if (characterClass) return characterClass->getClassName();
	return "�˼� ����";
}

// ��ų ��� Ƚ�� �ʱ�ȭ �Լ�
void Character::initializeSkillUsages() {
	skillUsages.clear(); // ���� �����͸� ����ϰ� �ʱ�ȭ

	// ��ų �̸��� �ʱ� ��� Ƚ���� ���� ���ڿ� Ű�� ����
	// �� ������ ��ų�� ���⿡ ��������� �߰��մϴ�.
	// ���� enum �� ��� ���� ��ų �̸��� ����մϴ�.

	// ���� ��ų
	skillUsages["�⺻ ����"] = 99; // ������

	// ���� ��ų
	skillUsages["����"] = 99;
	skillUsages["����"] = 99;
	skillUsages["��Ÿ"] = 99;
	skillUsages["��Ƽ��"] = 1; // 1ȸ ����

	// �ü� ��ų
	skillUsages["ȭ�� ����"] = 99;
	skillUsages["����"] = 99;
	skillUsages["��ǳ ȭ��"] = 99;
	skillUsages["���� ȭ��"] = 1; // 1ȸ ����

	// ���� ��ų
	skillUsages["����"] = 99;
	skillUsages["������ ��"] = 99;
	skillUsages["�޽�"] = 99;
	skillUsages["����"] = 1; // 1ȸ ����

	// (�ʿ��ϴٸ� ���⿡ �� ���� ��ų�� ��� Ƚ���� �߰�)
}

// ��ų ��� Ƚ�� ���� �Լ�
void Character::restoreSkillUsage(const std::string& skillName, int amount) {
	if (skillUsages.count(skillName)) { // skillUsages �ʿ� skillName�� �ִ��� Ȯ��
		if (skillUsages.at(skillName) != 99) { // ������ ��ų�� �ƴ� ��쿡�� ����
			skillUsages[skillName] += amount;
			std::cout << skillName << " ��ų ��� Ƚ���� " << amount << "��ŭ ȸ���Ǿ����ϴ�. ���� " << skillUsages[skillName] << "ȸ." << std::endl;
		}
		else {
			std::cout << skillName << " ��ų�� �������Դϴ�." << std::endl;
		}
	}
	else {
		std::cout << "�� �� ���� ��ų�̰ų� ��� Ƚ���� ������ �� ���� ��ų�Դϴ�." << std::endl;
	}
}

// ���� ��ų ��� Ƚ�� ��ȯ �Լ�
int Character::getRemainingSkillUsage(const std::string& skillName) const {
	if (skillUsages.count(skillName)) { // skillUsages �ʿ� skillName�� �ִ��� Ȯ��
		return skillUsages.at(skillName); // �ش� ��ų�� ���� Ƚ�� ��ȯ
	}
	return 0; // �ش� ��ų�� ������ 0 ��ȯ (�Ǵ� ���� ó��)
}

// ��ų Ÿ�Կ� ���� �̸� ��ȯ �Լ�
std::string Character::getSkillName(const std::string& skillName) const {
	// ��ų �̸��� �̹� ���ڿ��̹Ƿ�, �״�� ��ȯ�մϴ�.
	// ������ switch ���� SkillType enum�� string���� ��ȯ�ϴ� ������ ������,
	// ���� ��ų �̸� ��ü�� string�̹Ƿ� �ʿ� �������ϴ�.
	return skillName;
}