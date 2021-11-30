#include "PlayableCharacter.h"
#include "Weapon.h"
#include "Shop.h"
#include "Clash.h"
#include "Story.h"

#include "FireSpirit.h"
#include "WaterSpirit.h"
#include "WindSpirit.h"
#include "RainbowSpirit.h"

using namespace std;

int main() {
	//	Code init ==================================================== 

	//	Changing random seed
	srand(time(0));
	//	Establishing the game loop
	bool isLiving = true;
	//	Launching the story
	Story story;
	story.DrawHeading();

	//	==============================================================

	//	Player Init ==================================================

	PlayableCharacter player("__player__", 50, 50);
	player.CharacterCreation();

	Item littleRock("Little rock", "Small and useless", 1, 15.0, true, true);
	player.AddItem(littleRock);
	Weapon basicSword("Basic sword", "Still better than nothing", WeaponType::Sword, 2, 15, 3500);
	player.AddItem(basicSword);
	Weapon basicKnife("Basic knife", "Still better than nothing", WeaponType::Knife, 1, 15, 500, true, true);
	player.AddItem(basicKnife);

	////	Cheat code: ===================
	//player.SetStrength(12);
	//player.MaxLifeModifier(50);
	//player.Heal(50);
	////	===============================

	story.SetPlayerName(player.GetName());

	//	==============================================================

	do
	{
		//// POSSIBLE TO TEST, JUST REMOVE THE //
		//// Shop template:
		//cout << "\n==================================================\n" << endl;

		//Merchant merchantOne("Juan Pierre", 150, 150);
		//Item goldOre("Gold ore", "It's precious", 25, 12.0, true, true);
		//merchantOne.AddItem(goldOre);
		//Shop shopOne(player, merchantOne);
		//shopOne.ShopLoop();

		//cout << "\n==================================================\n" << endl;

		//	CHAPTER 1 ====================================================

		story.SetChapterName("Road to town");
		story.DrawHeading();
		story.Write();

		player.DisplayInventory();
		sleep_for(milliseconds(Timing::mediumDelay));

		player.SetEquippedWeapon();

		story.Write();
		sleep_for(milliseconds(Timing::mediumDelay));

		//	Ch. 1 - Encounter_01 =============
		Character bandit001("Pierre Jean", 10, 10, 5, 3, 2);
		Character bandit002("Jean Pierre", 10, 10, 5, 3, 5);

		vector<Character> banditGroup001 = { bandit001, bandit002};
		Clash firstEncounter(player, banditGroup001);
		firstEncounter.BeginEncounter();
		if (firstEncounter.EncounterResult()) {
			break;
		}
		//	===============================

		story.Write();

		//	Encounter 2 ===================
		Character bandit011("Pierre Martin", 20, 5, 10, 5, 2);
		Character bandit012("Martin Pierre", 15, 15, 10, 5, 2);

		vector<Character> banditGroup002 = { bandit011, bandit012 };
		Clash secondEncounter(player, banditGroup002);
		secondEncounter.BeginEncounter();
		if (firstEncounter.EncounterResult()) {
			break;
		}
		//	===============================



		//	==============================================================

		//	temp ==========================
		isLiving = false;
		//	===============================

	} while (isLiving);

	cout << "\n ====== YOU FAILED ======";
		

#pragma region Previous Version
	//string name;
	//int age, mana, health;
	////Characteristics
	//map<string,int> characteristics{
	//	{"force", 0},
	//	{"dexterity", 0},
	//	{"constitution", 0},
	//	{"intelligence", 0},
	//	{"wisdom", 0},
	//	{"charisma", 0}
	//};

	//cout << "Player's name: ";
	//cin >> name;
	//cout << "Player's age: ";
	//cin >> age;

	//cout << "Greetings " << name << " nice to meet you!";
	//
	//if (age <= 18) {
	//	cout << " Even if you're only " << age << " years old.";
	//}

	//cout << "\n\nLet's roll !\n";
	////force = rand() % 7; dexterity = rand() % 7; constitution = rand() % 7; intelligence = rand() % 7; wisdom = rand() % 7; charisma = rand() % 7;
	//map<string, int>::iterator itr;
	//for (itr = characteristics.begin(); itr != characteristics.end(); ++itr) {
	//	itr->second = rand() % 10 + 1;
	//}

	//cout << "\nPLAYER CHARACTERISTICS:\n";
	//for (itr = characteristics.begin(); itr != characteristics.end(); ++itr) {
	//	cout << '\t' << itr->first << " - " << itr->second << '\n';
	//}
	//cout << endl;
#pragma endregion Previous Version

}
