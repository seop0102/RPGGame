#pragma once

#include "IClass.h"
#include "Character.h"

class Archer : public IClass {
public:
	bool isAimed; // �ü�, ���� (���� ���� ���߷� ����)
	int wraithArrowDamage; // �ü�, ���� ȭ�� (���� �� ���� ���ط� ����)

	std::string getClassName() const override { return "�ü�"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};