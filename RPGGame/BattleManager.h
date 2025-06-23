#pragma once

#include "Character.h"
#include "Monster.h"
#include "Orc.h"
#include "Goblin.h"
#include "Utils.h"

enum class MonsterType {
	Orc,
	Goblin
};

class BattleManager
{
private:
	const int EXP = 50;

public:
	BattleManager() = default;
	~BattleManager() = default;


	bool doBattle(Character* player); //������ Ŭ���� �ϸ� true �ƴϸ� false ��ȯ

	Monster* CreateMonster(Character* player);
};