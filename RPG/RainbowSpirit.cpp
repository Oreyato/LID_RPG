#include "RainbowSpirit.h"

RainbowSpirit::RainbowSpirit()
{
	mName = "Arcus";
	mDescription = "The mighty Fire Spirit";
	mType = SpiritType::Fire | SpiritType::Water | SpiritType::Wind;

	mPrestige = Prestige::Intermediate;

	SetType(SpiritType::Rainbow);
	PrestigeUp();
}

RainbowSpirit::~RainbowSpirit()
{
}

void RainbowSpirit::SetType(std::uint8_t type)
{
	// Set Rainbow type
	mType = type;
}

std::string RainbowSpirit::GetSpiritName()
{
	return mName;
}

std::string RainbowSpirit::GetSpiritDescription()
{
	return mDescription;
}

std::uint8_t RainbowSpirit::GetSpiritType()
{
	return mType;
}

std::uint8_t RainbowSpirit::GetSpiritPrestige()
{
	return mPrestige;
}

void RainbowSpirit::SpecialSpiritAction(PlayableCharacter& player)
{
	player.SetStrength(player.GetStrength() + 2);
	player.SetInitiave(player.GetInitiative() + 1);
	player.Heal(8);
}

void RainbowSpirit::PrestigeUp()
{
	if (mPrestige != Prestige::Pinnacle) {
		mPrestige << 1;
	}
}

