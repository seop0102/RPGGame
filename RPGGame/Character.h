#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<map> // ���� �����̳� Key, Value 
#include<memory> // unique_ptr 
#include "IClass.h"
#include "ICombatant.h"
#include "Item.h"

class Monster;

class Character : public ICombatant {
private:
	std::string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int defense;

	int criticalChance;
	int hitChance; 
	int dodgeChance; // ȸ����

	int exp;
	int gold;

	std::vector<Item> inventory;

	// ���� ��ü 
	std::unique_ptr<IClass> characterClass;

	// ��ų ��� Ƚ��
	std::map<SkillType, int> skillUsages;

	// ��ų ȿ��
	bool hasSurvivedThisTurn; // ������, ��Ƽ�� (�ϴ� 1ȸ)
	bool isShielded; // ������, ���� (�ϴ� 1ȸ)
	bool isHiding; // ����, ���� (1ȸ��)
	bool isAimed; // �ü�, ���� (���� ���� ���߷� ����)
	int wraithArrowDamage; // �ü�, ���� ȭ�� (���� �� ���� ���ط� ����)
	bool hasIndomitableWill; // ������ �нú� 

public:
	Character(std::string name, std::unique_ptr<IClass> selectedClass);

// ICombatant �������̽�
	void takeDamage(int damage) override;
	int getAttack() const override { return attack; }
	int getHealth() const override { return health; }
	std::string getName() const override { return name; }
	bool isAlive() const override { return health > 0; }
	int getDefense() const override { return defense; }
	int getDodgeChance() const override { return dodgeChance; }

	std::vector<SkillType> getActiveSkills() const {
		if (characterClass) return characterClass->getActiveSkills();
		return {};
	}
	void useSkill(SkillType skillType, Character& self, Monster& target) {
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
	void applyPassiveSkill(Character& self)  {
		if (characterClass) characterClass->applyPassiveSkill(self);
	}
	std::string getClassName() const  {
		if (characterClass) return characterClass->getClassName();
		return "�˼� ����";
	}

	// ĳ���� ���
	void displayStat();
	void levelUp();
	void useItem(int itemIndex);

	// ��� / ����ġ / ������ ���� 
	void addGold(int amount);
	void addExp(int amount);
	void removeGold(int amount);
	void addItem(const Item& item);
	void removeItem(int index);

	// ��ų ��� Ƚ��
	void initializeSkillUsages();
	void restoreSkillUsage(SkillType skillType, int amount);
	int getRemainingSkillUsage(SkillType skillType) const;
	std::string getSkillName(SkillType skillType) const; // ��ų Ÿ��-> �̸� ��ȯ
		 
	// ���� �Լ�
	std::string getName() const { return name; }
	int getLevel() const { return level; }
	int getHealth() const { return health; }
	int getMaxHealth() const { return maxHealth; }
	int getAttack() const { return attack; }
	int getExp() const { return exp; }
	int getGold() const { return gold; }
	int getDefense() const override { return defense; }
	int getDodgeChance() const override { return dodgeChance; }
	int getHitChance() const { return hitChance; }
	bool isAlive() const override { return health > 0; }

	// ��ų ȿ�� ����/����
	void setHasSurvivedThisTurn(bool val) { hasSurvivedThisTurn = val; }
	bool getHasSurvivedThisTurn() const { return hasSurvivedThisTurn; }
	void setIsShielded(bool val) { isShielded = val; }
	bool getIsShielded() const { return isShielded; }
	void setIsHiding(bool val) { isHiding = val; }
	bool getIsHiding() const { return isHiding; }
	void setIsAimed(bool val) { isAimed = val; }
	bool getIsAimed() const { return isAimed; }
	void setWraithArrowDamage(int val) { wraithArrowDamage = val; }
	int getWraithArrowDamage() const { return wraithArrowDamage; }
	void setHasIndomitableWill(bool val) { hasIndomitableWill = val; }
	bool getHasIndomitableWill() const { return hasIndomitableWill; }

	// ���� �Լ�
	void setHealth(int newHealth) { health = newHealth; }
	void setMaxHealth(int newMaxHealth) { maxHealth = newMaxHealth; }
	void setAttack(int newAttack) { attack = newAttack; }
	void setDefense(int newDefense) { defense = newDefense; }
	void setCriticalChance(int chance) { criticalChance = chance; }
	void setHitChance(int chance) { hitChance = chance; }
	void setDodgeChance(int chance) { dodgeChance = chance; }
	void setGold(int newGold) { gold = newGold; } // ���� ��ų ��� �ʿ�

};