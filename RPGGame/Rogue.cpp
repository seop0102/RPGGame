#include "Rogue.h"
#include "IClass.h"
#include "Character.h"
#include "Monster.h"
#include "Utils.h"
#include <iostream>

namespace {
    void performRogue1(Character& self, Monster& target); // 찢기
    void performRogue2(Character& self, Monster& target); // 날렵한 손
    void performRogue3(Character& self, Monster& target); // 급습
    void performRogue4(Character& self, Monster& target); // 숨기
}

Rogue::Rogue()
	: isHiding(false) // 초기화
{
}

std::vector<SkillType> Rogue::getActiveSkills() const {
    return { SkillType::ROGUE1, SkillType::ROGUE2, SkillType::ROGUE3, SkillType::ROGUE4 };
}

void Rogue::applyPassiveSkill(Character& self) {
    // 전투 시작 시 회피율 보너스를 얻는 패시브
    self.setDodgeChance(self.getDodgeChance() + 20);
    std::cout << "[패시브 발동] " << self.getName() << "은(는) 날렵한 몸놀림으로 회피율이 20% 증가했습니다!" << std::endl;
}

void Rogue::useSkill(SkillType skillType, Character& self, Monster& target) {
    switch (skillType) {
    case SkillType::ROGUE1: performRogue1(self, target); break;
    case SkillType::ROGUE2: performRogue2(self, target); break;
    case SkillType::ROGUE3: performRogue3(self, target); break;
    case SkillType::ROGUE4: performRogue4(self, target); break;
    default:
        std::cout << "도적은 사용할 수 없는 스킬입니다." << std::endl;
        break;
    }
}

namespace {
    // ROGUE1: 찢기
    void performRogue1(Character& self, Monster& target) {
        std::cout << self.getName() << "의 찢기!" << std::endl;
        int damage = self.getAttack() + 15;
        std::cout << "날카로운 단검이 " << target.getName() << "에게 상처를 입혀 " << damage << "의 피해!" << std::endl;
        target.takeDamage(damage);
    }

    // ROGUE2: 날렵한 손
    void performRogue2(Character& self, Monster& target) {
        std::cout << self.getName() << "의 날렵한 손!" << std::endl;
        int stolenGold = Utils::getRandomInt(10, 30) * self.getLevel();
        self.addGold(stolenGold); // Character의 골드 획득 함수 호출
        std::cout << target.getName() << "에게서 " << stolenGold << " G를 훔쳤습니다!" << std::endl;

        int damage = static_cast<int>(self.getAttack() * 0.5); // 훔치는 동안 약간의 피해
        target.takeDamage(damage);
    }

    // ROGUE3: 급습
    void performRogue3(Character& self, Monster& target) {
        std::cout << self.getName() << "의 급습!" << std::endl;
        // 치명타 확률이 높은 공격
        int dice = Utils::rollDice();
        int damage = 0;
        if (dice >= 4) { // 주사위 4 이상일 때 치명타 (50% 확률)
            damage = static_cast<int>(self.getAttack() * 2.0); // 200% 피해
            std::cout << "치명타! " << target.getName() << "의 약점을 정확히 노렸습니다! " << damage << "의 피해!" << std::endl;
        }
        else {
            damage = self.getAttack();
            std::cout << "공격이 빗나가 약한 피해를 입혔습니다. " << damage << "의 피해." << std::endl;
        }
        target.takeDamage(damage);
    }

    // ROGUE4: 숨기
    void performRogue4(Character& self, Monster& target) {
        std::cout << self.getName() << "의 숨기!" << std::endl;
        self.setIsHiding(true); // isHiding 플래그 활성화
        std::cout << "그림자 속으로 사라집니다. 다음 턴 공격을 반드시 회피합니다." << std::endl;
    }
}