#include "Shop.h"
using namespace std;

Shop::Shop() {}

Shop::Shop(PlayableCharacter& character, Merchant& merchant) {
	mIsInShop = true;
	mCharacter = character;
	mMerchant = merchant;
}
Shop::~Shop() {}

void Shop::ShopLoop()
{
	cout << "\nWelcome to my humble shop, traveler..." << endl;
	cout << "Let me know if you need anything..." << endl;

	cout << "\n===== " << mMerchant.GetName() << "'s shop =====" << endl;
	cout << "Do you want to BUY anything?" << endl;
	cout << "Or do you want to SELL some items?" << endl;
	cout << "Write ESC to leave" << endl;

	while (mIsInShop) {
		Inputs();
	}
}

void Shop::Inputs() {
	cout << "\nBUY - SELL - ESC" << endl;
	string input;
	cin >> input;

	if (input == "ESC") {
		mIsInShop = false;
		cout << mCharacter.GetName() << " currently have " << mCharacter.GetMoney() << " coins" << endl;
	}
	else if (input == "BUY") {
		ShopDisplay(0);
	}
	else if (input == "SELL") {
		ShopDisplay(1);
	}
	else {
		cout << "Please enter a proper word (BUY / SELL / ESC)" << endl;
	}
}

void Shop::ShopDisplay(int menu) {
		cout << "\n===== " << mMerchant.GetName() << "'s shop =====" << endl;
		mCharacter.DisplayMoney();

		string itemName;

		// BUY LOOP
		if (menu == 0) {
			int inventorySize = mMerchant.GetInventory().size();

			if (inventorySize == 0) {
				cout << mMerchant.GetName() << " don't have anything to sell..." << endl;
			}
			else {
				cout << "What do you wish to buy?" << endl;
				mMerchant.DisplayShop();
				cout << "\t\tShop selling at: x" << mMerchant.GetShopSellMult() << endl;

				cout << "\nEnter item's index" << endl;

				bool isChoosing = true;

				while (isChoosing) {
					//	SELECTING BY NUMBER
					int itemIndex = -1;
					cin >> itemIndex;
					if (!cin) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //	\n séparateur ici
						cout << "Please enter a number" << endl;
						continue;
					}  
					else {
						Item i = Item();
						if (mMerchant.GetItemByIndex(itemIndex, i)) {
							mMerchant.SellItem(mCharacter, i);
							isChoosing = false;
						}
						else {
							cout << "Please enter a proper number" << endl;
						}

						//	SELECTING BY NAME

						//cin.ignore();
						//string itemName;
						//getline(cin, itemName);
						//Item i = Item();
						//if (mMerchant.GetItemByName(itemName, i)) {
						//	mMerchant.SellItem(mCharacter, i);
						//}
						//else {
						//	cout << "";
						//}
					}
				}
			}
		}
		// SELL LOOP
		else {
			int inventorySize = mCharacter.GetInventory().size();

			if (inventorySize == 0)
			{
				cout << "You don't have anything to sell" << endl;
			}
			else {
				cout << "What do you wish to sell?" << endl;
				mCharacter.DisplayShopOrientedInventory();
				cout << "\t\tShop buying at: x" << mMerchant.GetShopBuyMult() << endl;

				cout << "\nEnter item's index" << endl;

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
						Item i = Item();
						if (mCharacter.GetItemByIndex(itemIndex, i)) {
							mMerchant.BuyItem(mCharacter, i);
							isChoosing = false;
						}
						else {
							cout << "Please enter a proper number" << endl;
						}

						//	SELECTING BY NAME

						//cin.ignore();
						//string itemName;
						//getline(cin, itemName);
						//Item i = Item();
						//if (mCharacter.GetItemByName(itemName, i)) {
						//	mMerchant.BuyItem(mCharacter, i);
						//}
						//else {
						//	cout << "";
						//}
					}

				}
			}
		}	
}
