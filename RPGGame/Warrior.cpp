#include "Warrior.h"
#include "IClass.h"
#include "Character.h"
#include "Utils.h"
#include "Monster.h"

#include <iostream>

namespace {
	void performWarrior1(Character& self, Monster& target); // ����
	void performWarrior2(Character& self, Monster& target); // ����
	void performWarrior3(Character& self, Monster& target); // ��Ÿ
	void performWarrior4(Character& self, Monster& target); // ��Ƽ��
}

Warrior::Warrior()
	: isShielded(false), hasSurvivedThisTurn(false), hasIndomitableWill(false) // �ʱ�ȭ
{
}

std::vector<SkillType> Warrior::getActiveSkills() const {
	return { SkillType::WARRIOR1, SkillType::WARRIOR2, SkillType::WARRIOR3, SkillType::WARRIOR4 };
}

void Warrior::applyPassiveSkill(Character& self) {
	self.setHasIndomitableWill(true);
	std::cout << "�нú� �ߵ�! " << self.getName() << "��(��) ������ ��������� ������ ���߳´�! " << std::endl;
}

void Warrior::useSkill(SkillType skillType, Character& self, Monster& target) {
	switch (skillType) {
	case SkillType::WARRIOR1:performWarrior1(self, target); break; // ����
	case SkillType::WARRIOR2:performWarrior2(self, target); break; // ����
	case SkillType::WARRIOR3:performWarrior3(self, target); break; // ��Ÿ
	case SkillType::WARRIOR4:performWarrior4(self, target); break; // ��Ƽ��
	default:
		std::cout << "�������� ���� ��ų�Դϴ�." << std::endl;
		break;
	}
}

namespace {
	void performWarrior1(Character& self, Monster& target) {
		std::cout << self.getName() << "�� ����!" << std::endl;
		int baseSkillDamage = 10 + (self.getLevel() * 2);
		int finalDamage = self.getAttack() + baseSkillDamage;
		std::cout << target.getName() << "���� " << finalDamage << "�� ���ظ� �������ϴ�." << std::endl;
		target.takeDamage(finalDamage);
	}

	void performWarrior2(Character& self, Monster& target) {
		std::cout << self.getName() << "�� ����!" << std::endl;
		self.setIsShielded(true);
		std::cout << "���� ������ �޴� ���ذ� 50% �����մϴ�." << std::endl;
	}

	void performWarrior3(Character& self, Monster& target) {
		std::cout << self.getName() << "�� ��Ÿ!" << std::endl;
		int damage = static_cast<int>(self.getAttack() * 1.5);
		std::cout << target.getName() << "���� " << damage << "�� ���ظ� �������ϴ�." << std::endl;
		target.takeDamage(damage);
	}
	void performWarrior4(Character& self, Monster& target) {
		std::cout << self.getName() << "�� ��Ƽ��!" << std::endl;
		// �� �Ͽ� ġ������ ���ظ� �޾Ƶ� �� �� ���� (takeDamage �Լ����� Ȯ�� �ʿ�)
		self.setHasSurvivedThisTurn(true);
		std::cout << "�̹� �Ͽ� � ������ �޾Ƶ� �������� �ʽ��ϴ�." << std::endl;
	}
}