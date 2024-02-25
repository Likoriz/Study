#include "App.h"

using namespace sf;
using namespace std;

App* App::instance = nullptr;

App::App()
{
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
	pages[10] = new Page(CODETARJAN);
	pages[11] = new Page(TEST);
	pages[12] = new Page(GRADE);
	pages[13] = new Page(FINISH);

	currentPage = getPage(MAIN);
}

App::~App()
{
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
							if (buttons[i]->getNavigation() != NOWHERE && buttons[i]->getNavigation() != PREV && buttons[i]->getNavigation() != NEXT)
								currentPage = getPage(buttons[i]->getNavigation());
							else if (buttons[i]->getNavigation() == PREV)
								currentPage->prevPhoto();
							else if (buttons[i]->getNavigation() == NEXT)
								currentPage->nextPhoto();
				}
				break;
			}
		}

		window.clear(usual);

		currentPage->draw(window);

		window.display();
	}
}

Page* App::getPage(int page)
{
	return pages[page];
}