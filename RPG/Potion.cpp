#include "Potion.h"

Potion::Potion()
{
}

Potion::Potion(std::string name, std::string description, std::uint8_t mPType, int effect, float price, float weight, bool stackable, bool sellable)
{
	mName = name;
	mIType = ItemType::Potion;
	mDescription = description;

	mEffect = effect;

	mPrice = price;
	mWeight = weight;
	mStackable = stackable;
	mSellable = sellable;
}

Potion::~Potion()
{
}

std::uint8_t Potion::GetPotionType()
{
	return std::uint8_t(mPType);
}

int Potion::GetEffect()
{
	return mEffect;
}

void Potion::DisplayPotionCharacteristics()
{
	std::string potionType;

	switch (mPType)
	{
	case PotionType::Heal:
		potionType = "Healing";
		break;
	case PotionType::Mana:
		potionType = "Mana";
		break;
	case PotionType::Strength:
		potionType = "Strength";
		break;
	case PotionType::Initiative:
		potionType = "Initiative";
		break;
	case PotionType::Dexterity:
		potionType = "Dexterity";
		break;

	default:
		potionType = "ERROR:_UNKNOWN_POTION_TYPE";
		break;
	}

	std::cout << potionType << " potion [";
	DisplayEffect();
}

void Potion::DisplayEffect()
{
	if (mEffect >= 0)
	{
		std::cout << "+" << mEffect << "]" << std::endl;
	}
	else std::cout << "-" << mEffect << "]" << std::endl;
}
