#pragma once

#include "IClass.h"
#include "Character.h"

class Warrior : public IClass {
public:
	bool isShielded; // 워리어, 방패 (턴당 1회)
	bool hasSurvivedThisTurn; // 워리어, 버티기 (턴당 1회)
	bool hasIndomitableWill; // 워리어 패시브 

	std::string getClassName() const override { return "워리어"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target);
	void applyPassiveSkill(Character& self) override;
};