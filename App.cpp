#include "App.h"
#include "Kahn.h"
#include "Tarjan.h"
#include <sstream>
#include <cwctype>

using namespace sf;
using namespace std;

App* App::instance = nullptr;

App::App()
{
	check = new TestChecker();

	font = new Font();
	if (!font->loadFromFile("Resources\\oldtimer.ttf"))
		cout << "ERROR: LOADING FONT" << endl;

	pages = new Page * [pagesCount]();
	pages[0] = new Page(MAIN);
	pages[1] = new Page(THEORY);
	pages[2] = new Page(SORT);
	pages[3] = new Page(KAHN);
	pages[4] = new Page(TARJAN);
	pages[5] = new Page(DIFFICULTY);
	pages[6] = new Page(PLUSMINUS);
	pages[7] = new Page(USAGE);
	pages[8] = new Page(CODE);
	pages[9] = new Page(CODEKAHN);
	pages[10] = new Page(RUNKAHN);
	pages[11] = new Page(CODETARJAN);
	pages[12] = new Page(RUNTARJAN);
	pages[13] = new Page(TEST);
	pages[14] = new Page(EASY);
	pages[15] = new Page(HARD);
	pages[16] = new Page(GRADE);
	pages[17] = new Page(FINISH);

	currentPage = getPage(MAIN);
}

App::~App()
{
	delete check;

	delete font;

	if (instance)
		delete instance;

	delete[] pages;
	delete currentPage;
}

App* App::getInstance()
{
	if (!instance)
		instance = new App();

	return instance;
}

void App::Run(sf::RenderWindow& window)
{
	Page* previousPage = currentPage;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
				{
					Vector2f mouseCoords = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
					int count = currentPage->getButtonsCount();
					Button** buttons = currentPage->getButtons();

					for (int i = 0; i < count; i++)
						if (buttons[i]->getRect().getGlobalBounds().contains(mouseCoords))
							if (buttons[i]->getNavigation() != NOWHERE && buttons[i]->getNavigation() != PREV && buttons[i]->getNavigation() != NEXT && buttons[i]->getNavigation() != ADDV
								&& buttons[i]->getNavigation() != ADDADJ && buttons[i]->getNavigation() != REMADJ && buttons[i]->getNavigation() != RUNCODEKAHN && buttons[i]->getNavigation() != RUNCODETARJAN
								&& buttons[i]->getNavigation() != ONE && buttons[i]->getNavigation() != TWO && buttons[i]->getNavigation() != THREE && buttons[i]->getNavigation() != FOUR && buttons[i]->getNavigation() != FINISH)
							{
								previousPage = currentPage;
								currentPage->setCur(0);
								currentPage = getPage(buttons[i]->getNavigation());
							}
							else if (buttons[i]->getNavigation() == PREV)
								currentPage->prevPhoto();
							else if (buttons[i]->getNavigation() == NEXT)
								currentPage->nextPhoto();
							else if (buttons[i]->getNavigation() == ADDV)
								setState(ADDV);
							else if (buttons[i]->getNavigation() == ADDADJ)
								setState(ADDADJ);
							else if (buttons[i]->getNavigation() == REMADJ)
							{
								if (currentPage == getPage(RUNKAHN) && getCurKahn() > 13)
								{
									Button** buttons = currentPage->getButtons();
									buttons[getCurKahn()]->setText(L"нет");
									setCurKahn(getCurKahn() - 1);
								}
								else if (currentPage == getPage(RUNTARJAN) && getCurTarjan() > 13)
								{
									Button** buttons = currentPage->getButtons();
									buttons[getCurTarjan()]->setText(L"нет");
									setCurTarjan(getCurTarjan() - 1);
								}
							}
							else if (buttons[i]->getNavigation() == RUNCODEKAHN)
							{
								if (currentPage == getPage(RUNKAHN))
								{
									Button** buttons = currentPage->getButtons();
									buttons[27]->setText(runKahn());
								}
							}
							else if (buttons[i]->getNavigation() == RUNCODETARJAN)
							{
								if (currentPage == getPage(RUNTARJAN))
								{
									Button** buttons = currentPage->getButtons();
									buttons[27]->setText(runTarjan());
								}
							}
							else if (buttons[i]->getNavigation() == ONE)
							{
								if (currentPage == getPage(EASY))
									check->setAsnwer(EASY, currentPage->getCur(), 1);
								else if (currentPage == getPage(HARD))
									check->setAsnwer(HARD, currentPage->getCur(), 1);
							}
							else if (buttons[i]->getNavigation() == TWO)
							{
								if (currentPage == getPage(EASY))
									check->setAsnwer(EASY, currentPage->getCur(), 2);
								else if (currentPage == getPage(HARD))
									check->setAsnwer(HARD, currentPage->getCur(), 2);
							}
							else if (buttons[i]->getNavigation() == THREE)
							{
								if (currentPage == getPage(EASY))
									check->setAsnwer(EASY, currentPage->getCur(), 3);
								else if (currentPage == getPage(HARD))
									check->setAsnwer(HARD, currentPage->getCur(), 3);
							}
							else if (buttons[i]->getNavigation() == FOUR)
							{
								if (currentPage == getPage(EASY))
									check->setAsnwer(EASY, currentPage->getCur(), 4);
								else if (currentPage == getPage(HARD))
									check->setAsnwer(HARD, currentPage->getCur(), 4);
							}
							else if (buttons[i]->getNavigation() == FINISH)
							{
								previousPage = currentPage;
								previousPage->setCur(0);
								currentPage = getPage(buttons[i]->getNavigation());
								Button** buttons = currentPage->getButtons();

								if (previousPage == getPage(EASY))
									check->calculateResult(EASY, buttons);
								else if (previousPage == getPage(HARD))
									check->calculateResult(HARD, buttons);
							}
				}
				break;
			case Event::KeyPressed:
				if (currentPage == getPage(RUNKAHN) || currentPage == getPage(RUNTARJAN))
				{
					if (event.key.code >= Keyboard::Num0 && event.key.code <= Keyboard::Num9 || event.key.code == Keyboard::Space)
					{
						if (event.key.code != Keyboard::Space)
						{
							int digit = event.key.code - Keyboard::Num0;
							setInput(getInput().append(to_wstring(digit)));
						}
						else
							setInput(getInput().append(L" "));
					}
					else if (event.key.code == Keyboard::Enter)
					{
						if (getState() == ADDV)
						{
							Button** buttons = currentPage->getButtons();
							buttons[12]->setText(input);
						}
						else if (getState() == ADDADJ)
						{
							if (currentPage == getPage(RUNKAHN) && getCurKahn() < currentPage->getButtonsCount() - 3)
							{
								Button** buttons = currentPage->getButtons();
								setCurKahn(getCurKahn() + 1);
								buttons[getCurKahn()]->setText(input);
							}
							else if (currentPage == getPage(RUNTARJAN) && getCurTarjan() < currentPage->getButtonsCount() - 3)
							{
								Button** buttons = currentPage->getButtons();
								setCurTarjan(getCurTarjan() + 1);
								buttons[getCurTarjan()]->setText(input);
							}
						}

						setInput(L"");
						setState(-1);
					}
				}
				break;
			}
		}

		window.clear(usual);

		currentPage->draw(window);

		if (currentPage == getPage(EASY))
			currentPage->changeColour(check->getEasy()[currentPage->getCur()]);
		else if (currentPage == getPage(HARD))
			currentPage->changeColour(check->getHard()[currentPage->getCur()]);

		if (previousPage == getPage(FINISH))
		{
			previousPage->clearPage();
			check->clearResults();
		}

		window.display();
	}
}

Page* App::getPage(int page)
{
	return pages[page];
}

std::wstring App::getInput()
{
	return input;
}

void App::setInput(std::wstring input_)
{
	input = input_;
}

int App::getState()
{
	return state;
}

void App::setState(int state_)
{
	state = state_;
}

int App::getCurKahn()
{
	return curKahn;
}

void App::setCurKahn(int cur_)
{
	curKahn = cur_;
}

int App::getCurTarjan()
{
	return curTarjan;
}

void App::setCurTarjan(int cur_)
{
	curTarjan = cur_;
}

wstring App::runKahn()
{
	wstring result;

	Button** buttons = currentPage->getButtons();
	GraphK g(stoi(buttons[12]->getText().getString().toWideString()));
	cout << stoi(buttons[12]->getText().getString().toWideString()) << endl;

	for (int i = 14; i < 25; i++)
	{
		if (isNumber(buttons[i]->getText().getString().toWideString()))
		{
			wstringstream ss(buttons[i]->getText().getString().toWideString());

			int num1, num2;
			ss >> num1 >> num2;

			cout << "One: " << num1 << endl;
			cout << "Two: " << num2 << endl;

			try
			{
				g.addEdge(num1, num2);
			}
			catch (exception& e)
			{
				return L"¬ведены неверные данные!";
			}
		}
	}

	result = g.topologicalSort();

	return result;
}

wstring App::runTarjan()
{
	wstring result;

	Button** buttons = currentPage->getButtons();
	GraphT g(stoi(buttons[12]->getText().getString().toWideString()));

	for (int i = 14; i < 25; i++)
	{
		if (isNumber(buttons[i]->getText().getString().toWideString()))
		{
			wstringstream ss(buttons[i]->getText().getString().toWideString());

			int num1, num2;
			ss >> num1 >> num2;

			try
			{
				g.addEdge(num1, num2);
			}
			catch (exception& e)
			{
				return L"¬ведены неверные данные!";
			}
		}
	}

	result = g.topologicalSort();

	return result;
}

bool App::isNumber(const std::wstring& str)
{
	for (wchar_t ch : str)
		if (!std::iswdigit(ch) && ch != L' ')
			return false;

	return true;
}