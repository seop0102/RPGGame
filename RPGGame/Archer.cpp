#include "Archer.h"
#include "IClass.h"
#include "Character.h"
#include "Utils.h"
#include "Monster.h"

#include <iostream>

namespace {
	void performArcher1(Character& self, Monster& target); // ȭ�� ����
	void performArcher2(Character& self, Monster& target); // ����
	void performArcher3(Character& self, Monster& target); // ��ǳ ȭ��
	void performArcher4(Character& self, Monster& target); // ���� ȭ��
}

std::vector<SkillType> Archer::getActiveSkills() const {
	return { SkillType::ARCHER1, SkillType::ARCHER2, SkillType::ARCHER3, SkillType::ARCHER4 };
}

void Archer::applyPassiveSkill(Character& self) {
	self.setHitChance(self.getHitChance() + 15);
	std::cout << "�нú� �ߵ�! " << self.getName() << "��(��) ���� ������ ���߷��� 15% �����߽��ϴ�! " << std::endl;
}

void Archer::useSkill(SkillType skillType, Character& self, Monster& target) {
	switch (skillType) {
	case SkillType::ARCHER1:performArcher1(self, target); break; 
	case SkillType::ARCHER2:performArcher2(self, target); break; 
	case SkillType::ARCHER3:performArcher3(self, target); break; 
	case SkillType::ARCHER4:performArcher4(self, target); break; 
	default:
		std::cout << "�������� ���� ��ų�Դϴ�." << std::endl;
		break;
	}
}

namespace {
    void performArcher1(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ȭ�� ����!" << std::endl;
        int damage = self.getAttack();

        // '����' ���¶�� �߰� ���� �� ���� ȿ��
        if (self.getIsAimed()) {
            std::cout << "���� ȿ���� ȭ���� �ݵ�� �����ϸ� �߰� ���ظ� �����ϴ�!" << std::endl;
            damage = static_cast<int>(damage * 1.3); // ������ 30% ����
            self.setIsAimed(false); // ���� ȿ�� ��� �� �ʱ�ȭ
        }

        std::cout << target.getName() << "���� " << damage << "�� ���ظ� �������ϴ�." << std::endl;
        target.takeDamage(damage);
    }

    // ARCHER2: ����
    void performArcher2(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ����!" << std::endl;
        self.setIsAimed(true); // isAimed �÷��� Ȱ��ȭ
        std::cout << "���� ������ ���߷��� ���ط��� �����մϴ�." << std::endl;
    }

    // ARCHER3: ��ǳ ȭ��
    void performArcher3(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ��ǳ ȭ��!" << std::endl;
        int hitCount = Utils::getRandomInt(2, 4); // 2~4�� ���� �߻�
        int damagePerHit = static_cast<int>(self.getAttack() * 0.6); // �� �ߴ� ���ط��� 60%
        std::cout << "������ ȭ���� " << target.getName() << "��(��) " << hitCount << "�� �����մϴ�!" << std::endl;
        for (int i = 0; i < hitCount; ++i) {
            target.takeDamage(damagePerHit);
        }
    }

    // ARCHER4: ���� ȭ��
    void performArcher4(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ���� ȭ��!" << std::endl;
        int delayedDamage = self.getAttack() * 2; // ���ݷ��� 200%�� �ش��ϴ� ���� ����
        // Character.h�� ����� wraithArrowDamage ������ ���ط� ����
        self.setWraithArrowDamage(delayedDamage);
        std::cout << "������ ����� ��� ȭ���� " << target.getName() << "���� �������ϴ�. ���� �Ͽ� �����մϴ�!" << std::endl;
	}
}