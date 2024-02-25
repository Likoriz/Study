#include "Photo.h"

using namespace std;
using namespace sf;

Photo::Photo(std::string path)
{
    if (!texture.loadFromFile(path))
        cout << "ERROR: LOADING IMAGE" << endl;

    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(50, 55));
    sprite.setScale(Vector2f(900.0f / texture.getSize().x, 950.0f / texture.getSize().y));
}

sf::Sprite Photo::getSprite()
{
    return sprite;
}