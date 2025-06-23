#pragma once

#include "IClass.h"
#include "Character.h"

class Warrior : public IClass {
public:
    std::vector<SkillType> getActiveSkills() const override;
    void applyPassiveSkill(Character& self) override;
    void useSkill(SkillType skillType, Character& self, Monster& target) override;

    std::string getClassName() const override { return "¿ö¸®¾î"; }
};