#include "Item.h"
// 생성자
Item::Item(const std::string& name, ItemType type, ItemTier tier,
	int healthRecover = 0, int skillCharges = 0, int attackBonus = 0,
	int defenseBonus = 0,int maxhealthBonus=0,int price)
	:name(name), type(type), tier(tier), price(price),
	healthRecover(healthRecover), skillCharges(skillCharges),
	attackBonus(attackBonus), defenseBonus(defenseBonus), maxhealthBonus(maxhealthBonus), isEquipped(false) {}
// getter 함수
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

// setter 함수
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

//유틸리티? 아이템 상점 정보 관련 함수

std::string Item::getTypeString()const
{
	switch (type)
	{
	case ItemType::WEAPON:return "무기";
	case ItemType::ARMOR:return"방어구";
	case ItemType::EDIBLE:return "소모품";
	default:return "알 수 없음";
	}

}

std::string Item::getTierString()const
{
	switch (tier)
	{
	case ItemTier::NORAML:return"일반";
	case ItemTier::RARE:return"중급";
	case ItemTier::EPIC:return"고급";
	default:return "알 수 없음";

	}
}
std::string Item::getIteminfo() const
{
	std::string info = name + "(" + getTierString() + ")-";

	if (type == ItemType::EDIBLE)// 소모품인 경우(회복물약,공격력 부스트)
	{
		if (healthRecover > 0)info += "체력 회복 +" + std::to_string(healthRecover) + " ";
		if (skillCharges > 0) info += "스킬 사용 횟수 +" + std::to_string(skillCharges) + " ";
		if (attackBonus > 0)info += "임시 공격력 +" + std::to_string(attackBonus) + " ";
	}
	else // 장비(무기, 방어구인 경우)
	{
		if (attackBonus > 0)info += "공격력 +" + std::to_string(attackBonus) + " ";
		if (defenseBonus > 0)info += "방어력 +" + std::to_string(defenseBonus) + " ";
		if (maxhealthBonus > 0)info += "최대 체력 +" + std::to_string(maxhealthBonus) + " ";
	}

	info += "- " + std::to_string(price) + " gold";
	return info;
}
//사용 예시
// 
// Item healthPotion("체력 물약", EDIBLE, NORMAL,  100,       2,        0,     0,      1000)
//                  (    이름   , 타입, 등급, 체력회복량,스킬사용횟수, 공격력, 방어력, 가격(골드))
// 
//
//	//  순서: name, type, tier, hp, skill, att, def, price
//	Item healthPotion("체력 물약", EDIBLE, NORMAL, 100, 2, 0, 0, 1100);
//	Item attackPotion("공격력 강화", EDIBLE, NORMAL, 0, 0, 10, 0, 150);
//	Item sword("철검", WEAPON, RARE, 0, 0, 15, 0, 2000);
//	Item armor("가죽갑옷", ARMOR, NORMAL, 0, 0, 0, 8, 1500);
//