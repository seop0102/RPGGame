#pragma once

#include <string>
#include <vector>
#include "IClass.h"
#include "Character.h"


class Warrior : public IClass { // IClass ���
public:
	Warrior();
	~Warrior() override = default;

	std::string getClassName() const override; // SkillType ��� std::string ��ȯ�ϵ��� ����
	std::vector<std::string> getActiveSkills() const override; // SkillType ��� const std::string& �Ű����� �޵��� ����
	void useSkill(const std::string& skillName, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;

private:
	// SkillType ��� std::string�� �����ϵ��� ����
	std::vector<std::string> activeSkills; // ��ų �̸� ��� (std::string)
};