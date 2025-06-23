#include "Warrior.h"
#include "IClass.h"
#include "Character.h"
#include "Utils.h"
#include "Monster.h"

#include <iostream>

namespace {
	void performWarrior1(Character& self, Monster& target); // 베기
	void performWarrior2(Character& self, Monster& target); // 방패
	void performWarrior3(Character& self, Monster& target); // 강타
	void performWarrior4(Character& self, Monster& target); // 버티기
}

Warrior::Warrior()
	: isShielded(false), hasSurvivedThisTurn(false), hasIndomitableWill(false) // 초기화
{
}

std::vector<SkillType> Warrior::getActiveSkills() const {
	return { SkillType::WARRIOR1, SkillType::WARRIOR2, SkillType::WARRIOR3, SkillType::WARRIOR4 };
}

void Warrior::applyPassiveSkill(Character& self) {
	self.setHasIndomitableWill(true);
	std::cout << "패시브 발동! " << self.getName() << "은(는) 강인한 생명력으로 공격을 버텨냈다! " << std::endl;
}

void Warrior::useSkill(SkillType skillType, Character& self, Monster& target) {
	switch (skillType) {
	case SkillType::WARRIOR1:performWarrior1(self, target); break; // 베기
	case SkillType::WARRIOR2:performWarrior2(self, target); break; // 방패
	case SkillType::WARRIOR3:performWarrior3(self, target); break; // 강타
	case SkillType::WARRIOR4:performWarrior4(self, target); break; // 버티기
	default:
		std::cout << "지정되지 않은 스킬입니다." << std::endl;
		break;
	}
}

namespace {
	void performWarrior1(Character& self, Monster& target) {
		std::cout << self.getName() << "의 베기!" << std::endl;
		int baseSkillDamage = 10 + (self.getLevel() * 2);
		int finalDamage = self.getAttack() + baseSkillDamage;
		std::cout << target.getName() << "에게 " << finalDamage << "의 피해를 입혔습니다." << std::endl;
		target.takeDamage(finalDamage);
	}

	void performWarrior2(Character& self, Monster& target) {
		std::cout << self.getName() << "의 방패!" << std::endl;
		self.setIsShielded(true);
		std::cout << "다음 공격의 받는 피해가 50% 감소합니다." << std::endl;
	}

	void performWarrior3(Character& self, Monster& target) {
		std::cout << self.getName() << "의 강타!" << std::endl;
		int damage = static_cast<int>(self.getAttack() * 1.5);
		std::cout << target.getName() << "에게 " << damage << "의 피해를 입혔습니다." << std::endl;
		target.takeDamage(damage);
	}
	void performWarrior4(Character& self, Monster& target) {
		std::cout << self.getName() << "의 버티기!" << std::endl;
		// 이 턴에 치명적인 피해를 받아도 한 번 생존 (takeDamage 함수에서 확인 필요)
		self.setHasSurvivedThisTurn(true);
		std::cout << "이번 턴에 어떤 공격을 받아도 쓰러지지 않습니다." << std::endl;
	}
}