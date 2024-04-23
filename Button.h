#pragma once
#include "Basics.h"

class Button
{
private:
	sf::RectangleShape rect;
	sf::Font* font;
	sf::Text text;
	int leadsTo;
public:
	Button(int leadsTo_, sf::Vector2f position, sf::Vector2f size, sf::Font* font, int textSize, int outlineThickenss, sf::Color fillColor, sf::Color outlineColor = sf::Color::Transparent, std::wstring text_ = L"");
	sf::RectangleShape getRect();
	sf::Text getText();
	void setText(std::wstring text_);
	int getNavigation();

	void setColour(sf::Color color_);
};

