#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<map> // ���� �����̳� Key, Value 
#include<memory> // unique_ptr 

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
	std::unique_ptr<IClass> characterClass;

	// ��ų ��� Ƚ��
	std::map<std::string, int> skillUsages;

public:
	Character(std::string name, std::unique_ptr<IClass> selectedClass);

	unique_ptr<IClass> getcharacterClass() const { return characterClass.get(); } // ���� ��ü ��ȯ

// ICombatant �������̽�
	void takeDamage(int damage) override;
	int getAttack() const override { return attack; }
	int getHealth() const override { return health; }
	string getName() const override { return name; }
	int getDefense() const { return defense; } // ���� ��ȯ
	int getDodgeChance() const { return dodgeChance; } // ȸ���� ��ȯ

	vector<SkillType> getActiveSkills();
	
	void useSkill(SkillType skillType, Character& self, Monster& target);

	void applyPassiveSkill(Character& self);

	string getClassName();

	bool isAlive() const { return health > 0;} // ��Ҵ��� �׾����� Ȯ��

	// ĳ���� ���
	void displayStat();
	void levelUp();
	void useItem(int itemIndex);

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
	void restoreSkillUsage(SkillType skillType, int amount);
	int getRemainingSkillUsage(SkillType skillType) const;
	std::string getSkillName(SkillType skillType) const; // ��ų Ÿ��-> �̸� ��ȯ
		 
	// ���� �Լ�
	int getLevel() const { return level; }
	int getMaxHealth() const { return maxHealth; }
	int getExp() const { return exp; }
	int getGold() const { return gold; }
	int getHitChance() const { return hitChance; }
	
	//
	// ��ų ȿ�� ����/����
	/*void setHasSurvivedThisTurn(bool val) { hasSurvivedThisTurn = val; }
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
	bool getHasIndomitableWill() const { return hasIndomitableWill; }*/

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