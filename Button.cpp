#include "Button.h"

using namespace std;
using namespace sf;

Button::Button(int leadsTo_ , sf::Vector2f position, sf::Vector2f size, sf::Font* font, int textSize, int outlineThickenss, sf::Color fillColor, sf::Color outlineColor, std::wstring text_)
{
	leadsTo = leadsTo_;

	rect.setPosition(position);
	rect.setSize(size);

	text.setFillColor(Color::Black);

	text.setFont(*font);
	text.setCharacterSize(textSize);
	text.setString(text_);

	sf::FloatRect textBounds = text.getLocalBounds();
	float textPosX = rect.getPosition().x + rect.getSize().x / 2 - textBounds.width / 2;
	float textPosY = rect.getPosition().y + rect.getSize().y / 2 - textBounds.height / 2;
	text.setPosition(textPosX, textPosY);

	rect.setFillColor(fillColor);
	rect.setOutlineColor(outlineColor);
	rect.setOutlineThickness(outlineThickenss);
}

sf::RectangleShape Button::getRect()
{
	return rect;
}

sf::Text Button::getText()
{
	return text;
}

int Button::getNavigation()
{
	return leadsTo;
}