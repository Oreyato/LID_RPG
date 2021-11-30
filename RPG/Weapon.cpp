#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name, std::string description, WeaponType type, int damage, int price, float weight, bool stackable, bool sellable)
{
	mName = name;
	mIType = ItemType::Weapon;
	mDescription = description;
	mType = type;

	mAttackDamage = damage;

	mPrice = price;
	mWeight = weight;
	mStackable = stackable;
	mSellable = sellable;
}

Weapon::~Weapon()
{
}

WeaponType Weapon::GetWeaponType()
{
	return mType;
}

int Weapon::GetAttackDamage()
{
	return mAttackDamage;
}

void Weapon::DisplayWeaponType()
{
	std::string weaponType;

	switch (mType)
	{
	case WeaponType::Sword:
		weaponType = "Sword";
		break;
	case WeaponType::Knife:
		weaponType = "Knife";
		break;
	case WeaponType::Axe:
		weaponType = "Axe";
		break;
	case WeaponType::Bow:
		weaponType = "Bow";
		break;
	case WeaponType::Staff:
		weaponType = "Staff";
		break;
	default:
		weaponType = "None";
		break;
	}

	std::cout << "Weapon type: " << weaponType << std::endl;
}

void Weapon::DisplayAttackDamage()
{
	std::cout << mAttackDamage;
}
