#include "GameManager.h"

GameManager::GameManager() {

	battleManager = new BattleManager();
	shopManager = new ShopManager();

}

void GameManager::startGame()
{
	cout << "�÷��̾��� �̸��� �Է� �ϼ���" << endl;

	string playerName;
	cin >> playerName;

	player = Character::getInstance(playerName);
}

void GameManager::playGame()
{
	if (battleManager->doBattle(player)) 
	{
		cout << "������ Ŭ���� �߽��ϴ�!" << endl;
		player->displayStat();

		shopManager->openShop();

	}
	else
	{
		cout << "������ �����߽��ϴ�. ������ �����մϴ�." << endl;
		endGame();
		return;
	}
	
}

void GameManager::endGame()
{
}
