#include "Page.h"

using namespace std;
using namespace sf;

Page::Page(int page)
{
	switch (page)
	{
	case MAIN:
	{
		buttonsCount = 4;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Выберите опцию");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		photosCount = 0;
		photos = nullptr;
		currentPhoto = nullptr;
		cur = 0;
		break;
	}
	case THEORY:
	{
		buttonsCount = 10;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Выберите раздел");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(SORT, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сортировка");
		buttons[5] = new Button(KAHN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[6] = new Button(TARJAN, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(DIFFICULTY, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложность");
		buttons[8] = new Button(PLUSMINUS, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(USAGE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Применение");

		photosCount = 0;
		photos = nullptr;
		currentPhoto = nullptr;
		cur = 0;
		break;
	}
	case SORT:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Картинки по сортировке");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(NOWHERE, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Сортировка");
		buttons[5] = new Button(KAHN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[6] = new Button(TARJAN, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(DIFFICULTY, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложность");
		buttons[8] = new Button(PLUSMINUS, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(USAGE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Применение");

		buttons[10] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[11] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		photosCount = 1;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\sort.png");

		cur = 0;
		currentPhoto = photos[cur];
		break;
	}
	case KAHN:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Картинки по методу Кана");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(SORT, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сортировка");
		buttons[5] = new Button(NOWHERE, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Метод Кана");
		buttons[6] = new Button(TARJAN, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(DIFFICULTY, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложность");
		buttons[8] = new Button(PLUSMINUS, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(USAGE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Применение");

		buttons[10] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[11] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		photosCount = 5;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\kahn1.png");
		photos[1] = new Photo("Images\\kahn2.png");
		photos[2] = new Photo("Images\\kahn3.png");
		photos[3] = new Photo("Images\\kahn4.png");
		photos[4] = new Photo("Images\\kahn5.png");

		cur = 0;
		currentPhoto = photos[cur];
		break;
	}
	case TARJAN:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Картинки по методу Тарьяна");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(SORT, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сортировка");
		buttons[5] = new Button(KAHN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[6] = new Button(NOWHERE, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(DIFFICULTY, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложность");
		buttons[8] = new Button(PLUSMINUS, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(USAGE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Применение");

		buttons[10] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[11] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		photosCount = 7;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\tarjan1.png");
		photos[1] = new Photo("Images\\tarjan2.png");
		photos[2] = new Photo("Images\\tarjan3.png");
		photos[3] = new Photo("Images\\tarjan4.png");
		photos[4] = new Photo("Images\\tarjan5.png");
		photos[5] = new Photo("Images\\tarjan6.png");
		photos[6] = new Photo("Images\\tarjan7.png");

		cur = 0;
		currentPhoto = photos[cur];
		break;
	}
	case DIFFICULTY:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Картинки по сложности");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(SORT, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сортировка");
		buttons[5] = new Button(KAHN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[6] = new Button(TARJAN, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(NOWHERE, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Сложность");
		buttons[8] = new Button(PLUSMINUS, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(USAGE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Применение");

		buttons[10] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[11] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		photosCount = 2;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\difficulty1.png");
		photos[1] = new Photo("Images\\difficulty2.png");

		cur = 0;
		currentPhoto = photos[cur];
		break;
	}
	case PLUSMINUS:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Картинки по плюсам и минусам");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(SORT, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сортировка");
		buttons[5] = new Button(KAHN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[6] = new Button(TARJAN, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(DIFFICULTY, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложность");
		buttons[8] = new Button(NOWHERE, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(USAGE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Применение");

		buttons[10] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[11] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		photosCount = 3;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\plusminus1.png");
		photos[1] = new Photo("Images\\plusminus2.png");
		photos[2] = new Photo("Images\\plusminus3.png");

		cur = 0;
		currentPhoto = photos[cur];
		break;
	}
	case USAGE:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Картинки по применению");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(SORT, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сортировка");
		buttons[5] = new Button(KAHN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[6] = new Button(TARJAN, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");
		buttons[7] = new Button(DIFFICULTY, Vector2f(955, 205), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложность");
		buttons[8] = new Button(PLUSMINUS, Vector2f(955, 255), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Плюсы и минусы");
		buttons[9] = new Button(NOWHERE, Vector2f(955, 305), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Применение");

		buttons[10] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[11] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		photosCount = 2;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\usage1.png");
		photos[1] = new Photo("Images\\usage2.png");

		cur = 0;
		currentPhoto = photos[cur];
		break;
	}
	}
}

Button** Page::getButtons()
{
	return buttons;
}

int Page::getButtonsCount()
{
	return buttonsCount;
}

Photo** Page::getPhotos()
{
	return photos;
}

Photo* Page::getCurrentPhoto()
{
	return currentPhoto;
}

void Page::prevPhoto()
{
	if (cur > 0)
	{
		currentPhoto = photos[cur - 1];
		cur--;
	}
}

void Page::nextPhoto()
{
	if (cur < photosCount - 1)
	{
		currentPhoto = photos[cur + 1];
		cur++;
	}
}

void Page::draw(sf::RenderWindow& window)
{
	if (buttons)
		for (int i = 0; i < buttonsCount; i++)
		{
			window.draw(buttons[i]->getRect());
			window.draw(buttons[i]->getText());
		}

	if (currentPhoto)
		window.draw(currentPhoto->getSprite());
}