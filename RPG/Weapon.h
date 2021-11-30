#pragma once
#include "Item.h"

enum class WeaponType {
    Hand, // = 0
    Sword, // = 1
    Knife, // = 2
    Axe, // = 3
    Bow, // = 4
    Staff // = 5
};

class Weapon :
    public Item
{
private:
    WeaponType mType;
    int mAttackDamage;

public:
    Weapon();
    Weapon(std::string name, std::string desc, WeaponType type, int damage, int price = 0, float weight = 0, bool stackable = false, bool sellable = true);
    ~Weapon();
    WeaponType GetWeaponType();
    int GetAttackDamage();

    void DisplayWeaponType();
    void DisplayAttackDamage();
};

