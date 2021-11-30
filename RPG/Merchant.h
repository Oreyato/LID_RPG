#pragma once
#include "PlayableCharacter.h"
class Merchant :
    public Character
{
protected:
    float mShopBuyMult;
    float mInitialShopBuyMult;
    float mShopSellMult;
    float mInitialShopSellMult;
    float mLoyaltyFactor;

public:
    Merchant();
    Merchant(std::string name, int maxHealth, int maxMana, float money = 50, float buyMult = 1, float sellMult = 1.5);
    ~Merchant();

    float GetShopBuyMult();
    float GetShopSellMult();

    void SetShopBuyMult(int value);
    void SetShopSellMult(int value);
    void ModifyShopBuyMult(int value);
    void ModifyShopSellMult(int value);

    void BuyItem(PlayableCharacter& customer, Item item);
    void SellItem(PlayableCharacter& customer, Item item);

    void Loyalty(float value);

    void DisplayShop();
};

