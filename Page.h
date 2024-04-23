#pragma once
#include "Button.h"
#include "Photo.h"

class Page
{
private:
	Button** buttons;
	int buttonsCount;

	Photo** photos = nullptr;
	int photosCount = 0;

	Photo* currentPhoto = nullptr;
	int cur = 0;
public:
	Page(int page);
	Button** getButtons();
	int getButtonsCount();

	Photo** getPhotos();
	Photo* getCurrentPhoto();
	void prevPhoto();
	void nextPhoto();

	void changeColour(int button);
	int getCur();
	void setCur(int cur_);
	void clearPage();

	void draw(sf::RenderWindow& window);
};

