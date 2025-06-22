#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Character;
class Monster;

enum class SkillType {
	BASIC_ATTACK,

// 1�� - �Ϲݰ���
//���� ��ų
ROGUE1, //����
ROGUE2, //������ ��
ROGUE3, //�޽�
ROGUE4, //����


//�ü� ��ų
ARCHER1, //ȭ�� ����
ARCHER2, //����
ARCHER3, //��ǳ ȭ��
ARCHER4, //���� ȭ��

// �˻� ��ų
WARRIOR1, //����
WARRIOR2, //����
WARRIOR3, //��Ÿ
WARRIOR4, //��Ƽ��

};
// ĳ������ ������ ���� �������̽� 
class IClass {

public:
	
	// ���� �� ���� ��ų ��� ��ȯ �Լ�
	virtual std::vector<SkillType> getActiveSkills() const = 0;
	virtual void useSkill(SkillType skillType, Character& self, Monster& target) = 0;

	// �нú� ��ų �Լ�
	virtual void applyPassiveSkill(Character& self) = 0;
	
	// ���� �̸� ��ȯ
	virtual std::string getClassName() const = 0;
	
	virtual ~IClass() = default;
};

class Warrior : public IClass {
public:
	std::string getClassName() const override { return "������"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target);
	void applyPassiveSkill(Character& self) override;	
};

class Archer : public IClass {
public:
	std::string getClassName() const override { return "�ü�"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};

class Rogue : public IClass {
public:
	std::string getClassName() const override { return "����"; }
	std::vector<SkillType> getActiveSkills() const override;
	void useSkill(SkillType skillType, Character& self, Monster& target) override;
	void applyPassiveSkill(Character& self) override;
};