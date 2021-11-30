#pragma once
#include "Character.h"
class PlayableCharacter :
    public Character
{
private:
	int mForce;
	int mDexterity;
	int mConstitution;
	int mIntelligence;
	int mWisdom;
	int mCharisma;

	Weapon mEquippedWeapon;

	bool mIsDead = false;

public:
	PlayableCharacter();

	PlayableCharacter(std::string name, int health, int maxHealth, int initiative = 1, int mana = 0, int maxMana = 0, int f = 3, int d = 3, int c = 3, int i = 3, int w = 3, int ch = 3, int money = 0);

	~PlayableCharacter();

	void CharacterCreation();

	int GetForce();
	int GetDext();
	int GetConst();
	int GetInt();
	int GetWisdom();
	int GetChar();

	void SetForce(int value);
	void SetDext(int value);
	void SetConst(int value);
	void SetInt(int value);
	void SetWisdom(int value);
	void SetChar(int value);
	void SetAllCharacteristics(int dieValue);
	void SetEquippedWeapon();

	void Hurt(int points);
	void DisplaySumUp();
	
};

