#include "Merchant.h"
#include <string>

using namespace std;

Merchant::Merchant()
{
}

Merchant::Merchant(std::string name, int maxHealth, int maxMana, float money, float buyMult, float sellMult) {
	mName = name;
	mMaxHealth = maxHealth;
	mHealth = maxHealth;

	mMaxMana = maxMana;
	mMana = maxMana;

	mShopBuyMult = buyMult;
	mInitialShopBuyMult = buyMult;
	mShopSellMult = sellMult;
	mInitialShopSellMult = sellMult;

	mMoney = money;

	mLoyaltyFactor = 0;

}

Merchant::~Merchant()
{
}

float Merchant::GetShopBuyMult()
{
	return mShopBuyMult;
}

float Merchant::GetShopSellMult()
{
	return mShopSellMult;
}

void Merchant::SetShopBuyMult(int value)
{
	mShopBuyMult = value;
}

void Merchant::SetShopSellMult(int value)
{
	mShopSellMult = value;
}

void Merchant::ModifyShopBuyMult(int value)
{
	mShopBuyMult += value;
}

void Merchant::ModifyShopSellMult(int value)
{
	mShopSellMult += value;
}

void Merchant::BuyItem(PlayableCharacter& customer, Item item)
{
	float itemValue = item.GetPrice()*mShopBuyMult;
	Loyalty(itemValue / 100);

	AddItem(item);
	customer.RemoveItem(item.GetName()); 

	MoneyTransaction(-itemValue);
	customer.MoneyTransaction(itemValue);

	cout << customer.GetName() << " sold \"" << item.GetName() << "\" for " << itemValue << " coins" << endl;
}

void Merchant::SellItem(PlayableCharacter& customer, Item item)
{
	float itemValue = item.GetPrice() * mShopSellMult;
	string itemName = item.GetName();
	float customerWealth = customer.GetMoney();
	string customerName = customer.GetName();

	if (customerWealth >= itemValue) {
		Loyalty(itemValue / 50);

		RemoveItem(itemName);
		MoneyTransaction(itemValue);

		customer.AddItem(item);
		customer.MoneyTransaction(itemValue);

		cout << customerName << " bought " << itemName << " for " << itemValue << " coins" << endl;
	}
	else {
		cout << "You don't have enough money to buy this item, sorry!" << endl;
	}
}

void Merchant::Loyalty(float value)
{
	// Reward system
	// Buy - Sell more items, get better prices!

	mLoyaltyFactor += value;
	float mIBuy = mInitialShopBuyMult;
	float mISell = mInitialShopSellMult;

	if (0 <= mLoyaltyFactor	< 10) {
		mShopBuyMult = mIBuy + mIBuy * (1.0 / 50.0);
		mShopSellMult = mISell - mISell * (1.0 / 50.0);
	}
	else if (10 <= mLoyaltyFactor < 25) {
		mShopBuyMult = mIBuy + mIBuy * (1.0 / 25.0);
		mShopSellMult = mISell - mISell * (1.0 / 25.0);
	}
	else if (25 <= mLoyaltyFactor < 50) {
		mShopBuyMult = mIBuy + mIBuy * (1.0 / 10.0);
		mShopSellMult = mISell - mISell * (1.0 / 10.0);
	}
	else if (50 <= mLoyaltyFactor < 100) {
		mShopBuyMult = mIBuy + mIBuy * (1.0 / 5.0);
		mShopSellMult = mISell - mISell * (1.0 / 5.0);
	}
	else {
		mShopBuyMult = mIBuy * 2;
		mShopSellMult = mISell / 2;
	}
}

void Merchant::DisplayShop()
{
	string objectName;
	float objectPrice;

	for (int i = 0; i < mItems.size(); i++) {
		objectName = mItems[i].GetName();
		objectPrice = mItems[i].GetPrice() * mShopSellMult;

		cout << "\t" << i << " - " << objectName << " : " << objectPrice << " coins" << endl;
	}
}
