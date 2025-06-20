#pragma once

#include "Character.h"
#include "Monster.h"

class BattleManager
{

public:
	BattleManager() = default;
	~BattleManager() = default;

	void doBattle(Character* player, Monster* monster);

};