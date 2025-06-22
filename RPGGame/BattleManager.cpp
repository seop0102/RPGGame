#include "BattleManager.h"


bool BattleManager::doBattle(Character* player)
{

	//몬스터 생성
	Monster* monster = new Monster();

	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{

		//전투 구현
		monster->takeDamage(player->getAttack());

		player->takeDamage(monster->getAttack());


		if (monster->getHealth() <= 0) {

			std::cout << "몬스터를 처치했습니다!" << std::endl;

			player->addGold(monster->getGold()); // 몬스터 처치 시 골드 추가
			player->addExp(50); // 몬스터 처치 시 경험치 추가
			player->levelUp(); // 경험치에 따라 레벨업
			
			delete monster;

			return true; // 전투 클리어
			break;
		}

		if (player->getHealth() <= 0) {
			std::cout << "플레이어가 쓰러졌습니다!" << std::endl;

			delete monster;

			return false; // 전투 실패 이 후 게임종료 함수 부르기
			break;
		}
	}
}
