#pragma once

#include "IClass.h"
#include "Character.h"

class Archer : public IClass {
public:

	Archer(); // 생성자 초기화

	bool isAimed; // 궁수, 조준 (다음 공격 명중률 증가)
	int wraithArrowDamage; // 궁수, 망령 화살 (다음 턴 공격 피해량 증가)

	std::string getClassName() const override { return "궁수"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;

	bool getIsAimed() const { return isAimed; } // 조준 상태 반환;
	void setIsAimed(bool aimed) { isAimed = aimed; } // 조준 상태 설정
};

