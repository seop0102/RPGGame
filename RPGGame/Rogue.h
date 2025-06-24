#pragma once

#include <string> // std::string�� ����ϹǷ� �߰�
#include <vector> // std::vector�� ����ϹǷ� �߰�
#include "IClass.h"
#include "Character.h"

class Rogue : public IClass {
public:
	// isHiding�� Character Ŭ���� ����� �̵������Ƿ� ���⼭ ����.
	// ���� Ŭ���� ��ü�� �ʿ��� ������ ����� �ִٸ� ���⿡ �߰�.

	// ������ �߰�
	Rogue();
	// �Ҹ���
	~Rogue() override = default;

	std::string getClassName() const override { return "����"; }
	// SkillType ��� std::string�� ��ȯ�ϴ� ���ͷ� ����
	std::vector<std::string> getActiveSkills() const override;
	// SkillType ��� const std::string&�� �Ű������� �޵��� ����
	void useSkill(const std::string& skillName, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
	

private:
	// Rogue�� Ȱ�� ��ų �̸��� ������ ����
	std::vector<std::string> activeSkills;
};