#pragma once
#include<string>

enum class ItemType //������ ����
{
	WEAPON,// ����
	ARMOR, // ��
	EDIBLE // �Ҹ�ǰ(ü�� �����̳� ���ݷ� ����)
};

enum class ItemTier // ������ ���
{
	NORAML, // �Ϲ�
	RARE,  // �߱�
	EPIC   // ���
};
class Item
{
private:
	std::string name;
	std::string description;
	ItemType type;
	ItemTier tier;
	int price;

	//ȿ�� ����(ȸ��,���ݷ�,����,��ų���Ƚ��, ��� ���뿩��)
	int healthRecover; // ȸ������ ü�� ȸ��
	int attackBonus;  // ���ݷ�( ���⳪ attack boost)
	int defenseBonus;  //����
	int skillCharges;   // ��ų ��� Ƚ��
	int maxhealthBonus; // �ִ� ü�� ����
	bool isEquipped;   // �����������

public:
	//������
	Item(const std::string& name, ItemType type, ItemTier tier,
		int healthRecover = 0, int skillCharges = 0, int attackBonus = 0,
		int defenseBonus = 0, int maxhealthBonus = 0, int price = 0);
	
	//getter �Լ�
	std::string getName()const;
	std::string getDescription()const;
	ItemType getType()const;
	ItemTier getTier()const;
	int getPrice()const;
	int getHealthRecover()const;
	int getAttackBonus()const;
	int getDefenseBonus()const;
	int getSkillCharges()const;
	int getMaxHealthBonus()const;
	bool getIsEquipped()const;

	//setter �Լ�
	void setName(const std::string& name);
	void setEquipped(bool equipped);
	void setPrice(int price);

	// ��ƿ��Ƽ? ���������� �� ���� �Լ�
	std::string getTypeString()const;
	std::string getTierString()const;
	std::string getIteminfo()const; // �������� ������ ������ ����

};