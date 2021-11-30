#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Timing.h"

class Story
{
private:
	std::string mPlayerName;

	int mChapterNumber;
	std::string mCurrentChapterName;
	std::string mChapterString;
	int mSubChapter;
	int mStep;

	int mHeadingSize;

	std::string mStoryFileName;
	std::ifstream mStoryStream;

	int mLittleDelay;
	int mMediumDelay;
	int mHugeDelay;

public:
	Story();
	~Story();

	void SetPlayerName(std::string playerName);
	void SetChapterName(std::string chapterName);
	std::string GetChapterName();

	void DrawHeading();
	void Write();
};

