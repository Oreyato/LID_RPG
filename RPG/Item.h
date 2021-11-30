#pragma once
#include <iostream>
#include <string>
#include "ItemType.h"

class Item
{
protected:
	std::string mName;
	std::uint8_t mIType;
	std::string mDescription;
	float mPrice;
	float mWeight;
	bool mStackable;
	bool mSellable;

public:
	Item();
	Item(std::string name, std::string description, float price, float weight, bool stackable, bool sellable);
	~Item();

	std::string GetName();
	std::uint8_t GetIType();
	std::string GetDescription();
	int GetPrice();
	float GetWeight();
	bool IsStackable();
	bool IsSellable();
	//For the record:
	//Boolean setter: void IsStackable(bool s) 

	void DisplaySumUp();
};

