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

Character::Character(std::string name, std::unique_ptr<IClass> selectedClass)
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
	characterClass(std::move(selectedClass)), // Unique_ptr �ʱ�ȭ
	hasSurvivedThisTurn(false),
	isShielded(false),
	isHiding(false),
	isAimed(false),
	wraithArrowDamage(0), // int�� �ʱ�ȭ
	hasIndomitableWill(false)
{
	// �ʱ� ��ų ��� Ƚ�� ����
	initializeSkillUsages();
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

void Character::useItem(int itemIndex)
{

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
void Character::addItem(const Item& item)
{
    inventory.push_back(item);
    std::cout << item.getName() << "��(��) �κ��丮�� �߰��߽��ϴ�." << std::endl;
}

// ������ ���� �Լ�
void Character::removeItem(int index)
{
    if (index >= 0 && index < inventory.size()) {
        std::cout << inventory[index].getName() << "��(��) �κ��丮���� �����߽��ϴ�." << std::endl;
        inventory.erase(inventory.begin() + index);
    }
    else {
        std::cout << "�߸��� ������ �ε����Դϴ�." << std::endl;
    }
}

vector<SkillType> Character::getActiveSkills() {
	if (characterClass) return characterClass->getActiveSkills();
	return {};
}

void Character::useSkill(SkillType skillType, Character& self, Monster& target) {
	if (characterClass) {
		// ��ų ��� Ƚ�� üũ, ����
		if (skillUsages.count(skillType) && skillUsages[skillType] > 0) {
			characterClass->useSkill(skillType, self, target); // ��ų ȿ�� ����
			// Ư�� ��ų Ƚ�� ������
			if (skillType == SkillType::ROGUE4 || skillType == SkillType::WARRIOR4 || skillType == SkillType::ARCHER4) {
				skillUsages[skillType]--;
			}
		}
		else {
			std::cout << "��ų '" << getSkillName(skillType) << "'�� ��� Ƚ���� �����մϴ�." << std::endl;
		}
	}
}

void Character::applyPassiveSkill(Character & self) {
	if (characterClass) characterClass->applyPassiveSkill(self);
}

string Character::getClassName() {
	if (characterClass) return characterClass->getClassName();
	return "�˼� ����";
}

// ��ų ��� Ƚ�� �ʱ�ȭ �Լ�
void Character::initializeSkillUsages() {
    // ��� ��ų Ÿ���� �����ͼ� �ʱ� ��� Ƚ���� �����մϴ�.
    // �� ������ ��ų ��� Ƚ���� ��� �������� ���� �����ο� ���� �ٸ��ϴ�.
    // ���⼭�� �Ϲ� ��ų�� 99, Ư�� ��ų(����, ��Ƽ��, ���� ȭ��)�� 1�� �����մϴ�.
    for (int i = static_cast<int>(SkillType::ROGUE1); i <= static_cast<int>(SkillType::WARRIOR4); ++i) {
        SkillType type = static_cast<SkillType>(i);
        if (type == SkillType::ROGUE4 || type == SkillType::WARRIOR4 || type == SkillType::ARCHER4) {
            skillUsages[type] = 1; // Ư�� ��ų (����, ��Ƽ��, ���� ȭ��)�� 1ȸ ��� ����
        }
        else {
            skillUsages[type] = 99; // �Ϲ� ��ų�� ������ (�׽�Ʈ ����)
        }
    }
    // BASIC_ATTACK�� ��ų ��� Ƚ�� ������ �����Ƿ� ����
}

// ��ų ��� Ƚ�� ���� �Լ�
void Character::restoreSkillUsage(SkillType skillType, int amount) {
    if (skillUsages.count(skillType)) {
        skillUsages[skillType] += amount;
        std::cout << getSkillName(skillType) << " ��ų ��� Ƚ���� " << amount << "��ŭ ȸ���Ǿ����ϴ�. ���� " << skillUsages[skillType] << "ȸ." << std::endl;
    }
}

// ���� ��ų ��� Ƚ�� ��ȯ �Լ�
int Character::getRemainingSkillUsage(SkillType skillType) const {
    if (skillUsages.count(skillType)) {
        return skillUsages.at(skillType);
    }
    return 0; // �ش� ��ų�� ������ 0 ��ȯ
}

// ��ų Ÿ�Կ� ���� �̸� ��ȯ �Լ�
std::string Character::getSkillName(SkillType skillType) const {
    switch (skillType) {
    case SkillType::BASIC_ATTACK: return "�⺻ ����";
        // ���� ��ų
    case SkillType::ROGUE1: return "����";
    case SkillType::ROGUE2: return "������ ��";
    case SkillType::ROGUE3: return "�޽�";
    case SkillType::ROGUE4: return "����";
        // �ü� ��ų
    case SkillType::ARCHER1: return "ȭ�� ����";
    case SkillType::ARCHER2: return "����";
    case SkillType::ARCHER3: return "��ǳ ȭ��";
    case SkillType::ARCHER4: return "���� ȭ��";
        // ������ ��ų
    case SkillType::WARRIOR1: return "����";
    case SkillType::WARRIOR2: return "����";
    case SkillType::WARRIOR3: return "��Ÿ";
    case SkillType::WARRIOR4: return "��Ƽ��";
    default: return "�� �� ���� ��ų";
    }
}