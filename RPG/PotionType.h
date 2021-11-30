#pragma once

namespace PotionType
{
	enum Type {
		Heal = 1 << 0,
		Mana = 1 << 1,

		Strength = 1 << 2,
		Initiative = 1 << 3,

		Dexterity = 1 << 4
	};
}