#include "WindSpirit.h"

WindSpirit::WindSpirit()
{
	mName = "Helios";
	mDescription = "The mighty Wind Spirit";
	mType = SpiritType::Wind;

	mPrestige = Prestige::Intermediate;
}

WindSpirit::~WindSpirit()
{
}

std::string WindSpirit::GetSpiritName()
{
	return mName;
}

std::string WindSpirit::GetSpiritDescription()
{
	return mDescription;
}

std::uint8_t WindSpirit::GetSpiritType()
{
	return mType;
}

std::uint8_t WindSpirit::GetSpiritPrestige()
{
	return mPrestige;
}

void WindSpirit::SpecialSpiritAction(PlayableCharacter& player)
{
	player.SetInitiave(player.GetInitiative() + 2);
}

void WindSpirit::PrestigeUp()
{
	if (mPrestige != Prestige::Pinnacle) {
		mPrestige << 1;
	}
}
