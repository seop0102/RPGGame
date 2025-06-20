#pragma once
#include<string>

enum class ItemType //아이템 종류
{
	WEAPON,// 무기
	ARMOR, // 방어구
	EDIBLE // 소모품(체력 포션이나 공격력 포션)
};

enum class ItemTier // 아이템 등급
{
	NORAML, // 일반
	RARE,  // 중급
	EPIC   // 고급
};
class Item
{
private:
	std::string name;
	std::string description;
	ItemType type;
	ItemTier tier;
	int price;

	//효과 관련(회복,공격력,방어력,스킬사용횟수, 장비 착용여부)
	int healthRecover; // 회복물약 체력 회복
	int attackBonus;  // 공격력( 무기나 attack boost)
	int defenseBonus;  //방어력
	int skillCharges;   // 스킬 사용 횟수
	int maxhealthBonus; // 최대 체력 증가
	bool isEquipped;   // 장비장착여부

public:
	//생성자
	Item(const std::string& name, ItemType type, ItemTier tier,
		int healthRecover = 0, int skillCharges = 0, int attackBonus = 0,
		int defenseBonus = 0, int maxhealthBonus = 0, int price = 0);
	
	//getter 함수
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

	//setter 함수
	void setName(const std::string& name);
	void setEquipped(bool equipped);
	void setPrice(int price);

	// 유틸리티? 아이템정보 및 가격 함수
	std::string getTypeString()const;
	std::string getTierString()const;
	std::string getIteminfo()const; // 상점에서 보여줄 아이템 정보

};