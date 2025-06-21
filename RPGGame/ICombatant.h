#pragma once

#include <string>

// ���� �� ĳ���Ͱ� ��ӹ޴� �������̽� 
class ICombatant {
public:
	virtual void takeDamage(int damage) = 0; // �޴� ����
	virtual int getAttack() const = 0; // ���ݷ� ��ȯ
	virtual int getHealth() const = 0; // ü�� ��ȯ
	virtual std::string getName() const = 0; // �̸� ��ȯ
	virtual bool isAlive() const = 0; // ��Ҵ��� �׾����� Ȯ��
	virtual int getDefense() const = 0; // ���� ��ȯ
	virtual int getDodgeChance() const = 0; // ȸ����
	virtual ~ICombatant() = default; // ���� �Ҹ���
};