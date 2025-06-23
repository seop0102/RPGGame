#pragma once

#include "IClass.h"
#include "Character.h"

class Rogue : public IClass {
public:
	bool isHiding; // ����, ���� (1ȸ��)

	std::string getClassName() const override { return "����"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};