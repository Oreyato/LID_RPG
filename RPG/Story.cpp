#include "Story.h"

using namespace std;


Story::Story()
{
	mChapterNumber = 0;
	mCurrentChapterName = "Character creation";
	mChapterString = "Chapter ";
	mSubChapter = 1;
	mStep = 1;

	mHeadingSize = 70;

	mStoryFileName = "../Story.txt";

	mLittleDelay = Timing::littleDelay;
	mMediumDelay = Timing::mediumDelay;
	mHugeDelay = Timing::hugeDelay;
}

Story::~Story()

{
	mStoryStream.close();
}

void Story::SetPlayerName(std::string playerName)
{
	mPlayerName = playerName;
}

void Story::SetChapterName(string chapterName)
{
	mCurrentChapterName = chapterName;
}

std::string Story::GetChapterName()
{
	return mCurrentChapterName;
}

void Story::DrawHeading()
{
	cout << endl;
	//	There might be a mathematical way to do it...
	int unitNumber = 0;
	if (mChapterNumber < 10) {
		unitNumber = 1;
	}
	else if (mChapterNumber < 100) {
		unitNumber = 2;
	}
	else {
		unitNumber = 3;
	}

	//	Getting sizes
	int chaptersNameSize = mCurrentChapterName.length();
	int chapterStringSize = mChapterString.length();

	//	Determining how much space is left to write around texts
	int spaceName = (mHeadingSize - chaptersNameSize) / 2;
	int spaceChapterNumber = (mHeadingSize - chapterStringSize - unitNumber) / 2;

	//	Actual writing ===============================================
	//	Top
	for (size_t i = 0; i < mHeadingSize; i++)
	{
		cout << "=";
	}
	cout << endl;

	//	Middle Top
	for (int i = 0; i < spaceChapterNumber - 1; i++)
	{
		cout << " ";
	}
	cout << " " << mChapterString << mChapterNumber << " ";
	for (int i = 0; i < spaceChapterNumber - 1; i++)
	{
		cout << " ";
	}
	cout << endl;

	//	Middle Bottom
	for (int i = 0; i < spaceName -1; i++)
	{
		cout << " ";
	}
	cout << " " << mCurrentChapterName << " ";
	for (int i = 0; i < spaceName -1; i++)
	{
		cout << " ";
	}
	cout << endl;

	//	Bottom
	for (size_t i = 0; i < mHeadingSize; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << endl;
	//	==============================================================

	mChapterNumber += 1;
	sleep_for(milliseconds(mMediumDelay));
	cout.flush();
}

void Story::Write()
{
	mStoryStream.open(mStoryFileName.c_str());

	string line;
	string strStep = "#";
	strStep.append(to_string(mStep));
	size_t pos;

	if (mStoryStream.is_open()) {

		//	using getline + specific symbol ==============================

		//getline(mStoryStream, line, '#');

		//while (getline(mStoryStream, line, '#')) {
		//	cout << line << endl;
		//	getline(mStoryStream, line, '#');
		//}

		//	==============================================================
		
		//	using find ===================================================
		while (getline(mStoryStream, line))
		{
			//	using "#[mStep]" to know what to write
			pos = line.find(strStep);

			if (pos != string::npos) {
				while (getline(mStoryStream, line)) {

					if (line == strStep) {
						break;
					}
					else {
						sleep_for(milliseconds(mLittleDelay));
						cout << "> " << line << endl;
						cout.flush();
					}

				}
			}
		}
		//	==============================================================

		mStoryStream.close();
		mStep += 1;
		sleep_for(milliseconds(mLittleDelay));
	}
	else {
		cout << "ERROR: Cannot open file (supposely located here: " << mStoryFileName << " -relative path-)" << endl;
	}
}
