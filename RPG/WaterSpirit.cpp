#include "WaterSpirit.h"

WaterSpirit::WaterSpirit()
{
	mName = "Ondule";
	mDescription = "The mighty Water Spirit";
	mType = SpiritType::Water;

	mPrestige = Prestige::Intermediate;
}

WaterSpirit::~WaterSpirit()
{
}

std::string WaterSpirit::GetSpiritName()
{
	return mName;
}

std::string WaterSpirit::GetSpiritDescription()
{
	return mDescription;
}

std::uint8_t WaterSpirit::GetSpiritType()
{
	return mType;
}

std::uint8_t WaterSpirit::GetSpiritPrestige()
{
	return mPrestige;
}

void WaterSpirit::SpecialSpiritAction(PlayableCharacter& player)
{
	player.Heal(15);
}

void WaterSpirit::PrestigeUp()
{
	if (mPrestige != Prestige::Pinnacle) {
		mPrestige << 1;
	}
}
