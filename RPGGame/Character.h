#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<map> // ���� �����̳� Key, Value 

#include "IClass.h"
#include "ICombatant.h"
#include "Item.h"

using namespace std;

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

	WeaponItem* equippedWeapon; // ������ ����
	ArmorItem* equippedArmor; // ������ ��

	std::vector<Item*> inventory;

	// ���� ��ü 
	//std::unique_ptr<IClass> characterClass;
	IClass* characterClass;

	// ��ų ��� Ƚ��
	std::map<std::string, int> skillUsages;

	//��ų���� ����
	bool isAimed; // �ü�, ���� (���� ���� ���߷� ����)
	int wraithArrowDamage; // �ü�, ���� ȭ�� (���� �� ���� ���ط� ����)

	bool isHiding; // ����, ���� (1ȸ��)

	bool isShielded; // ������, ���� (�ϴ� 1ȸ)
	bool hasSurvivedThisTurn; // ������, ��Ƽ�� (�ϴ� 1ȸ)
	bool hasIndomitableWill; // ������ �нú� 



public:
	Character(std::string name, IClass* selectedClass);

// ICombatant �������̽�
	void takeDamage(int damage) override;
	int getAttack() const override { return attack; }
	int getHealth() const override { return health; }
	string getName() const override { return name; }
	int getDefense() const { return defense; } // ���� ��ȯ
	int getDodgeChance() const { return dodgeChance; } // ȸ���� ��ȯ

	std::vector<std::string> getActiveSkills() const;
	void useSkill(const std::string& skillName, Character& self, Monster& target);
	void applyPassiveSkill(Character& self);
	std::string getClassName() const;

	bool isAlive() const { return health > 0;} // ��Ҵ��� �׾����� Ȯ��

	// ĳ���� ���
	void displayStat();
	void levelUp();

	// ��� / ����ġ / ������ ���� 
	void addGold(int amount);
	void addExp(int amount);
	void removeGold(int amount);

	// �κ��丮 ����
	void equipWeapon(WeaponItem* weapon);
	void equipArmor(ArmorItem* armor);
	void useItem(int itemIndex); // ������ ���
	void addItem(Item* item);
	void removeItem(int index);
	void showInventory() const; // �κ��丮 ���

	// ��ų ��� Ƚ��
	void initializeSkillUsages();
	void restoreSkillUsage(const std::string& skillName, int amount);
	int getRemainingSkillUsage(const std::string& skillName) const;
	std::string getSkillName(const std::string& skillName) const; // ��ų Ÿ��-> �̸� ��ȯ

	bool getIsAimed() const { return isAimed; } // ���� ���� ��ȯ;
	void setIsAimed(bool aimed) { isAimed = aimed; } // ���� ���� ����
	void setWraithArrowDamage(int val) { wraithArrowDamage = val; }
	int getWraithArrowDamage() const { return wraithArrowDamage; }

	void setIsHiding(bool val) { isHiding = val; }
	bool getIsHiding() const { return isHiding; } // ���� ���� ����

	void setHasSurvivedThisTurn(bool val) { hasSurvivedThisTurn = val; }
	bool getHasSurvivedThisTurn() const { return hasSurvivedThisTurn; }
	void setIsShielded(bool val) { isShielded = val; }
	bool getIsShielded() const { return isShielded; }
	void setHasIndomitableWill(bool val) { hasIndomitableWill = val; }
	bool getHasIndomitableWill() const { return hasIndomitableWill; }


	// ���� �Լ�
	int getLevel() const { return level; }
	int getMaxHealth() const { return maxHealth; }
	int getExp() const { return exp; }
	int getGold() const { return gold; }
	int getHitChance() const { return hitChance; }
	int getCriticalChance() const { return criticalChance; }

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