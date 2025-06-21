#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<map> // 연관 컨테이너 Key, Value 
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
	int dodgeChance; // 회피율

	int exp;
	int gold;

	std::vector<Item> inventory;

	// 직업 객체 
	std::unique_ptr<IClass> characterClass;

	// 스킬 사용 횟수
	std::map<SkillType, int> skillUsages;

	// 스킬 효과
	bool hasSurvivedThisTurn; // 워리어, 버티기 (턴당 1회)
	bool isShielded; // 워리어, 방패 (턴당 1회)
	bool isHiding; // 도적, 숨기 (1회성)
	bool isAimed; // 궁수, 조준 (다음 공격 명중률 증가)
	int wraithArrowDamage; // 궁수, 망령 화살 (다음 턴 공격 피해량 증가)
	bool hasIndomitableWill; // 워리어 패시브 

public:
	Character(std::string name, std::unique_ptr<IClass> selectedClass);

// ICombatant 인터페이스
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
			// 스킬 사용 횟수 체크, 감소
			if (skillUsages.count(skillType) && skillUsages[skillType] > 0) {
				characterClass->useSkill(skillType, self, target); // 스킬 효과 위임
				// 특수 스킬 횟수 차감용
				if (skillType == SkillType::ROGUE4 || skillType == SkillType::WARRIOR4 || skillType == SkillType::ARCHER4) {
					skillUsages[skillType]--;
				}
			}
			else {
				std::cout << "스킬 '" << getSkillName(skillType) << "'의 사용 횟수가 부족합니다." << std::endl;
			}
		}
	}
	void applyPassiveSkill(Character& self)  {
		if (characterClass) characterClass->applyPassiveSkill(self);
	}
	std::string getClassName() const  {
		if (characterClass) return characterClass->getClassName();
		return "알수 없음";
	}

	// 캐릭터 기능
	void displayStat();
	void levelUp();
	void useItem(int itemIndex);

	// 골드 / 경험치 / 아이템 관리 
	void addGold(int amount);
	void addExp(int amount);
	void removeGold(int amount);
	void addItem(const Item& item);
	void removeItem(int index);

	// 스킬 사용 횟수
	void initializeSkillUsages();
	void restoreSkillUsage(SkillType skillType, int amount);
	int getRemainingSkillUsage(SkillType skillType) const;
	std::string getSkillName(SkillType skillType) const; // 스킬 타입-> 이름 변환
		 
	// 게터 함수
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

	// 스킬 효과 게터/세터
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