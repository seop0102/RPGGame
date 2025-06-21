#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Character;
class Monster;

enum class SkillType {
	BASIC_ATTACK,

// 1번 - 일반공격
//도적 스킬
ROGUE1, //찢기
ROGUE2, //날렵한 손
ROGUE3, //급습
ROGUE4, //숨기


//궁수 스킬
ARCHER1, //화살 명중
ARCHER2, //조준
ARCHER3, //폭풍 화살
ARCHER4, //망령 화살

// 검사 스킬
WARRIOR1, //베기
WARRIOR2, //방패
WARRIOR3, //강타
WARRIOR4, //버티기

};
// 캐릭터의 직업을 위한 인터페이스 
class IClass {

public:
	
	// 직업 별 고유 스킬 목록 반환 함수
	virtual std::vector<SkillType> getActiveSkills() const = 0;
	virtual void useSkill(SkillType skillType, Character& self, Monster& target) = 0;

	// 패시브 스킬 함수
	virtual void applyPassiveSkill(Character& self) = 0;
	
	// 직업 이름 반환
	virtual std::string getClassName() const = 0;
	
	virtual ~IClass() = default;
};

class Warrior : public IClass {
public:
	std::string getClassName() const override { return "워리어"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target);
	void applyPassiveSkill(Character& self) override;	
};

class Archer : public IClass {
public:
	std::string getClassName() const override { return "궁수"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};

class Rogue : public IClass {
public:
	std::string getClassName() const override { return "도적"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};