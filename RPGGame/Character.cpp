#include "Character.h"
#include "Item.h"
#include "IClass.h"
#include "Utils.h"
#include "Monster.h"
#include "ICombatant.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <map>

Character::Character(std::string name, std::unique_ptr<IClass> selectedClass)
	: name(name),
	level(1),
	health(200),
	maxHealth(200),
	attack(30),
	defense(10), // 기본 방어력 설정 (필요시)
	criticalChance(10), // 기본 치명타 확률 (필요시)
	hitChance(85), // 기본 명중률 설정 (필요시)
	dodgeChance(5), // 기본 회피율 설정 (필요시)
	exp(0),
	gold(0),
	equippedWeapon(nullptr), equippedArmor(nullptr)
{
	characterClass = move(selectedClass);
}

void Character::displayStat()
{
	std::cout << "--------상태 창--------" << std::endl;
	std::cout << "이름: " << name << std::endl;
	std::cout << "레벨: " << level << std::endl;
	std::cout << "체력: " << health << "/" << maxHealth << std::endl;
	std::cout << "공격력: " << attack << std::endl;
	std::cout << "경험치: " << exp << std::endl;
	std::cout << "골드: " << gold << std::endl;
	std::cout << "----------------------" << std::endl;
}

void Character::levelUp()
{
	const int MAX_LEVEL = 10;
	const int EXP_TO_NEXT_LEVEL = level * 100;

	if (level >= MAX_LEVEL) {
		std::cout << "10레벨에 도달했습니다!" << std::endl;
		return;
	}

	if (exp >= EXP_TO_NEXT_LEVEL) {
		level++;
		exp -= EXP_TO_NEXT_LEVEL;

		maxHealth += 20; // 최대 체력 증가
		health = maxHealth; // 체력 회복
		attack += 5; // 공격력 증가

		std::cout << "레벨 업 :" << level << "이(가) 되었습니다." << std::endl;
		std::cout << "최대 체력 +20, 공격력 +5 증가" << std::endl;
	}
	else {
		std::cout << "경험치가 부족합니다. 다음 레벨업 까지 " << (EXP_TO_NEXT_LEVEL - exp) << "경험치가 더 필요합니다." << std::endl;
	}
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
	}
}

// 골드 추가 함수
void Character::addGold(int amount)
{
    gold += amount;
    std::cout << amount << " G를 획득했습니다. 현재 골드: " << gold << std::endl;
}

// 경험치 추가 함수
void Character::addExp(int amount)
{
    exp += amount;
    std::cout << amount << " 경험치를 획득했습니다. 현재 경험치: " << exp << std::endl;
    // 경험치 획득 후 레벨업 체크
    levelUp();
}

// 골드 제거 함수
void Character::removeGold(int amount)
{
    if (gold >= amount) {
        gold -= amount;
        std::cout << amount << " G를 사용했습니다. 현재 골드: " << gold << std::endl;
    }
    else {
        std::cout << "골드가 부족합니다." << std::endl;
    }
}

// 아이템 추가 함수
void Character::addItem(Item* item)
{
	if (inventory.size() >= 10) { // 인벤토리 최대 10개 아이템
		showInventory();
		std::cout << "인벤토리가 가득 찼습니다. 다른 아이템을 버리시겠습니까?" << std::endl;
		
		//선택지 추가 예정
		int index = 0;
		item; // 아이템 정보 출력
		swap(item, inventory[index]); // 마지막 아이템과 교체

		delete item;
	
	}

    inventory.push_back(item);
    std::cout << item->getName() << "을(를) 인벤토리에 추가했습니다." << std::endl;
}

// 아이템 제거 함수
void Character::removeItem(int index)
{
    if (index >= 0 && index < inventory.size()) {
        std::cout << inventory[index]->getName() << "을(를) 인벤토리에서 제거했습니다." << std::endl;
        inventory.erase(inventory.begin() + index);
    }
    else {
        std::cout << "잘못된 아이템 인덱스입니다." << std::endl;
    }
}

void Character::showInventory() const
{
	for (Item* i : inventory)
	{
		//아이템 정보 출력
	}

}

void Character::equipWeapon(WeaponItem* weapon) {
	if (equippedWeapon != nullptr)
	{
		swap(equippedWeapon, weapon); // 기존 무기와 교체
	}
	else
	{
		equippedWeapon = weapon; // 무기 장착
	}
}

void Character::equipArmor(ArmorItem* armor)
{
	if (equippedWeapon != nullptr)
	{
		swap(equippedArmor, armor); // 기존 방어구와 교체
	}
	else
	{
		equippedArmor = armor; // 방어구 장착
	}
}

void Character::useItem(int itemindex) {
    if (inventory.empty() || itemindex < 0 || itemindex >= inventory.size())
    {
	    std::cout << "잘못된 아이템 인덱스입니다." << std::endl;
	    return;
    }

    EdibleItem* edible = dynamic_cast<EdibleItem*>(inventory[itemindex]);

    if (edible)
    {
	    edible->use(); // 아이템 사용
    }
    else
    {
	    std::cout << "사용할 수 없는 아이템입니다." << std::endl;
	    return;

    }

    removeItem(itemindex); // 아이템 사용 후 인벤토리에서 제거
}



vector<SkillType> Character::getActiveSkills() {
	if (characterClass) return characterClass->getActiveSkills();
	return {};
}

void Character::useSkill(SkillType skillType, Character& self, Monster& target) {
	if (characterClass) {
		// 스킬 사용 횟수 체크, 감소
		if (skillUsages.count(skillType) && skillUsages[skillType] > 0) {
			characterClass->useSkill(skillType, self, target); // 스킬 효과 위임
			// 특수 스킬 횟수 차감용
			if (skillType == SkillType::ROGUE4 || skillType == SkillType::WARRIOR4 || skillType == SkillType::ARCHER4) {
				skillUsages[skillType]--;
			}
		}
		else {
			std::cout << "스킬 '" << getSkillName(skillType) << "'의 사용 횟수가 부족합니다." << std::endl;
		}
	}
}

void Character::applyPassiveSkill(Character & self) {
	if (characterClass) characterClass->applyPassiveSkill(self);
}

string Character::getClassName() {
	if (characterClass) return characterClass->getClassName();
	return "알수 없음";
}

// 스킬 사용 횟수 초기화 함수
void Character::initializeSkillUsages() {
    // 모든 스킬 타입을 가져와서 초기 사용 횟수를 설정합니다.
    // 각 직업의 스킬 사용 횟수를 어떻게 정할지는 게임 디자인에 따라 다릅니다.
    // 여기서는 일반 스킬은 99, 특정 스킬(숨기, 버티기, 망령 화살)은 1로 설정합니다.
    for (int i = static_cast<int>(SkillType::ROGUE1); i <= static_cast<int>(SkillType::WARRIOR4); ++i) {
        SkillType type = static_cast<SkillType>(i);
        if (type == SkillType::ROGUE4 || type == SkillType::WARRIOR4 || type == SkillType::ARCHER4) {
            skillUsages[type] = 1; // 특수 스킬 (숨기, 버티기, 망령 화살)은 1회 사용 가능
        }
        else {
            skillUsages[type] = 99; // 일반 스킬은 무제한 (테스트 목적)
        }
    }
    // BASIC_ATTACK은 스킬 사용 횟수 개념이 없으므로 제외
}

// 스킬 사용 횟수 복원 함수
void Character::restoreSkillUsage(SkillType skillType, int amount) {
    if (skillUsages.count(skillType)) {
        skillUsages[skillType] += amount;
        std::cout << getSkillName(skillType) << " 스킬 사용 횟수가 " << amount << "만큼 회복되었습니다. 현재 " << skillUsages[skillType] << "회." << std::endl;
    }
}

// 남은 스킬 사용 횟수 반환 함수
int Character::getRemainingSkillUsage(SkillType skillType) const {
    if (skillUsages.count(skillType)) {
        return skillUsages.at(skillType);
    }
    return 0; // 해당 스킬이 없으면 0 반환
}

// 스킬 타입에 따른 이름 반환 함수
std::string Character::getSkillName(SkillType skillType) const {
    switch (skillType) {
    case SkillType::BASIC_ATTACK: return "기본 공격";
        // 도적 스킬
    case SkillType::ROGUE1: return "찢기";
    case SkillType::ROGUE2: return "날렵한 손";
    case SkillType::ROGUE3: return "급습";
    case SkillType::ROGUE4: return "숨기";
        // 궁수 스킬
    case SkillType::ARCHER1: return "화살 명중";
    case SkillType::ARCHER2: return "조준";
    case SkillType::ARCHER3: return "폭풍 화살";
    case SkillType::ARCHER4: return "망령 화살";
        // 워리어 스킬
    case SkillType::WARRIOR1: return "베기";
    case SkillType::WARRIOR2: return "방패";
    case SkillType::WARRIOR3: return "강타";
    case SkillType::WARRIOR4: return "버티기";
    default: return "알 수 없는 스킬";
    }
}