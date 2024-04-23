#pragma once
#include "Basics.h"

class Button;

class TestChecker
{
private:
	int* answersEasy;
	int* answersHard;

	int* answersEasyCorrect;
	int answersEasyCount = 10;

	int* answersHardCorrect;
	int answersHardCount = 5;

public:
	TestChecker();
	void setAsnwer(int test, int cur, int ans);
	void calculateResult(int test, Button** buttons);
	void clearResults();
	int* getEasy();
	int* getHard();
};

