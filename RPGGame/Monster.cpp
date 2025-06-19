#include "Monster.h"
#include <iostream>
#include <cstdlib>

// 받는 데미지
// 30%확률로 아이템 드랍 추가 해야 함
void Monster::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
    }
}

//몬스터 스텟
void Monster::status() const {
    std::cout << "[ " << name << " ]\n"
        << "체력 : " << health
        << " 공격력 : " << attack << "\n";
}

// 1~100 사이의 랜덤 골드 반환(임시)
int Monster::getGold() const {
    return rand() % 100 + 1;
}