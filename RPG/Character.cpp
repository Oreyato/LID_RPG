#include "Character.h"

using namespace std;

Character::Character()
{
}

Character::Character(std::string name, int maxHealth, int maxMana, int strength, int initiative, int money)
{
	mName = name;
	mMaxHealth = maxHealth;
	mHealth = maxHealth;

	mStrength = strength;
	mInitiative = initiative;

	mMaxMana = maxMana;
	mMana = maxMana;

	mMoney = money;

	Weapon bareHand("Bare hand", "Not that efficient...", WeaponType::Hand, 1, 1);
	mWeapons.push_back(bareHand);
	_mWeapons.push_back(bareHand);

	mEquippedWeapon = bareHand;
}

Character::~Character()
{
	mItems.~vector();
}

std::string Character::GetName()
{
	return std::string(mName);
}

int Character::GetHealth()
{
	return mHealth;
}

int Character::GetMaxHealth()
{
	return mMaxHealth;
}

int Character::GetMana()
{
	return mMana;
}

int Character::GetMaxMana()
{
	return mMaxMana;
}

int Character::GetStrength()
{
	return mStrength;
}

int Character::GetInitiative()
{
	return mInitiative;
}

int Character::GetMoney()
{
	return mMoney;
}

Weapon Character::GetEquippedWeapon()
{
	return mEquippedWeapon;
}

std::vector<Item> Character::GetInventory()
{
	return mItems;
}

Item Character::GetInventoryItem(int index)
{
	return mItems[index];
}

bool Character::GetItemByIndex(int index, Item& item)
{
	int itemsNumber = mItems.size();
	
	if (0 <= index && index < itemsNumber) {
		item = mItems[index];
	}
	else {
		index = -1;
	}

	return (index != -1);
}


bool Character::GetItemByName(std::string name, Item& item)
{
	int itemIndex = -1;
	string itemName;
	
	for (int i = 0; i < mItems.size(); i++) {
		itemName = mItems[i].GetName();
		if (itemName == name) { 
			itemIndex = i;
			break;
		}
	}
	if(itemIndex != -1) item = mItems[itemIndex];
	
	return (itemIndex != -1);
}


void Character::Heal(int points)
{
	mHealth = ((mHealth + points) >= mMaxHealth) ? mMaxHealth : (mHealth + points);
}

void Character::Hurt(int points)
{
	mHealth = max((mHealth - points), 0);
	if (mHealth == 0) {
		cout << mName << " died!\n";
	}
	else DisplayHealth();
}

void Character::MaxLifeModifier(int points)
{
	mMaxHealth += points;
}

void Character::MaxManaModifier(int points)
{
	mMaxMana += points;
}

void Character::SetStrength(int value) {
	mStrength = value;
}

void Character::SetInitiave(int value) {
	mInitiative = value;
}

void Character::AddItem(Item item)
{
	mItems.push_back(item);

	if (item.GetIType() == ItemType::Weapon) {
		mWeapons.push_back(item);
	}
}

void Character::RemoveItem(string item)
{
	int itemIndex = 0;
	int weaponIndex = 0;
	string itemName = item;
	string tempItemName;

	bool isWeapon = false;

	for (int i = 0; i < mItems.size(); i++) {
		tempItemName = mItems[i].GetName();
		if (tempItemName == itemName) {
			itemIndex = i;

			if (mItems[i].GetIType() == ItemType::Weapon)
			{
				for (int i = 0; i < mWeapons.size(); i++) {
					tempItemName = mWeapons[i].GetName();

					if (tempItemName == itemName) {
						weaponIndex = i;

						break;
					}
				}
			}

			break;
		}
	}

	mItems.erase(mItems.begin() + itemIndex);
	if (isWeapon) mWeapons.erase(mWeapons.begin() + weaponIndex);
}

void Character::MoneyTransaction(int value)
{
	mMoney += value;
}

void Character::DisplayHealth()
{
	cout << "  >> " << mName << " has " << mHealth << " health.\n";
 }

void Character::DisplayItem(int index)
{
	mItems[index].DisplaySumUp();
}

void Character::DisplayWeapon()
{
	cout << "\n" << mName << "'s weapons: (enter a number)\n";
	string objectName;
	string objectDescription;

	for (int i = 0; i < mWeapons.size(); i++) {
		objectName = mWeapons[i].GetName();
		string objectDescription = mWeapons[i].GetDescription();

		cout << "\t" << i << "- " << objectName << " | " << objectDescription << endl;
	}
}


void Character::DisplayInventory()
{
	cout << "\n" << mName << "'s inventory:\n";
	string objectName;

	vector<Item>::iterator i;
 
	for (i = mItems.begin(); i < mItems.end(); i++) {
		objectName = i->GetName();
		cout << "\t" << objectName << endl;
	}
	cout << endl;
}

void Character::DisplayShopOrientedInventory()
{
	cout << "\n" << mName << "'s inventory:\n";
	string objectName;
	float objectPrice;

	int itemIndex = 0;

	vector<Item>::iterator i;

	for (i = mItems.begin(); i < mItems.end(); i++) {
		objectName = i->GetName();
		objectPrice = i->GetPrice();

		cout << "\t" << itemIndex << " - " << objectName << " : " << objectPrice << " coins" << endl;

		itemIndex += 1;
	}
}

void Character::DisplayMoney()
{
	cout << mName << " currently have " << mMoney << " coins" << endl;
}
