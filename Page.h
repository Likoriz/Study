#pragma once
#include "Button.h"
#include "Photo.h"

class Page
{
private:
	Button** buttons;
	int buttonsCount;

	Photo** photos;
	int photosCount;

	Photo* currentPhoto;
	int cur;
public:
	Page(int page);
	Button** getButtons();
	int getButtonsCount();

	Photo** getPhotos();
	Photo* getCurrentPhoto();
	void prevPhoto();
	void nextPhoto();

	void draw(sf::RenderWindow& window);
};

