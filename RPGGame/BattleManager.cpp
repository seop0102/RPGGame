#include "BattleManager.h"


bool BattleManager::doBattle(Character* player)
{

	//���� ����
	Monster* monster = new Monster();

	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{

		//���� ����
		monster->takeDamage(player->getAttack());

		player->takeDamage(monster->getAttack());


		if (monster->getHealth() <= 0) {

			std::cout << "���͸� óġ�߽��ϴ�!" << std::endl;

			player->addGold(monster->getGold()); // ���� óġ �� ��� �߰�
			player->addExp(50); // ���� óġ �� ����ġ �߰�
			player->levelUp(); // ����ġ�� ���� ������
			
			delete monster;

			return true; // ���� Ŭ����
			break;
		}

		if (player->getHealth() <= 0) {
			std::cout << "�÷��̾ ���������ϴ�!" << std::endl;

			delete monster;

			return false; // ���� ���� �� �� �������� �Լ� �θ���
			break;
		}
	}
}
