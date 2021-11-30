#include "Clash.h"
#include "Utils.h"
#include "Timing.h"

using namespace std;


Clash::Clash()
{
}

Clash::Clash(PlayableCharacter& player, std::vector<Character> enemyGroup)
{

	mPlayer = &player; //	est-ce que ce passage n'écraserait pas le passage par référence ? 

	mEnemyGroup = enemyGroup;
	mInFight = true;
	mDied = false;

	mPlayerName = player.GetName();
	mGroupSize = mEnemyGroup.size();
		
	mNumberOfTurns = 0;
}

Clash::~Clash()
{
	mEnemyGroup.~vector();
}

void Clash::CreatingCharactersVector()
{
	mCharacters.push_back(*mPlayer);

	for (int i = 0; i < mGroupSize; i++) {
		mCharacters.push_back(mEnemyGroup[i]);
	}
}

void Clash::SetEnemiesNames()
{
	string enemyName;

	for (int i = 0; i < mGroupSize; ++i) {
		enemyName = mEnemyGroup[i].GetName();
		mEnemiesNames.push_back(enemyName);
	}
}

std::vector<std::string> Clash::GetEnemiesNames()
{
	return mEnemiesNames;
}

void Clash::DisplayEnemyNames()
{
	cout << endl;

	if (mGroupSize >= 3) {
		for (int i = 0; i < mGroupSize - 2; ++i) {
			cout << mEnemiesNames[i] << ", ";
		}
		cout << mEnemiesNames[mGroupSize - 2] << " and " << mEnemiesNames[mGroupSize-1];
	}
	else if (mGroupSize == 2) {
		cout << mEnemiesNames[0] << " and " << mEnemiesNames[1];
	}
	else {
		cout << mEnemiesNames[0];
	}
}

void Clash::BeginEncounter()
{
	CreatingCharactersVector();
	SetEnemiesNames();
	DisplayEnemyNames();
	cout << " started to fight " << mPlayerName << endl; 

	sleep_for(milliseconds(Timing::mediumDelay));
	cout.flush();

	//	Define order by looking at the initiative
	mOrder = algo::SortingAlgorithmDown(mCharacters);

	Turn();
}

void Clash::DefineOrder()
{
	vector<Character> order = algo::SortingAlgorithmDown(mCharacters);
}

void Clash::ChooseAction()
{
	bool isChoosing = true;

	cout << "\nWhat would " << mPlayerName << " do? (enter a number)" << endl;
	cout << "\t1 - ATTACK" << endl;
	cout << "\t2 - CHANGE WEAPON" << endl;
	cout << "\t3 - USE ITEM" << endl;
	cout << "\t4 - FLEE" << endl;

	while (isChoosing) {

		int decision = -1;
		cin >> decision;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //	\n séparateur ici
			cout << "Please enter a number" << endl;
		}
		else {
			switch (decision)
			{
			case 1:
				isChoosing = false;
				ChooseTarget();
				break;

			case 2:
				isChoosing = false;
				mPlayer->SetEquippedWeapon();
				break;

			case 3:
				isChoosing = false;
				cout << "NO!" << endl;

				break;

			case 4:
				isChoosing = false;
				Flee();
				break;

			default:
				cout << "Please enter a proper number" << endl;
				break;
			}
		}
	}
}

void Clash::ChooseTarget()
{
	cout << "\nWho do you wish to attack?" << endl;

	for (int i = 1; i < mOrder.size(); i++) {
		string enemyName = mOrder[i].GetName();
		int enemyHealth = mOrder[i].GetHealth();

		cout << "\t" << i << " - " << enemyName << " : " << enemyHealth << " HP" << endl;
	}

	bool isChoosing = true;

	while (isChoosing) {
		int enemyIndex = -1;
		cin >> enemyIndex;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //	\n séparateur ici
			cout << "Please enter a number" << endl;
			continue;
		}
		else {

			if (enemyIndex >= 0 && enemyIndex < mOrder.size()) {
				Attack(*mPlayer, mOrder[enemyIndex], enemyIndex);
				isChoosing = false;
			}
			else {
				cout << "Please enter a proper number" << endl;
			}

		}
	}
}

void Clash::Attack(Character attacker, Character& target, int index)
{
	mEquippedWeapon = attacker.GetEquippedWeapon();

	cout << attacker.GetName() << " attacks " << target.GetName() << "!" << endl;

	int randDmg = (rand() % (attacker.GetStrength() + 1));
	int damage = randDmg + mEquippedWeapon.GetAttackDamage();

	target.Hurt(randDmg);

	sleep_for(milliseconds(Timing::littleDelay));
	cout.flush();

	if (index != -1) {
		if (target.GetHealth() <= 0) {
			mOrder.erase(mOrder.begin() + index);
		}
	}
}

void Clash::Flee()
{
	int playerDext = mPlayer->GetDext();
	int chanceToFlee = (rand() % (mGroupSize) + 1) + mGroupSize;
	cout << playerDext << " : " << chanceToFlee << endl;

	if (playerDext >= chanceToFlee) {
		mInFight = false;
		EndEncounter(2);
	}
	else {
		cout << mPlayerName << " failed to escape!" << endl;
		Turn();
	}
}

void Clash::Turn()
{
	do
	{
		mNumberOfTurns += 1;

		cout << "\n========== Turn Number " << mNumberOfTurns << " ==========\n" << endl;

		sleep_for(milliseconds(Timing::littleDelay));
		cout.flush();

		for (int i = mOrder.size() - 1; i >= 0; i--) {
			if (mPlayer->GetHealth() <= 0) {
				mInFight = false;
				EndEncounter(0);
			}
			else if (mOrder[i].GetName() == mPlayer->GetName()) {
				ChooseAction();
			}
			else if (mOrder[i].GetHealth() > 0) {
				Attack(mOrder[i], *mPlayer, i);
			}
		}

		if (mOrder.size() == 1) {
			mInFight = false;
			EndEncounter(1);
		}

	} while (mInFight);
}

void Clash::EndEncounter(int result)
{
	if (result == 0)
	{
		mDied = true;
	}
	else if (result == 1)
	{
		cout << mPlayerName << " successfully won the fight!" << endl;
		mDied = false;
	}
	else if (result == 2) {
		cout << mPlayerName << " successfully escaped the fight!" << endl;
		mDied = false;
	}
}

bool Clash::EncounterResult()
{
	return mDied;
}



