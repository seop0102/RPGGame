#pragma once

#include "IClass.h"
#include "Character.h"

class Rogue : public IClass {
public:
	bool isHiding; // 档利, 见扁 (1雀己)

	std::string getClassName() const override { return "档利"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};