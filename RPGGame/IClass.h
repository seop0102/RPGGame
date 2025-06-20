#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Character;
class Monster;

enum class SkillType {
	BASIC_ATTACK,

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
	virtual std::vector<SkillType> getActiveSkills() const = 0;
	virtual void useSkill(SkillType skillType, Character& self, Monster& target) = 0;
	virtual std::string getClassName() const = 0;
	virtual ~IClass() = default;
};

class warrior : public IClass {
public:
	
	
};