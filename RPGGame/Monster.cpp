#include "Monster.h"
#include <iostream>
#include <cstdlib>

// 받는 데미지
// 30%확률로 아이템 드랍 추가 해야 함
// 몬스터가 쓰러지면 골드 드랍 골드 캐릭터 연동 추가 해야 함
void Monster::takeDamage(int damage) {
    health -= damage;
    std::cout << name << "이(가) " << damage << "의 데미지를 받았습니다!\n";
    if (health <= 0) {
        health = 0;
        std::cout << name << "이(가) 쓰러졌습니다!\n";
        int gold = getGold();
        std::cout << "획득 골드 : " << gold << "\n";
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