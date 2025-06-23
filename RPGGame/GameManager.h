#pragma once

#include "BattleManager.h"
#include "ShopManager.h"
#include "StoryManager.h"
#include "Character.h"
#include "IClass.h"
#include "Rogue.h"
#include "Archer.h"
#include "Warrior.h"
#include "Monster.h"
#include <memory>

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

};