#pragma once

#include "Character.h"
#include "Monster.h"

class BattleManager
{

public:
	BattleManager() = default;
	~BattleManager() = default;

	bool doBattle(Character* player); //������ Ŭ���� �ϸ� true �ƴϸ� false ��ȯ

};