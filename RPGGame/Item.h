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
protected: // private>protected �� �ؼ� ��Ӱ����ϰԲ�
	std::string name;
	std::string description;
	ItemType type;
	ItemTier tier;
	int price;

	//ȿ�� ����(ȸ��,���ݷ�,����,��ų���Ƚ��, ��� ���뿩��)
	int healthRecover; // ȸ�������� ü�� ȸ��
	int attackBonus;  // ���ݷ�( ���⳪ attack boost)
	int defenseBonus;  //����
	int skillCharges;   // ��ų ��� Ƚ��
	int maxHealthBonus; // �ִ� ü�� ����
	bool isEquipped;   // ��� ���� �ߴ��� ����

public:
	//������
	Item(const std::string& name, ItemType type, ItemTier tier,
		int healthRecover = 0, int skillCharges = 0, int attackBonus = 0,
		int defenseBonus = 0, int maxHealthBonus = 0, int price = 0);

	// ���� �Ҹ���
	virtual~Item() = default;

	//���������Լ�(�������̽�)
	virtual void use() = 0; // ������ ���
	virtual std::string getEffect() const = 0; // ������ ȿ�� ����
	virtual bool canUse() const = 0; // ��� ���� ����
	
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

//��ü���� ������ Ŭ����
// �Ҹ�ǰ
class EdibleItem : public Item
{
public: // �Ҹ�ǰ���� ���� ������ �ִ� ü�� ���� ����
	EdibleItem(const std::string& name, ItemTier tier, int healthRecover, int skillCharges,
		int attakBonus,int price);

	//���������Լ� �κ�
	void use() override;
	std::string getEffect() const override;
	bool canUse() const override;
};

// ������-����
class WeaponItem :public Item
{
public:
	WeaponItem(const std::string& name, ItemTier tier, int attackBonus, int price);

	// ���������Լ� �κ�
	void use() override;
	std::string getEffect()const override;
	bool canUse() const override;
};

// ������-��
class ArmorItem :public Item
{
public:
	ArmorItem(const std::string& name, ItemTier tier, int defenseBonus, int maxHealthBonus, int price);

	//���������Լ� �κ�
	void use() override;
	std::string getEffect() const override;
	bool canUse() const override;
};

