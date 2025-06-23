#include "BattleManager.h"


bool BattleManager::doBattle(Character* player)
{
	Monster* monster = CreateMonster(player);

	if (player->getLevel() >= 10) {

		cout << "���� 10 �̻�! ���� ���Ͱ� �����մϴ�!" << endl;
		monster->setHealth(int(monster->getHealth() * 1.5)); // ���� 10 �̻��� �� ���� ���� ����
		monster->setAttack(int(monster->getAttack() * 1.5)); // ���� 10 �̻��� �� ���� ���� ����

	}

	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{

		//���� ����
		monster->takeDamage(player->getAttack());

		player->takeDamage(monster->getAttack());
		//

		if (monster->getHealth() <= 0) {

			std::cout << "���͸� óġ�߽��ϴ�!" << std::endl;

			player->addGold(monster->getGold()); // ���� óġ �� ��� �߰�
			
			if (monster->dropItem() != nullptr) {
				std::cout << "�������� ȹ���߽��ϴ�: " << monster->dropItem()->getName() << std::endl;
				player->addItem(monster->dropItem()); // �÷��̾�� ������ �߰�
			}

			player->addExp(EXP); // ���� óġ �� ����ġ �߰�
			
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

Monster* BattleManager::CreateMonster(Character* player)
{
	MonsterType monster = static_cast<MonsterType>(Utils::getRandomInt(0, 1));

	switch (monster) {
	case MonsterType::Orc:
		return new Orc(player->getLevel());
	case MonsterType::Goblin:
		return new Goblin(player->getLevel());
	default:
		return nullptr;
	}
}
