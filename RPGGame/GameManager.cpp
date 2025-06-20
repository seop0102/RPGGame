#include "GameManager.h"

GameManager::GameManager() {

	battleManager = new BattleManager();
	shopManager = new ShopManager();

}

void GameManager::startGame()
{
	cout << "플레이어의 이름을 입력 하세요" << endl;

	string playerName;
	cin >> playerName;

	player = Character::getInstance(playerName);
}

void GameManager::playGame()
{
	if (battleManager->doBattle(player)) 
	{
		cout << "전투를 클리어 했습니다!" << endl;
		player->displayStat();

		shopManager->openShop();

	}
	else
	{
		cout << "전투에 실패했습니다. 게임을 종료합니다." << endl;
		endGame();
		return;
	}
	
}

void GameManager::endGame()
{
}
