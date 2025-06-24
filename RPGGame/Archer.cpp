#include "Archer.h"
#include "IClass.h"
#include "Character.h"
#include "Utils.h"
#include "Monster.h"



Archer::Archer() {
        activeSkills.push_back("�⺻ ����"); // ��� ������ �⺻ ������ �����ϴ�.
        activeSkills.push_back("ȭ�� ����");
        activeSkills.push_back("����");
        activeSkills.push_back("����");
        activeSkills.push_back("��ǳ ȭ��");
        activeSkills.push_back("���� ȭ��");
}

namespace {
        // ���� ���� �Լ��鵵 SkillType ��� std::string ����ϵ��� ����
        void performArcher1(Character& self, Monster& target); // ȭ�� ����
        void performArcher2(Character& self, Monster& target); // ����
        void performArcher3(Character& self, Monster& target); // ��ǳ ȭ��
        void performArcher4(Character& self, Monster& target); // ���� ȭ��
}

// std::vector<SkillType> ��� std::vector<std::string> ��ȯ
std::vector<std::string> Archer::getActiveSkills() const {
        return activeSkills; // �����ڿ��� �ʱ�ȭ�� ��ų ��� ��ȯ
}

void Archer::applyPassiveSkill(Character& self) {
        self.setHitChance(self.getHitChance() + 15);
        std::cout << "[�нú� �ߵ�] " << self.getName() << "��(��) ���� ������ ���߷��� 15% �����߽��ϴ�! ���� ���߷�: " << self.getHitChance() << "%" << std::endl;
}

// SkillType ��� const std::string&�� �Ű������� �޵��� ����
void Archer::useSkill(const std::string& skillName, Character& self, Monster& target) {
        // switch �� ��� if-else if ������ ���ڿ� ��
        if (skillName == "ȭ�� ����") {
                performArcher1(self, target);
        }
        else if (skillName == "����") {
                performArcher2(self, target);
        }
        else if (skillName == "��ǳ ȭ��") {
                performArcher3(self, target);
        }
        else if (skillName == "���� ȭ��") {
                performArcher4(self, target);
        }
        else if (skillName == "�⺻ ����") { // �⺻ ���ݵ� ���⼭ ó���� �� �ֽ��ϴ�.
                std::cout << self.getName() << "��(��) " << target.getName() << "���� �⺻ ������ �����մϴ�!" << std::endl;
                int damage = self.getAttack();
                target.takeDamage(damage);
        }
        else {
                std::cout << "�������� ���� ��ų�Դϴ�: " << skillName << std::endl;
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

        void performArcher2(Character& self, Monster& target) {
                std::cout << self.getName() << "�� ����!" << std::endl;
                self.setIsAimed(true); // isAimed �÷��� Ȱ��ȭ
                std::cout << "���� ������ ���߷��� ���ط��� �����մϴ�." << std::endl;
        }

        void performArcher3(Character& self, Monster& target) {
                std::cout << self.getName() << "�� ��ǳ ȭ��!" << std::endl;
                int hitCount = Utils::getRandomInt(2, 4); // 2~4�� ���� �߻�
                int damagePerHit = static_cast<int>(self.getAttack() * 0.6); // �� �ߴ� ���ط��� 60%
                std::cout << "������ ȭ���� " << target.getName() << "��(��) " << hitCount << "�� �����մϴ�!" << std::endl;
                for (int i = 0; i < hitCount; ++i) {
                        target.takeDamage(damagePerHit);
                }
        }

        void performArcher4(Character& self, Monster& target) {
                std::cout << self.getName() << "�� ���� ȭ��!" << std::endl;
                int delayedDamage = self.getAttack() * 2; // ���ݷ��� 200%�� �ش��ϴ� ���� ����
                // Character.h�� ����� wraithArrowDamage ������ ���ط� ����
                self.setWraithArrowDamage(delayedDamage);
                std::cout << "������ ����� ��� ȭ���� " << target.getName() << "���� �������ϴ�. ���� �Ͽ� �����մϴ�!" << std::endl;
        }
}