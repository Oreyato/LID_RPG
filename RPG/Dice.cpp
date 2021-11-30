#include "Dice.h"

Dice Dice::operator+(Dice const& dice)
{
	Dice newDice;
	newDice.mDefaultValue = mDefaultValue + dice.mDefaultValue;
	newDice.mDefaultLuckFactor = mDefaultLuckFactor + dice.mDefaultLuckFactor;
	newDice.mDefaultUnluckFactor = mDefaultUnluckFactor + dice.mDefaultUnluckFactor;

	return newDice;
}
Dice Dice::operator-(Dice const& dice)
{
	Dice newDice;
	newDice.mDefaultValue = mDefaultValue - dice.mDefaultValue;
	newDice.mDefaultLuckFactor = mDefaultLuckFactor - dice.mDefaultLuckFactor;
	newDice.mDefaultUnluckFactor = mDefaultUnluckFactor - dice.mDefaultUnluckFactor;

	return newDice;
}



Dice::Dice()
{
	mDefaultValue = 6;
	mDefaultLuckFactor = 2;
	mDefaultUnluckFactor = -2;
}
Dice::Dice(int diceValue)
{
	mDefaultValue = diceValue;
	mDefaultLuckFactor = 2;
	mDefaultUnluckFactor = -2;
}
Dice::Dice(int diceValue, int luckFactor, int unluckFactor) {
	mDefaultValue = diceValue;
	mDefaultLuckFactor = luckFactor;
	mDefaultUnluckFactor = unluckFactor;
}
Dice::~Dice()
{
}



int Dice::GetValue()
{
	return mDefaultValue;
}

int Dice::GetLuckFactor()
{
	return mDefaultLuckFactor;
}
int Dice::GetUnluckFactor()
{
	return mDefaultUnluckFactor;
}



void Dice::SetValue(int value)
{
	mDefaultValue = value;
}
void Dice::SetLuckFactor(int value) {
	mDefaultLuckFactor = value;
}
void Dice::SetUnluckFactor(int value) {
	mDefaultUnluckFactor = value;
}



int Dice::NormalDice()
{
	int value = rand() % mDefaultValue + 1;

	return value;
}

int Dice::NormalDice(int diceValue) {
	int value = rand() % diceValue + 1;

	return value;
}

int Dice::LuckyDice()
{
	int value = rand() % mDefaultValue + 1;
	value += rand() % mDefaultLuckFactor + 1;
	if (value > mDefaultValue) value = mDefaultValue;

	return value;
}

int Dice::LuckyDice(int diceValue, int luckFactor) {
	int value = rand() % diceValue + 1;
	value += rand() % luckFactor + 1;
	if (value > diceValue) value = diceValue;

	return value;
}

int Dice::UnluckyDice()
{
	int value = rand() % mDefaultValue + 1;
	value -= rand() % mDefaultUnluckFactor + 1;
	if (value < 1) value = 1;

	return value;
}

int Dice::UnluckyDice(int diceValue, int unluckFactor) {
	int value = rand() % diceValue + 1;
	value -= rand() % unluckFactor + 1;
	if (value < 1) value = 1;

	return value;
}

