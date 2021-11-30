#pragma once

#include "PlayableCharacter.h"
#include <string>

class ISpirit {
public:
	virtual std::string GetSpiritName() = 0;
	virtual std::string GetSpiritDescription() = 0;
	virtual std::uint8_t GetSpiritType() = 0;
	virtual std::uint8_t GetSpiritPrestige() = 0;
	virtual void SpecialSpiritAction(PlayableCharacter& player) = 0;
	virtual void PrestigeUp() = 0;
};