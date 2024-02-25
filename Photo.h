#pragma once
#include "Basics.h"

class Photo
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int number;
public:
	Photo(std::string path);
	sf::Sprite getSprite();
};

