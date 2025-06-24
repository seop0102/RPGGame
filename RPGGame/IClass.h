#pragma once

#include <string>
#include <iostream>
#include <vector>

class Character;
class Monster;

class IClass {
public:
	virtual ~IClass() = default; // ���� �Ҹ���

	virtual std::string getClassName() const = 0;
	// SkillType ��� std::string ����ϵ��� ����
	virtual std::vector<std::string> getActiveSkills() const = 0;
	// SkillType ��� const std::string& ����ϵ��� ����
	virtual void useSkill(const std::string& skillName, Character& self, Monster& target) = 0;
	virtual void applyPassiveSkill(Character& self) = 0;
};