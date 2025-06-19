#include "Monster.h"
#include <iostream>
#include <cstdlib>

// �޴� ������
// 30%Ȯ���� ������ ��� �߰� �ؾ� ��
void Monster::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
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