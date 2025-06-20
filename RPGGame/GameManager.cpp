#include "GameManager.h"

GameManager::GameManager() {

	battleManager = new BattleManager();
	shopManager = new ShopManager();

}

void GameManager::startGame()
{

}

void GameManager::playGame()
{
	battleManager->doBattle();
	shopManager->openShop();
}

void GameManager::endGame()
{
}
