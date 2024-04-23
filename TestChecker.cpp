#include "TestChecker.h"
#include "Button.h"

using namespace std;

TestChecker::TestChecker()
{
	answersEasyCount = 10;
	answersEasyCorrect = new int[answersEasyCount];
	answersEasyCorrect[0] = 3;
	answersEasyCorrect[1] = 1;
	answersEasyCorrect[2] = 1;
	answersEasyCorrect[3] = 1;
	answersEasyCorrect[4] = 2;
	answersEasyCorrect[5] = 1;
	answersEasyCorrect[6] = 2;
	answersEasyCorrect[7] = 1;
	answersEasyCorrect[8] = 1;
	answersEasyCorrect[9] = 4;

	answersHardCount = 5;
	answersHardCorrect = new int[answersHardCount];
	answersHardCorrect[0] = 1;
	answersHardCorrect[1] = 3;
	answersHardCorrect[2] = 4;
	answersHardCorrect[3] = 1;
	answersHardCorrect[4] = 2;

	answersEasy = new int[answersEasyCount];
	for (int i = 0; i < answersEasyCount; i++)
		answersEasy[i] = 0;

	answersHard = new int[answersHardCount];
	for (int i = 0; i < answersHardCount; i++)
		answersHard[i] = 0;
}

void TestChecker::setAsnwer(int test, int cur, int ans)
{
	switch (test)
	{
	case EASY:
	{
		answersEasy[cur] = ans;
		break;
	}
	case HARD:
	{
		answersHard[cur] = ans;
		break;
	}
	}
}

void TestChecker::calculateResult(int test, Button** buttons)
{
	/*
		buttons[5] = new Button(NOWHERE, Vector2f(50, 110), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");result
		buttons[6] = new Button(NOWHERE, Vector2f(50, 165), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[7] = new Button(NOWHERE, Vector2f(50, 220), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[8] = new Button(NOWHERE, Vector2f(50, 275), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[9] = new Button(NOWHERE, Vector2f(50, 330), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[10] = new Button(NOWHERE, Vector2f(50, 385), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[11] = new Button(NOWHERE, Vector2f(50, 440), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[12] = new Button(NOWHERE, Vector2f(50, 495), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[13] = new Button(NOWHERE, Vector2f(50, 550), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[14] = new Button(NOWHERE, Vector2f(50, 605), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		buttons[15] = new Button(NOWHERE, Vector2f(50, 660), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
		17
	*/

	int points = 0;
	int grade = 0;
	int* result = nullptr;

	if (test == EASY)
	{
		result = new int[10];

		for (int i = 0; i < 10; i++)
			if (answersEasy[i] == answersEasyCorrect[i])
			{
				result[i] = 1;
				points++;
			}
			else
				result[i] = 0;

		buttons[5]->setText(to_wstring(points) + L"/" + to_wstring(answersEasyCount));

		buttons[11]->setText(L"Вопрос 6: " + to_wstring(result[5]) + L" балл (ов)");
		buttons[12]->setText(L"Вопрос 7: " + to_wstring(result[6]) + L" балл (ов)");
		buttons[13]->setText(L"Вопрос 8: " + to_wstring(result[7]) + L" балл (ов)");
		buttons[14]->setText(L"Вопрос 9: " + to_wstring(result[8]) + L" балл (ов)");
		buttons[15]->setText(L"Вопрос 10: " + to_wstring(result[9]) + L" балл (ов)");

		if (points > 8)
			grade = 5;
		else if (points > 6)
			grade = 4;
		else if (points > 3)
			grade = 3;
		else
			grade = 2;
	}
	else if (test == HARD)
	{
		result = new int[5];

		for (int i = 0; i < 5; i++)
			if (answersHard[i] == answersHardCorrect[i])
			{
				result[i] = 1;
				points++;
			}
			else
				result[i] = 0;

		buttons[5]->setText(to_wstring(points) + L"/" + to_wstring(answersHardCount));

		if (points > 3)
			grade = points;
		else
			grade = 2;
	}

	buttons[6]->setText(L"Вопрос 1: " + to_wstring(result[0]) + L" балл (ов)");
	buttons[7]->setText(L"Вопрос 2: " + to_wstring(result[1]) + L" балл (ов)");
	buttons[8]->setText(L"Вопрос 3: " + to_wstring(result[2]) + L" балл (ов)");
	buttons[9]->setText(L"Вопрос 4: " + to_wstring(result[3]) + L" балл (ов)");
	buttons[10]->setText(L"Вопрос 5: " + to_wstring(result[4]) + L" балл (ов)");

	buttons[17]->setText(to_wstring(grade));
}

void TestChecker::clearResults()
{
	for (int i = 0; i < answersEasyCount; i++)
		answersEasy[i] = 0;

	for (int i = 0; i < answersHardCount; i++)
		answersHard[i] = 0;
}

int* TestChecker::getEasy()
{
	return answersEasy;
}

int* TestChecker::getHard()
{
	return answersHard;
}