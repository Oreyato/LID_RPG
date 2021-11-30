#pragma once
#include "ISpirit.h"
#include "PrestigeLevel.h"
#include "SpiritType.h"
#include "PlayableCharacter.h"

class WindSpirit :
    public ISpirit
{
	std::string mName;
	std::string mDescription;
	std::uint8_t mType;
	std::uint8_t mPrestige;

public:
	WindSpirit();
	~WindSpirit();

	std::string GetSpiritName();
	std::string GetSpiritDescription();
	std::uint8_t GetSpiritType();
	std::uint8_t GetSpiritPrestige();

	void SpecialSpiritAction(PlayableCharacter& player);
	void PrestigeUp();
};

