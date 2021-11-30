#pragma once
#include "Item.h"
#include "PotionType.h"

class Potion :
	public Item	
{
private:
	std::uint8_t mPType;
	int mEffect;

public:
	Potion();
	Potion(std::string name, std::string description, std::uint8_t mPType, int effect, float price = 10, float weight = 250, bool stackable = true, bool sellable = true);
	~Potion();
	std::uint8_t GetPotionType();
	int GetEffect();

	void DisplayPotionCharacteristics();
	void DisplayEffect();
};

