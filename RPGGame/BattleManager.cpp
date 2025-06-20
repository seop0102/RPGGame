#include "BattleManager.h"


void BattleManager::doBattle(Character* player, Monster* monster)
{
	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{

		//���� ����
		monster->takeDamage(player->getAttack());

		player->takeDamage(monster->getAttack());


		if (monster->getHealth() <= 0) {
			player->addGold(monster->getGold()); // ���� óġ �� ��� �߰�
			player->addExp(50); // ���� óġ �� ����ġ �߰�
			std::cout << "���͸� óġ�߽��ϴ�!" << std::endl;
			break;
		}

		if (player->getHealth() <= 0) {
			std::cout << "�÷��̾ ���������ϴ�!" << std::endl;
			break;
		}
	}
}
