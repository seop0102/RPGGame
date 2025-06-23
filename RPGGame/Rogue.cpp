#include "Rogue.h"
#include "IClass.h"
#include "Character.h"
#include "Monster.h"
#include "Utils.h"
#include <iostream>

namespace {
    void performRogue1(Character& self, Monster& target); // ����
    void performRogue2(Character& self, Monster& target); // ������ ��
    void performRogue3(Character& self, Monster& target); // �޽�
    void performRogue4(Character& self, Monster& target); // ����
}

Rogue::Rogue()
	: isHiding(false) // �ʱ�ȭ
{
}

std::vector<SkillType> Rogue::getActiveSkills() const {
    return { SkillType::ROGUE1, SkillType::ROGUE2, SkillType::ROGUE3, SkillType::ROGUE4 };
}

void Rogue::applyPassiveSkill(Character& self) {
    // ���� ���� �� ȸ���� ���ʽ��� ��� �нú�
    self.setDodgeChance(self.getDodgeChance() + 20);
    std::cout << "[�нú� �ߵ�] " << self.getName() << "��(��) ������ ������� ȸ������ 20% �����߽��ϴ�!" << std::endl;
}

void Rogue::useSkill(SkillType skillType, Character& self, Monster& target) {
    switch (skillType) {
    case SkillType::ROGUE1: performRogue1(self, target); break;
    case SkillType::ROGUE2: performRogue2(self, target); break;
    case SkillType::ROGUE3: performRogue3(self, target); break;
    case SkillType::ROGUE4: performRogue4(self, target); break;
    default:
        std::cout << "������ ����� �� ���� ��ų�Դϴ�." << std::endl;
        break;
    }
}

namespace {
    // ROGUE1: ����
    void performRogue1(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ����!" << std::endl;
        int damage = self.getAttack() + 15;
        std::cout << "��ī�ο� �ܰ��� " << target.getName() << "���� ��ó�� ���� " << damage << "�� ����!" << std::endl;
        target.takeDamage(damage);
    }

    // ROGUE2: ������ ��
    void performRogue2(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ������ ��!" << std::endl;
        int stolenGold = Utils::getRandomInt(10, 30) * self.getLevel();
        self.addGold(stolenGold); // Character�� ��� ȹ�� �Լ� ȣ��
        std::cout << target.getName() << "���Լ� " << stolenGold << " G�� ���ƽ��ϴ�!" << std::endl;

        int damage = static_cast<int>(self.getAttack() * 0.5); // ��ġ�� ���� �ణ�� ����
        target.takeDamage(damage);
    }

    // ROGUE3: �޽�
    void performRogue3(Character& self, Monster& target) {
        std::cout << self.getName() << "�� �޽�!" << std::endl;
        // ġ��Ÿ Ȯ���� ���� ����
        int dice = Utils::rollDice();
        int damage = 0;
        if (dice >= 4) { // �ֻ��� 4 �̻��� �� ġ��Ÿ (50% Ȯ��)
            damage = static_cast<int>(self.getAttack() * 2.0); // 200% ����
            std::cout << "ġ��Ÿ! " << target.getName() << "�� ������ ��Ȯ�� ��Ƚ��ϴ�! " << damage << "�� ����!" << std::endl;
        }
        else {
            damage = self.getAttack();
            std::cout << "������ ������ ���� ���ظ� �������ϴ�. " << damage << "�� ����." << std::endl;
        }
        target.takeDamage(damage);
    }

    // ROGUE4: ����
    void performRogue4(Character& self, Monster& target) {
        std::cout << self.getName() << "�� ����!" << std::endl;
        self.setIsHiding(true); // isHiding �÷��� Ȱ��ȭ
        std::cout << "�׸��� ������ ������ϴ�. ���� �� ������ �ݵ�� ȸ���մϴ�." << std::endl;
    }
}