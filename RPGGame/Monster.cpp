#include "Monster.h"
#include <iostream>
#include <cstdlib>

// �޴� ������
// 30%Ȯ���� ������ ��� �߰� �ؾ� ��
// ���Ͱ� �������� ��� ��� ��� ĳ���� ���� �߰� �ؾ� ��
void Monster::takeDamage(int damage) {
    health -= damage;
    std::cout << name << "��(��) " << damage << "�� �������� �޾ҽ��ϴ�!\n";
    if (health <= 0) {
        health = 0;
        std::cout << name << "��(��) ���������ϴ�!\n";
        int gold = getGold();
        std::cout << "ȹ�� ��� : " << gold << "\n";
    }
}

//���� ����
void Monster::status() const {
    std::cout << "[ " << name << " ]\n"
        << "ü�� : " << health
        << " ���ݷ� : " << attack << "\n";
}

// 1~100 ������ ���� ��� ��ȯ(�ӽ�)
int Monster::getGold() const {
    return rand() % 100 + 1;
}