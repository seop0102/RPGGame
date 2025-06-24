#include "Rogue.h"
#include "IClass.h"
#include "Character.h"
#include "Monster.h"
#include "Utils.h"
#include <iostream>

// Rogue �����ڿ��� ��ų ��� �ʱ�ȭ
Rogue::Rogue() {
        activeSkills.push_back("�⺻ ����");
        activeSkills.push_back("����");
        activeSkills.push_back("������ ��");
        activeSkills.push_back("�޽�");
        activeSkills.push_back("����");
}

namespace {
        // ���� ���� �Լ��鵵 SkillType ��� std::string ����ϵ��� ����
        void performRogue1(Character& self, Monster& target); // ����
        void performRogue2(Character& self, Monster& target); // ������ ��
        void performRogue3(Character& self, Monster& target); // �޽�
        void performRogue4(Character& self, Monster& target); // ����
}

// std::vector<SkillType> ��� std::vector<std::string> ��ȯ
std::vector<std::string> Rogue::getActiveSkills() const {
        return activeSkills; // �����ڿ��� �ʱ�ȭ�� ��ų ��� ��ȯ
}

void Rogue::applyPassiveSkill(Character& self) {
        // ���� ���� �� ȸ���� ���ʽ��� ��� �нú�
        self.setDodgeChance(self.getDodgeChance() + 20);
        std::cout << "[�нú� �ߵ�] " << self.getName() << "��(��) ������ ������� ȸ������ 20% �����߽��ϴ�! ���� ȸ����: " << self.getDodgeChance() << "%" << std::endl;
}

// SkillType ��� const std::string&�� �Ű������� �޵��� ����
void Rogue::useSkill(const std::string& skillName, Character& self, Monster& target) {
        // switch �� ��� if-else if ������ ���ڿ� ��
        if (skillName == "����") {
                performRogue1(self, target);
        }
        else if (skillName == "������ ��") {
                performRogue2(self, target);
        }
        else if (skillName == "�޽�") {
                performRogue3(self, target);
        }
        else if (skillName == "����") {
                performRogue4(self, target);
        }
        else if (skillName == "�⺻ ����") { // �⺻ ���ݵ� ���⼭ ó��
                std::cout << self.getName() << "��(��) " << target.getName() << "���� �⺻ ������ �����մϴ�!" << std::endl;
                int damage = self.getAttack();
                target.takeDamage(damage);
        }
        else {
                std::cout << "������ ����� �� ���� ��ų�Դϴ�: " << skillName << std::endl;
        }
}

namespace {
        void performRogue1(Character& self, Monster& target) {
                std::cout << self.getName() << "�� ����!" << std::endl;
                int damage = self.getAttack() + 15;
                std::cout << "��ī�ο� �ܰ��� " << target.getName() << "���� ��ó�� ���� " << damage << "�� ����!" << std::endl;
                target.takeDamage(damage);
        }

        void performRogue2(Character& self, Monster& target) {
                std::cout << self.getName() << "�� ������ ��!" << std::endl;
                int stolenGold = Utils::getRandomInt(10, 30) * self.getLevel();
                self.addGold(stolenGold); // Character�� ��� ȹ�� �Լ� ȣ��
                std::cout << target.getName() << "���Լ� " << stolenGold << " G�� ���ƽ��ϴ�!" << std::endl;

                int damage = static_cast<int>(self.getAttack() * 0.5); // ��ġ�� ���� �ణ�� ����
                target.takeDamage(damage);
        }

        void performRogue3(Character& self, Monster& target) {
                std::cout << self.getName() << "�� �޽�!" << std::endl;
                // ġ��Ÿ Ȯ���� ���� ����
                int dice = Utils::rollDice();
                int damage = 0;
                if (Utils::checkChance(self.getCriticalChance())) { // Character::getCriticalChance()�� ���
                        damage = static_cast<int>(self.getAttack() * 2.0); // 200% ����
                        std::cout << "ġ��Ÿ! " << target.getName() << "�� ������ ��Ȯ�� ��Ƚ��ϴ�! " << damage << "�� ����!" << std::endl;
                }
                else {
                        damage = self.getAttack();
                        std::cout << "������ ������ ���� ���ظ� �������ϴ�. " << damage << "�� ����." << std::endl;
                }
                target.takeDamage(damage);
        }

        void performRogue4(Character& self, Monster& target) {
                std::cout << self.getName() << "�� ����!" << std::endl;
                self.setIsHiding(true); // isHiding �÷��� Ȱ��ȭ
                std::cout << "�׸��� ������ ������ϴ�. ���� �� ������ �ݵ�� ȸ���մϴ�." << std::endl;
        }
}