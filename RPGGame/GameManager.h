#pragma once

using namespace std;

class BattleManager;
class ShopManager;

class GameManager {


public:
	GameManager() = default;
	~GameManager() = default;

	void startGame();

	void endGame();


};