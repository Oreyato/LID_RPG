#pragma once
#include <string>
#include <vector>

#include "Weapon.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
protected:
	std::string mName;
	int mHealth;
	int mMaxHealth;
	int mMana;
	int mMaxMana;

	int mStrength;
	int mInitiative;

	int mMoney;

	Weapon mEquippedWeapon;
	std::vector<Item> mItems;
	std::vector<Item> mWeapons;
	std::vector<Weapon> _mWeapons;

public:
	Character();
	Character(std::string name, int maxHealth, int maxMana, int strength=3, int initiative=1, int money=5);
	~Character();

	std::string GetName();
	int GetHealth();
	int GetMaxHealth();
	int GetMana();
	int GetMaxMana();

	int GetStrength();
	int GetInitiative();

	int GetMoney();
	Weapon GetEquippedWeapon();
	std::vector<Item> GetInventory();
	Item GetInventoryItem(int index);

	bool GetItemByIndex(int index, Item& item);
	bool GetItemByName(std::string name, Item& item);

	void Heal(int points);
	void Hurt(int points);
	void MaxLifeModifier(int points);
	void MaxManaModifier(int points);
	void SetStrength(int value);
	void SetInitiave(int value);

	void AddItem(Item item);
	void RemoveItem(std::string item);
	void MoneyTransaction(int value);

	void DisplayHealth();
	void DisplayItem(int index);
	void DisplayWeapon();
	void DisplayInventory();
	void DisplayShopOrientedInventory();
	void DisplayMoney();
};

#endif // !CHARACTER_H

