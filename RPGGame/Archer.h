#pragma once

#include "IClass.h"
#include "Character.h"

class Archer : public IClass {
public:
	bool isAimed; // 궁수, 조준 (다음 공격 명중률 증가)
	int wraithArrowDamage; // 궁수, 망령 화살 (다음 턴 공격 피해량 증가)

	std::string getClassName() const override { return "궁수"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};