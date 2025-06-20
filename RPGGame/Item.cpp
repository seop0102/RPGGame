#include "Item.h"
// ������
Item::Item(const std::string& name, ItemType type, ItemTier tier,
	int healthRecover = 0, int skillCharges = 0, int attackBonus = 0,
	int defenseBonus = 0,int maxhealthBonus=0,int price)
	:name(name), type(type), tier(tier), price(price),
	healthRecover(healthRecover), skillCharges(skillCharges),
	attackBonus(attackBonus), defenseBonus(defenseBonus), maxhealthBonus(maxhealthBonus), isEquipped(false) {}
// getter �Լ�
std::string Item::getName()const
{
	return name;
}
std::string Item::getDescription()const
{
	return description;
}
ItemType Item::getType() const
{
	return type;
}
ItemTier Item::getTier() const
{
	return tier;
}
int Item::getPrice() const
{
	return price;
}
int Item::getHealthRecover() const
{
	return healthRecover;
}
int Item::getAttackBonus() const 
{
	return attackBonus;
}

int Item::getDefenseBonus() const 
{
	return defenseBonus;
}

int Item::getSkillCharges() const 
{
	return skillCharges;
}

int Item::getMaxHealthBonus()const
{
	return maxhealthBonus;
}

bool Item::getIsEquipped() const 
{
	return isEquipped;
}

// setter �Լ�
void Item::setName(const std::string& name)
{
	this->name = name;
}
void Item::setEquipped(bool equipped)
{
	this->isEquipped = equipped;
}
void Item::setPrice(int price)
{
	this->price = price;
}

//��ƿ��Ƽ? ������ ���� ���� ���� �Լ�

std::string Item::getTypeString()const
{
	switch (type)
	{
	case ItemType::WEAPON:return "����";
	case ItemType::ARMOR:return"��";
	case ItemType::EDIBLE:return "�Ҹ�ǰ";
	default:return "�� �� ����";
	}

}

std::string Item::getTierString()const
{
	switch (tier)
	{
	case ItemTier::NORAML:return"�Ϲ�";
	case ItemTier::RARE:return"�߱�";
	case ItemTier::EPIC:return"���";
	default:return "�� �� ����";

	}
}
std::string Item::getIteminfo() const
{
	std::string info = name + "(" + getTierString() + ")-";

	if (type == ItemType::EDIBLE)// �Ҹ�ǰ�� ���(ȸ������,���ݷ� �ν�Ʈ)
	{
		if (healthRecover > 0)info += "ü�� ȸ�� +" + std::to_string(healthRecover) + " ";
		if (skillCharges > 0) info += "��ų ��� Ƚ�� +" + std::to_string(skillCharges) + " ";
		if (attackBonus > 0)info += "�ӽ� ���ݷ� +" + std::to_string(attackBonus) + " ";
	}
	else // ���(����, ���� ���)
	{
		if (attackBonus > 0)info += "���ݷ� +" + std::to_string(attackBonus) + " ";
		if (defenseBonus > 0)info += "���� +" + std::to_string(defenseBonus) + " ";
		if (maxhealthBonus > 0)info += "�ִ� ü�� +" + std::to_string(maxhealthBonus) + " ";
	}

	info += "- " + std::to_string(price) + " gold";
	return info;
}
//��� ����
// 
// Item healthPotion("ü�� ����", EDIBLE, NORMAL,  100,       2,        0,     0,      1000)
//                  (    �̸�   , Ÿ��, ���, ü��ȸ����,��ų���Ƚ��, ���ݷ�, ����, ����(���))
// 
//
//	//  ����: name, type, tier, hp, skill, att, def, price
//	Item healthPotion("ü�� ����", EDIBLE, NORMAL, 100, 2, 0, 0, 1100);
//	Item attackPotion("���ݷ� ��ȭ", EDIBLE, NORMAL, 0, 0, 10, 0, 150);
//	Item sword("ö��", WEAPON, RARE, 0, 0, 15, 0, 2000);
//	Item armor("���װ���", ARMOR, NORMAL, 0, 0, 0, 8, 1500);
//