#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>
#include <codecvt>

extern sf::Color usual;
extern sf::Color usualChosen;

extern sf::Font* font;

enum Pages { MAIN = 0, THEORY, SORT, KAHN, TARJAN, DIFFICULTY, PLUSMINUS, USAGE, CODE, CODEKAHN, RUNKAHN, CODETARJAN, RUNTARJAN, TEST, EASY, HARD, GRADE, FINISH, NOWHERE, PREV, NEXT, ADDV, ADDADJ, REMADJ, RUNCODEKAHN, RUNCODETARJAN, ONE, TWO, THREE, FOUR };