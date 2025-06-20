#include "Item.h"
#include<iostream>

// ������
Item::Item(const std::string& name, ItemType type, ItemTier tier,
	int healthRecover, int skillCharges, int attackBonus,
	int defenseBonus,int maxHealthBonus,int price)
	:name(name), type(type), tier(tier), healthRecover(healthRecover), skillCharges(skillCharges),
	attackBonus(attackBonus), defenseBonus(defenseBonus), maxHealthBonus(maxHealthBonus),
	price(price), isEquipped(false) {}
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
	return maxHealthBonus;
}

int Item::getPrice() const
{
	return price;
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
		if (maxHealthBonus > 0)info += "�ִ� ü�� +" + std::to_string(maxHealthBonus) + " ";
	}

	info += "- " + std::to_string(price) + " gold";
	return info;
}
// Edible Item ��
EdibleItem::EdibleItem(const std::string& name,ItemTier tier,int healthRecover,int skilCharges,
	int attackBonus,int price)
	:Item(name,ItemType::EDIBLE,tier,healthRecover,skillCharges,attackBonus,0,0,price)
	// tier ���ĺ��� ���� healthRecover, skillCharges, attackBonus, defenseBonus, maxHealthBonus, price
	// �Ҹ�ǰ�� ����, �ִ� ü�� ���� ����!
{ }
void EdibleItem::use()
{
	std::cout << name << "��(��) ����߽��ϴ�!" << std::endl;
	// ���� ��� ȿ���� ���ӸŴ����� ĳ���Ϳ��� �ϼž��ҵ�..
}
std::string EdibleItem::getEffect()const
{
	std::string effect = "";
	if (healthRecover > 0) effect += "ü�� ȸ�� +" + std::to_string(healthRecover) + " ";
	if (skillCharges > 0) effect += "��ų ��� Ƚ�� +" + std::to_string(skillCharges) + " ";
	if (attackBonus > 0) effect += "�ӽ� ���ݷ�+" + std::to_string(attackBonus) + " ";
	return effect;
}
bool EdibleItem::canUse()const
{
	return true; // �Ҹ�ǰ�� �׻� ��� �����ϰԲ�
}
// Weapon Item ��
WeaponItem::WeaponItem(const std::string& name,ItemTier tier,int attackBonus,int price)
	:Item(name,ItemType::WEAPON,tier,0,0,attackBonus,0,0,price)
	// ����� ü�� ȸ��, ��ų���Ƚ��,����,�ִ�ü�� ���� ����!
{ }
void WeaponItem::use()
{
	if (!isEquipped)
	{
		isEquipped = true;
		std::cout << name << "��(��) �����߽��ϴ�!" << std::endl;
	}
	else
	{
		std::cout << name << "��(��) �̹� �������Դϴ�!" << std::endl;
	}
}
std::string WeaponItem::getEffect()const
{
	return"���ݷ� +" + std::to_string(attackBonus);
}
bool WeaponItem::canUse()const
{
	return !isEquipped;//����� �������� �ʾ��� ���� ��� ����
}

// Armor Item ��
ArmorItem::ArmorItem(const std::string& name,ItemTier tier,int defenseBonus,int maxHealthBonus,int price)
	:Item(name,ItemType::ARMOR,tier,0,0,0,defenseBonus,maxHealthBonus,price)
	// ���� ü�� ȸ��, ��ų���Ƚ��,���ݷ� ����!
{ }
void ArmorItem::use()
{
	if (!isEquipped)
	{
		isEquipped = true;
		std::cout << name << "��(��) �����߽��ϴ�!" << std::endl;
	}
	else
	{
		std::cout << name << "��(��) �̹� �������Դϴ�!" << std::endl;
	}
}
std::string ArmorItem::getEffect()const
{
	std::string effect = "";
	if (defenseBonus > 0) effect += "���� +" + std::to_string(defenseBonus) + " ";
	if (maxHealthBonus > 0) effect += "�ִ� ü��+" + std::to_string(maxHealthBonus) + " ";
	return effect;
}
bool ArmorItem::canUse() const
{
	return !isEquipped; //���� �������� �ʾ��� ���� ��� ����
}
//
// ��� ����
// EdibleItem* healthPotion = new EdibleItem("ü�� ����", ItemTier::NORMAL, 100, 2, 0, 1100)
// WeaponItem* sword = new WeaponItem("ö��", ItemTier::RARE, 15, 2000);
// ArmorItem* lightArmor= nwe ArmorItem("����",ItemTier::EPIC,10,3,6000);
// 
// 

