#include "BattleManager.h"


void BattleManager::doBattle(Character* player, Monster* monster)
{
	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{

		//전투 구현
		monster->takeDamage(player->getAttack());

		player->takeDamage(monster->getAttack());


		if (monster->getHealth() <= 0) {
			player->addGold(monster->getGold()); // 몬스터 처치 시 골드 추가
			player->addExp(50); // 몬스터 처치 시 경험치 추가
			std::cout << "몬스터를 처치했습니다!" << std::endl;
			break;
		}

		if (player->getHealth() <= 0) {
			std::cout << "플레이어가 쓰러졌습니다!" << std::endl;
			break;
		}
	}
}
