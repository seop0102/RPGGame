#include "Archer.h"
#include "IClass.h"
#include "Character.h"
#include "Utils.h"
#include "Monster.h"

#include <iostream>

namespace {
	void performArcher1(Character& self, Monster& target); // 화살 명중
	void performArcher2(Character& self, Monster& target); // 조준
	void performArcher3(Character& self, Monster& target); // 폭풍 화살
	void performArcher4(Character& self, Monster& target); // 망령 화살
}

std::vector<SkillType> Archer::getActiveSkills() const {
	return { SkillType::ARCHER1, SkillType::ARCHER2, SkillType::ARCHER3, SkillType::ARCHER4 };
}

void Archer::applyPassiveSkill(Character& self) {
	self.setHitChance(self.getHitChance() + 15);
	std::cout << "패시브 발동! " << self.getName() << "은(는) 매의 눈으로 명중률이 15% 증가했습니다! " << std::endl;
}

void Archer::useSkill(SkillType skillType, Character& self, Monster& target) {
	switch (skillType) {
	case SkillType::ARCHER1:performArcher1(self, target); break; 
	case SkillType::ARCHER2:performArcher2(self, target); break; 
	case SkillType::ARCHER3:performArcher3(self, target); break; 
	case SkillType::ARCHER4:performArcher4(self, target); break; 
	default:
		std::cout << "지정되지 않은 스킬입니다." << std::endl;
		break;
	}
}

namespace {
    void performArcher1(Character& self, Monster& target) {
        std::cout << self.getName() << "의 화살 명중!" << std::endl;
        int damage = self.getAttack();

        // '조준' 상태라면 추가 피해 및 필중 효과
        if (self.getIsAimed()) {
            std::cout << "조준 효과로 화살이 반드시 명중하며 추가 피해를 입힙니다!" << std::endl;
            damage = static_cast<int>(damage * 1.3); // 데미지 30% 증가
            self.setIsAimed(false); // 조준 효과 사용 후 초기화
        }

        std::cout << target.getName() << "에게 " << damage << "의 피해를 입혔습니다." << std::endl;
        target.takeDamage(damage);
    }

    // ARCHER2: 조준
    void performArcher2(Character& self, Monster& target) {
        std::cout << self.getName() << "의 조준!" << std::endl;
        self.setIsAimed(true); // isAimed 플래그 활성화
        std::cout << "다음 공격의 명중률과 피해량이 증가합니다." << std::endl;
    }

    // ARCHER3: 폭풍 화살
    void performArcher3(Character& self, Monster& target) {
        std::cout << self.getName() << "의 폭풍 화살!" << std::endl;
        int hitCount = Utils::getRandomInt(2, 4); // 2~4발 랜덤 발사
        int damagePerHit = static_cast<int>(self.getAttack() * 0.6); // 한 발당 피해량은 60%
        std::cout << "수많은 화살이 " << target.getName() << "을(를) " << hitCount << "번 가격합니다!" << std::endl;
        for (int i = 0; i < hitCount; ++i) {
            target.takeDamage(damagePerHit);
        }
    }

    // ARCHER4: 망령 화살
    void performArcher4(Character& self, Monster& target) {
        std::cout << self.getName() << "의 망령 화살!" << std::endl;
        int delayedDamage = self.getAttack() * 2; // 공격력의 200%에 해당하는 지연 피해
        // Character.h에 선언된 wraithArrowDamage 변수에 피해량 저장
        self.setWraithArrowDamage(delayedDamage);
        std::cout << "망령의 기운이 담긴 화살이 " << target.getName() << "에게 박혔습니다. 다음 턴에 폭발합니다!" << std::endl;
	}
}