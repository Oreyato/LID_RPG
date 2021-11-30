#include "FireSpirit.h"

FireSpirit::FireSpirit()
{
	mName = "Arcus";
	mDescription = "The mighty Fire Spirit";
	mType = SpiritType::Fire;

	mPrestige = Prestige::Intermediate;
}

FireSpirit::~FireSpirit()
{
}

std::string FireSpirit::GetSpiritName()
{
	return mName;
}

std::string FireSpirit::GetSpiritDescription()
{
	return mDescription;
}

std::uint8_t FireSpirit::GetSpiritType()
{
	return mType;
}

std::uint8_t FireSpirit::GetSpiritPrestige()
{
	return mPrestige;
}

void FireSpirit::SpecialSpiritAction(PlayableCharacter& player)
{
	player.SetStrength(player.GetStrength() + 4);
}

void FireSpirit::PrestigeUp()
{
	if (mPrestige != Prestige::Pinnacle) {
		mPrestige << 1;
	}
}
