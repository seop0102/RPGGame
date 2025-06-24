#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<map> // 연관 컨테이너 Key, Value 
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
	int dodgeChance; // 회피율

	int exp;
	int gold;

	WeaponItem* equippedWeapon; // 장착된 무기
	ArmorItem* equippedArmor; // 장착된 방어구

	std::vector<Item*> inventory;

	// 직업 객체 
	std::unique_ptr<IClass> characterClass;

	// 스킬 사용 횟수
	std::map<std::string, int> skillUsages;

public:
	Character(std::string name, std::unique_ptr<IClass> selectedClass);

	unique_ptr<IClass> getcharacterClass() const { return characterClass.get(); } // 직업 객체 반환

// ICombatant 인터페이스
	void takeDamage(int damage) override;
	int getAttack() const override { return attack; }
	int getHealth() const override { return health; }
	string getName() const override { return name; }
	int getDefense() const { return defense; } // 방어력 반환
	int getDodgeChance() const { return dodgeChance; } // 회피율 반환

	vector<SkillType> getActiveSkills();
	
	void useSkill(SkillType skillType, Character& self, Monster& target);

	void applyPassiveSkill(Character& self);

	string getClassName();

	bool isAlive() const { return health > 0;} // 살았는지 죽었는지 확인

	// 캐릭터 기능
	void displayStat();
	void levelUp();
	void useItem(int itemIndex);

	// 골드 / 경험치 / 아이템 관리 
	void addGold(int amount);
	void addExp(int amount);
	void removeGold(int amount);

	// 인벤토리 관련
	void equipWeapon(WeaponItem* weapon);
	void equipArmor(ArmorItem* armor);
	void useItem(int itemIndex); // 아이템 사용
	void addItem(Item* item);
	void removeItem(int index);
	void showInventory() const; // 인벤토리 출력

	// 스킬 사용 횟수
	void initializeSkillUsages();
	void restoreSkillUsage(SkillType skillType, int amount);
	int getRemainingSkillUsage(SkillType skillType) const;
	std::string getSkillName(SkillType skillType) const; // 스킬 타입-> 이름 변환
		 
	// 게터 함수
	int getLevel() const { return level; }
	int getMaxHealth() const { return maxHealth; }
	int getExp() const { return exp; }
	int getGold() const { return gold; }
	int getHitChance() const { return hitChance; }
	
	//
	// 스킬 효과 게터/세터
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

	// 세터 함수
	void setHealth(int newHealth) { health = newHealth; }
	void setMaxHealth(int newMaxHealth) { maxHealth = newMaxHealth; }
	void setAttack(int newAttack) { attack = newAttack; }
	void setDefense(int newDefense) { defense = newDefense; }
	void setCriticalChance(int chance) { criticalChance = chance; }
	void setHitChance(int chance) { hitChance = chance; }
	void setDodgeChance(int chance) { dodgeChance = chance; }
	void setGold(int newGold) { gold = newGold; } // 도적 스킬 등에서 필요

};