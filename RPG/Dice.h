#pragma once
#include <ctime>
#include <stdlib.h>

class Dice
{
private:
	int mDefaultValue;
	int mDefaultLuckFactor;
	int mDefaultUnluckFactor;

public:
	Dice();
	Dice(int diceValue);
	Dice(int diceValue, int luckFactor, int unluckFactor);
	~Dice();

	Dice operator+ (Dice const& dice);
	Dice operator- (Dice const& dice);

	int GetValue();
	int GetLuckFactor();
	int GetUnluckFactor();

	void SetValue(int value);
	void SetLuckFactor(int value);
	void SetUnluckFactor(int value);

	int NormalDice();
	int NormalDice(int diceValue);
	int LuckyDice();
	int LuckyDice(int diceValue, int luckFactor);
	int UnluckyDice();
	int UnluckyDice(int diceValue, int unluckFactor);
};