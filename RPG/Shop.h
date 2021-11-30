#pragma once
#include "Merchant.h"

class Shop
{
private:
	bool mIsInShop;
	Merchant mMerchant;
	PlayableCharacter mCharacter;

public:
	Shop();
	Shop(PlayableCharacter& character, Merchant& merchant);
	~Shop();

	void ShopLoop();
	void Inputs();
	void ShopDisplay(int menu);
};

