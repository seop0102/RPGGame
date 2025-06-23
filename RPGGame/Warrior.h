#pragma once

#include "IClass.h"
#include "Character.h"

class Warrior : public IClass {
public:
	bool isShielded; // ������, ���� (�ϴ� 1ȸ)
	bool hasSurvivedThisTurn; // ������, ��Ƽ�� (�ϴ� 1ȸ)
	bool hasIndomitableWill; // ������ �нú� 

	std::string getClassName() const override { return "������"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target);
	void applyPassiveSkill(Character& self) override;
};