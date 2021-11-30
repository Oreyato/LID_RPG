#include "PlayableCharacter.h"
#include "Dice.h"
#include "Timing.h"

using namespace std;

PlayableCharacter::PlayableCharacter()
{
}

PlayableCharacter::PlayableCharacter(std::string name, int health, int maxHealth, int initiative, int mana, int maxMana, int f, int d, int c, int i, int w, int ch, int money)
{
	mName = name;
	mHealth = health;
	mMaxHealth = maxHealth;
	mMana = mana;
	mMaxMana = maxMana;
	
	mInitiative = initiative;

	mForce = f;
	mDexterity = d;
	mConstitution = c;
	mIntelligence = i;
	mWisdom = w;
	mCharisma = ch;

	mMoney = money;
}


PlayableCharacter::~PlayableCharacter()
{
	mItems.~vector();
}

void PlayableCharacter::CharacterCreation()
{
	cout << "[???] I[we] welcome you strange being[creature]" << endl;
	sleep_for(milliseconds(Timing::littleDelay));
	cout.flush();
	cout << "[???] You decided[were forc-] to be reincarnated as a hero[vagrant]" << endl;
	sleep_for(milliseconds(Timing::littleDelay));
	cout.flush();
	cout << "[???] What is your name[spirit description]?" << endl;

	getline(cin, mName);

	cout << "[???] " << mName << "...? Interesting[Odd]" << endl;
	sleep_for(milliseconds(Timing::littleDelay));
	cout.flush();
	cout << "[???] Shall the gods[we] bless[curse] you" << endl;
	sleep_for(milliseconds(Timing::mediumDelay));
	cout.flush();

	SetAllCharacteristics(12);
	DisplaySumUp();

	sleep_for(milliseconds(Timing::mediumDelay));
	cout.flush();

	cout << "[???] I[we] wish you good luck hero[lost soul]" << endl;
	sleep_for(milliseconds(Timing::littleDelay));
	cout.flush();
	cout << "\n> ~There is nothing but light~" << endl;
	sleep_for(milliseconds(Timing::littleDelay));
	cout.flush();
}


int PlayableCharacter::GetForce()
{
	return mForce;
}

int PlayableCharacter::GetDext()
{
	return mDexterity;
}

int PlayableCharacter::GetConst()
{
	return mConstitution;
}

int PlayableCharacter::GetInt()
{
	return mIntelligence;
}

int PlayableCharacter::GetWisdom()
{
	return mWisdom;
}

int PlayableCharacter::GetChar()
{
	return mCharisma;
}


void PlayableCharacter::SetForce(int value)
{
	mForce = value;
	mStrength = mForce;
}

void PlayableCharacter::SetDext(int value)
{
	mDexterity = value;
}

void PlayableCharacter::SetConst(int value)
{
	mConstitution = value;
}

void PlayableCharacter::SetInt(int value)
{
	mIntelligence = value;
}

void PlayableCharacter::SetWisdom(int value)
{
	mWisdom = value;
}

void PlayableCharacter::SetChar(int value)
{
	mCharisma = value;
}

void PlayableCharacter::SetAllCharacteristics(int diceValue)
{
	Dice dice(diceValue);
	Dice luckyDice(0, 2, 0);
	Dice combinedDice = dice + luckyDice;

	SetForce(combinedDice.LuckyDice());
	SetDext(combinedDice.LuckyDice());
	SetConst(combinedDice.LuckyDice());
	SetInt(combinedDice.LuckyDice());
	SetWisdom(combinedDice.LuckyDice());
	SetChar(combinedDice.LuckyDice());
}

void PlayableCharacter::SetEquippedWeapon()
{
	DisplayWeapon();

	bool isChoosing = true;
	int itemIndex;

	while (isChoosing) {
		//	SELECTING BY NUMBER
		itemIndex = 0;
		cin >> itemIndex;

		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a number" << endl;
			continue;
		}
		else {
			Weapon i = Weapon();
			if (GetItemByIndex(itemIndex, i)) {
				mEquippedWeapon = i;

				cout << mName << " equipped \"" << i.GetName() << "\"" << endl; 

				isChoosing = false;
			}
			else {
				cout << "Please enter a proper number" << endl;
			}
		}
	}
}

void PlayableCharacter::Hurt(int points)
{
	mHealth = max((mHealth - points), 0);
	if (mHealth == 0) {
		cout << mName << " died!\n";
	}
	else DisplayHealth();
}

void PlayableCharacter::DisplaySumUp()
{
	cout << "\n" << mName << "'s characteristics:\n";
	cout << "\t Force: " << mForce << endl;
	cout << "\t Dexterity: " << mDexterity << endl;
	cout << "\t Constitution: " << mConstitution << endl;
	cout << "\t Intelligence: " << mIntelligence << endl;
	cout << "\t Wisdom: " << mWisdom << endl;
	cout << "\t Charisma: " << mCharisma << endl;
	cout << endl;
}

