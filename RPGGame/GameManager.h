#pragma once

#include "BattleManager.h"
#include "ShopManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;

class BattleManager;
class ShopManager;
class Character;

class GameManager {

private:

	BattleManager* battleManager;
	ShopManager* shopManager;

	Character* player;

public:
	GameManager();
	~GameManager() = default;

	void startGame();

	void playGame();

	void endGame();

	Monster createMonster(const string& monsterName, int health, int attack) {
};