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

		currentPhoto = photos[cur];
		break;
	}
	case CODE:
	{
		buttonsCount = 6;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Выберите метод");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(CODEKAHN, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[5] = new Button(CODETARJAN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");

		break;
	}
	case CODEKAHN:
	{
		buttonsCount = 9;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(NOWHERE, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Метод Кана");
		buttons[5] = new Button(CODETARJAN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");

		buttons[6] = new Button(PREV, Vector2f(955, 210), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Объявление");
		buttons[7] = new Button(NEXT, Vector2f(955, 265), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Определение");

		buttons[8] = new Button(RUNKAHN, Vector2f(955, 375), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Данные");

		photosCount = 2;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\codekahn1.png");
		photos[1] = new Photo("Images\\codekahn2.png");

		currentPhoto = photos[cur];
		break;
	}
	case RUNKAHN:
	{
		buttonsCount = 28;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(CODEKAHN, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Метод Кана");
		buttons[5] = new Button(CODETARJAN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Тарьяна");

		buttons[6] = new Button(NOWHERE, Vector2f(955, 375), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Данные");

		buttons[7] = new Button(ADDV, Vector2f(955, 485), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Вершины");
		buttons[8] = new Button(ADDADJ, Vector2f(955, 540), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Добавить ребро");
		buttons[9] = new Button(REMADJ, Vector2f(955, 595), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Удалить ребро");
		buttons[10] = new Button(RUNCODEKAHN, Vector2f(955, 705), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Запуск");

		buttons[11] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Количество вершин:");
		buttons[12] = new Button(NOWHERE, Vector2f(50, 110), Vector2f(900, 50), font, 32, 5, Color::Transparent, Color::Transparent, L"0");
		buttons[13] = new Button(NOWHERE, Vector2f(50, 165), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Ребра:");
		buttons[14] = new Button(NOWHERE, Vector2f(50, 220), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[15] = new Button(NOWHERE, Vector2f(50, 275), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[16] = new Button(NOWHERE, Vector2f(50, 330), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[17] = new Button(NOWHERE, Vector2f(50, 385), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[18] = new Button(NOWHERE, Vector2f(50, 440), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[19] = new Button(NOWHERE, Vector2f(50, 495), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[20] = new Button(NOWHERE, Vector2f(50, 550), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[21] = new Button(NOWHERE, Vector2f(50, 605), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[22] = new Button(NOWHERE, Vector2f(50, 660), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[23] = new Button(NOWHERE, Vector2f(50, 715), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[24] = new Button(NOWHERE, Vector2f(50, 770), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[25] = new Button(NOWHERE, Vector2f(50, 825), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[26] = new Button(NOWHERE, Vector2f(50, 880), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Результат:");
		buttons[27] = new Button(NOWHERE, Vector2f(50, 935), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");

		break;
	}
	case CODETARJAN:
	{
		buttonsCount = 9;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(CODEKAHN, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[5] = new Button(NOWHERE, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Метод Тарьяна");

		buttons[6] = new Button(PREV, Vector2f(955, 210), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Объявление");
		buttons[7] = new Button(NEXT, Vector2f(955, 265), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Определение");

		buttons[8] = new Button(RUNTARJAN, Vector2f(955, 375), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Данные");

		photosCount = 2;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\codetarjan1.png");
		photos[1] = new Photo("Images\\codetarjan2.png");

		currentPhoto = photos[cur];
		break;
	}
	case RUNTARJAN:
	{
		buttonsCount = 28;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Тест");

		buttons[4] = new Button(CODEKAHN, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Метод Кана");
		buttons[5] = new Button(CODETARJAN, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Метод Тарьяна");

		buttons[6] = new Button(NOWHERE, Vector2f(955, 375), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Данные");

		buttons[7] = new Button(ADDV, Vector2f(955, 485), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Вершины");
		buttons[8] = new Button(ADDADJ, Vector2f(955, 540), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Добавить ребро");
		buttons[9] = new Button(REMADJ, Vector2f(955, 595), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Удалить ребро");
		buttons[10] = new Button(RUNCODETARJAN, Vector2f(955, 705), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Запуск");

		buttons[11] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Количество вершин");
		buttons[12] = new Button(NOWHERE, Vector2f(50, 110), Vector2f(900, 50), font, 32, 5, Color::Transparent, Color::Transparent, L"0");
		buttons[13] = new Button(NOWHERE, Vector2f(50, 165), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Ребра:");
		buttons[14] = new Button(NOWHERE, Vector2f(50, 220), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[15] = new Button(NOWHERE, Vector2f(50, 275), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[16] = new Button(NOWHERE, Vector2f(50, 330), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[17] = new Button(NOWHERE, Vector2f(50, 385), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[18] = new Button(NOWHERE, Vector2f(50, 440), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[19] = new Button(NOWHERE, Vector2f(50, 495), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[20] = new Button(NOWHERE, Vector2f(50, 550), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[21] = new Button(NOWHERE, Vector2f(50, 605), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[22] = new Button(NOWHERE, Vector2f(50, 660), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[23] = new Button(NOWHERE, Vector2f(50, 715), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[24] = new Button(NOWHERE, Vector2f(50, 770), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[25] = new Button(NOWHERE, Vector2f(50, 825), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");
		buttons[26] = new Button(NOWHERE, Vector2f(50, 880), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Результат");
		buttons[27] = new Button(NOWHERE, Vector2f(50, 935), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"нет");

		break;
	}
	case TEST:
	{
		buttonsCount = 7;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Выберите уровень сложности");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Тест");

		buttons[4] = new Button(GRADE, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Оценивание");
		buttons[5] = new Button(EASY, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Легкий");
		buttons[6] = new Button(HARD, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложный");

		break;
	}
	case EASY:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Легкий тест");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(NOWHERE, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Тест");

		buttons[4] = new Button(FINISH, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Завершить");
		buttons[5] = new Button(NOWHERE, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Легкий");

		buttons[6] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[7] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		buttons[8] = new Button(ONE, Vector2f(1045, 475), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"1");
		buttons[9] = new Button(TWO, Vector2f(1110, 475), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"2");
		buttons[10] = new Button(THREE, Vector2f(1045, 540), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"3");
		buttons[11] = new Button(FOUR, Vector2f(1110, 540), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"4");

		photosCount = 10;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\easy1.png");
		photos[1] = new Photo("Images\\easy2.png");
		photos[2] = new Photo("Images\\easy3.png");
		photos[3] = new Photo("Images\\easy4.png");
		photos[4] = new Photo("Images\\easy5.png");
		photos[5] = new Photo("Images\\easy6.png");
		photos[6] = new Photo("Images\\easy7.png");
		photos[7] = new Photo("Images\\easy8.png");
		photos[8] = new Photo("Images\\easy9.png");
		photos[9] = new Photo("Images\\easy10.png");

		currentPhoto = photos[cur];

		break;
	}
	case HARD:
	{
		buttonsCount = 12;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L"Сложность тест");
		buttons[1] = new Button(NOWHERE, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(NOWHERE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(NOWHERE, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Тест");

		buttons[4] = new Button(FINISH, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Завершить");
		buttons[5] = new Button(NOWHERE, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Сложный");

		buttons[6] = new Button(PREV, Vector2f(1045, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"<-");
		buttons[7] = new Button(NEXT, Vector2f(1110, 410), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"->");

		buttons[8] = new Button(ONE, Vector2f(1045, 475), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"1");
		buttons[9] = new Button(TWO, Vector2f(1110, 475), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"2");
		buttons[10] = new Button(THREE, Vector2f(1045, 540), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"3");
		buttons[11] = new Button(FOUR, Vector2f(1110, 540), Vector2f(50, 50), font, 28, 5, usual, usualChosen, L"4");

		photosCount = 5;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\hard1.png");
		photos[1] = new Photo("Images\\hard2.png");
		photos[2] = new Photo("Images\\hard3.png");
		photos[3] = new Photo("Images\\hard4.png");
		photos[4] = new Photo("Images\\hard5.png");

		currentPhoto = photos[cur];

		break;
	}
	case GRADE:
	{
		buttonsCount = 7;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L" ");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Тест");

		buttons[4] = new Button(NOWHERE, Vector2f(955, 55), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Оценивание");
		buttons[5] = new Button(EASY, Vector2f(955, 105), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Легкий");
		buttons[6] = new Button(HARD, Vector2f(955, 155), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Сложный");

		photosCount = 1;
		photos = new Photo * [photosCount];

		photos[0] = new Photo("Images\\grade.png");

		currentPhoto = photos[cur];

		break;
	}
	case FINISH:
	{
		buttonsCount = 18;
		buttons = new Button * [buttonsCount];

		buttons[0] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 950), font, 32, 5, Color::White, usualChosen, L" ");
		buttons[1] = new Button(THEORY, Vector2f(50, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Теория");
		buttons[2] = new Button(CODE, Vector2f(350, 0), Vector2f(300, 50), font, 28, 5, usual, usualChosen, L"Код");
		buttons[3] = new Button(TEST, Vector2f(650, 0), Vector2f(300, 50), font, 28, 5, usualChosen, usualChosen, L"Тест");

		buttons[4] = new Button(NOWHERE, Vector2f(50, 55), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Результат прохождения теста");
		buttons[5] = new Button(NOWHERE, Vector2f(50, 110), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");
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

		buttons[16] = new Button(NOWHERE, Vector2f(50, 880), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L"Оценка");
		buttons[17] = new Button(NOWHERE, Vector2f(50, 935), Vector2f(900, 50), font, 32, 5, Color::White, Color::Transparent, L" ");

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

void Page::changeColour(int button)
{
	buttons[8]->setColour(Color(205, 237, 242));
	buttons[9]->setColour(Color(205, 237, 242));
	buttons[10]->setColour(Color(205, 237, 242));
	buttons[11]->setColour(Color(205, 237, 242));

	switch (button)
	{
	case 1:
	{
		buttons[8]->setColour(Color(160, 198, 203));
		break;
	}
	case 2:
	{
		buttons[9]->setColour(Color(160, 198, 203));
		break;
	}
	case 3:
	{
		buttons[10]->setColour(Color(160, 198, 203));
		break;
	}
	case 4:
	{
		buttons[11]->setColour(Color(160, 198, 203));
		break;
	}
	}
}

int Page::getCur()
{
	return cur;
}

void Page::setCur(int cur_)
{
	cur = cur_;
	if (photos)
		currentPhoto = photos[cur];
}

void Page::clearPage()
{
	for (int i = 5; i < 16; i++)
		buttons[i]->setText(L" ");

	buttons[17]->setText(L" ");
}