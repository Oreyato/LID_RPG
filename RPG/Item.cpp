#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(){}

Item::Item(std::string name, std::string description, float price, float weight, bool stackable, bool sellable)
{
	mName = name;
	mIType = ItemType::Basic;
	mDescription = description;
	mPrice = price;
	mWeight = weight;
	mStackable = stackable;
	mSellable = sellable;
}

Item::~Item()
{
}

std::string Item::GetName()
{
	return std::string(mName);
}

std::uint8_t Item::GetIType()
{
	return std::uint8_t(mIType);
}

std::string Item::GetDescription()
{
	return std::string(mDescription);
}

int Item::GetPrice()
{
	return mPrice;
}

float Item::GetWeight()
{
	return mWeight;
}

bool Item::IsStackable()
{
	return mStackable;
}

bool Item::IsSellable()
{
	return mSellable;
}

void Item::DisplaySumUp()
{
	string isStackable;
	string isSellable;

	(mStackable) ? isStackable = "True" : isStackable = "False";
	(mSellable) ? isSellable = "True" : isSellable = "False";

	cout << mName << " - " << mDescription << endl;
	cout << "\t Price: " << mPrice << " coins" << endl;
	cout << "\t Weight: " << mWeight << "g" << endl;
	cout << "\t Is stackable: " << isStackable << endl;
	cout << "\t Is sellable: " << isSellable << endl;
	cout << endl;
}
