#include "class.h"


GameInfo::GameInfo(void)
{
	int x = 0;

	//Initialize time limit to be 0 minutes
	TimeLimit = 0;

	//Fill the available characters with 40 x's
	ListOfChars = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

	//Fill the allowed words array with NOTSET
	for(x = 0; x < MAXWORDS; x++)
	{
		ListOfWords[x] = "";
	}

}



GameInfo::~GameInfo(void)
{
}


string GameInfo::getListOfChars(void)
{
	return ListOfChars;
}



string *GameInfo::getListOfWords(void)
{
	return ListOfWords;
}


int GameInfo::getTimeLimit(void)
{
	return TimeLimit;
}



bool GameInfo::setListOfChars(string newSetOfChars)
{
	ListOfChars = newSetOfChars;

	return true;
}



bool GameInfo::setListOfWords(string *newSetOfWords)
{
	int x = 0;

	for(x = 0; x < MAXWORDS; x++)
	{
		ListOfWords[x] = newSetOfWords[x];

	}
	return true;
}



bool GameInfo::setTimeLimit(int newTimeLimit)
{
	if(newTimeLimit > 0)
	{
		TimeLimit = newTimeLimit;
		return true;
	}
	return false;
}


void GameInfo::printGameInfo(void)
{
	int x = 0;
	printf("[TIMELIMIT]: %d minutes\n", TimeLimit);
	printf("[AVAILABLE CHARACTERS]: %s\n", ListOfChars.c_str());

	for(x = 0; x < MAXWORDS; x++)
	{
		printf("[AVAILABLE WORD]: %s\n", ListOfWords[x].c_str());
	}
}


void GameInfo::printGame(void)
{
	int x = 0;
	char printChars[MAXCHARS] = {0};

	for(x = 0; x < 40; x++)
	{
		printChars[x] = ListOfChars[x];
	}

	printf("  ");

	//print 5 letters, spaced out on one line
	for(x = 0; x < 40; x++)
	{
		if(x % 5 == 0 && x != 0)
		{
			printf("\n  ");
		}
		printf("%c ", printChars[x]);
	}
	//print one extra new line
	printf("\n");
}

