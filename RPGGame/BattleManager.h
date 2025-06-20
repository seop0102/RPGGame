#pragma once

#include "Character.h"
#include "Monster.h"

class BattleManager
{

public:
	BattleManager() = default;
	~BattleManager() = default;

	bool doBattle(Character* player); //전투를 클리어 하면 true 아니면 false 반환

};