#pragma once

#include "BattleManager.h"
#include "ShopManager.h"
#include "StoryManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;

class BattleManager;
class ShopManager;
class StoryManager;
class Character;

class GameManager {

public:

	BattleManager* battleManager;
	ShopManager* shopManager;
	StoryManager* storyManager;

	Character* player;

public:
	GameManager();
	~GameManager() = default;

	void startGame();

	void playGame();

	void endGame();

	Monster createMonster(const string& monsterName, int health, int attack) {
};