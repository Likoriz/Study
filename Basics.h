#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

extern sf::Color usual;
extern sf::Color usualChosen;

extern sf::Font* font;

enum Pages { MAIN = 0, THEORY, SORT, KAHN, TARJAN, DIFFICULTY, PLUSMINUS, USAGE, CODE, CODEKAHN, CODETARJAN, TEST, GRADE, FINISH, NOWHERE, PREV, NEXT };