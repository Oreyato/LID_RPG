#pragma once
#include "PlayableCharacter.h"
#include <map>

class Clash
{
private:
	bool mInFight;
	bool mDied;

	PlayableCharacter *mPlayer;
	Weapon mEquippedWeapon;

	std::vector<Character> mEnemyGroup;
	std::vector<Character> mCharacters;
	int mGroupSize;
	std::vector<Character> mOrder;

	std::string mPlayerName;
	std::vector<std::string> mEnemiesNames;

	int mNumberOfTurns;
 
public:
	Clash();
	Clash(PlayableCharacter& player, std::vector<Character> enemyGroup);
	~Clash();

	void CreatingCharactersVector();

	void SetEnemiesNames();

	std::vector<std::string> GetEnemiesNames();

	void DisplayEnemyNames();

	void BeginEncounter();
	void DefineOrder();
	void ChooseAction();
	void ChooseTarget();
	void Attack(Character attacker, Character& target, int index = -1);
	void Flee();
	void Turn();
	void EndEncounter(int result);
	bool EncounterResult();
};

