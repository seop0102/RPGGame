#include "Warrior.h"
#include "IClass.h"
#include "Character.h"
#include "Utils.h"
#include "Monster.h"

#include <iostream>

Warrior::Warrior() {
        // activeSkills ���Ϳ� ���� ��ų �̸��� ���ڿ��� �߰�
        activeSkills.push_back("�⺻ ����");
        activeSkills.push_back("����");
        activeSkills.push_back("����");
        activeSkills.push_back("��Ÿ");
        activeSkills.push_back("��Ƽ��");
}

std::string Warrior::getClassName() const {
        return "����";
}

// std::vector<std::string>�� ��ȯ�ϵ��� ����
std::vector<std::string> Warrior::getActiveSkills() const {
        return activeSkills;
}

// �Ű������� const std::string&���� �����ϰ� ���� ������ ���ڿ� �񱳷� ����
void Warrior::useSkill(const std::string& skillName, Character& self, Monster& target) {
        if (skillName == "�⺻ ����") {
                std::cout << self.getName() << "��(��) " << target.getName() << "���� �⺻ ������ �����մϴ�!" << std::endl;
                int damage = self.getAttack();
                target.takeDamage(damage);
        }
        else if (skillName == "����") {
                std::cout << self.getName() << "��(��) " << target.getName() << "���� ���⸦ �����մϴ�!" << std::endl;
                int damage = self.getAttack() * 1.2; // ���÷� ���ݷ��� 120%
                target.takeDamage(damage);
        }
        else if (skillName == "����") {
                std::cout << self.getName() << "��(��) ���и� ��� ��� �¼��� ���մϴ�!" << std::endl;
                self.setIsShielded(true); // Character Ŭ������ isShielded ���� �߰� �� ���� �ʿ�
                self.setDefense(self.getDefense() + 10); // �ӽ÷� ���� ���� ����
        }
        else if (skillName == "��Ÿ") {
                std::cout << self.getName() << "��(��) " << target.getName() << "���� ��Ÿ�� �����մϴ�!" << std::endl;
                int damage = self.getAttack() * 1.5; // ���� ����
                if (Utils::checkChance(self.getCriticalChance())) { // Utils::checkChance�� ���� �Լ�
                        damage *= 2; // ġ��Ÿ
                        std::cout << "ġ��Ÿ �ߵ�!" << std::endl;
                }
                target.takeDamage(damage);
        }
        else if (skillName == "��Ƽ��") {
                // Character.cpp�� useSkill���� Ƚ�� ������ �̹� ó����
                std::cout << self.getName() << "��(��) �γ������� ��Ƽ�⸦ ����մϴ�! ���� �Ͽ� ���� �ʽ��ϴ�." << std::endl;
                self.setHasIndomitableWill(true); // Character�� hasIndomitableWill ���� �߰� �� ���� �ʿ�
        }
        else {
                std::cout << "�� �� ���� ���� ��ų�Դϴ�: " << skillName << std::endl;
        }
}

void Warrior::applyPassiveSkill(Character& self) {
        std::cout << "������ �нú� ��ų '������'�� ����˴ϴ�. �ִ� ü�� +50." << std::endl;
        self.setMaxHealth(self.getMaxHealth() + 50);
        self.setHealth(self.getMaxHealth()); // ü�µ� �ִ�ġ�� ȸ��
}