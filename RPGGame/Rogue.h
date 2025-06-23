#pragma once

#include "IClass.h"
#include "Character.h"

class Rogue : public IClass {
public:
	bool isHiding; // 도적, 숨기 (1회성)

	std::string getClassName() const override { return "도적"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;

	void setIsHiding(bool hiding) { isHiding = hiding; } // 숨기 상태 설정
};