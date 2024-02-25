#pragma once
#include "Page.h"

class App
{
private:
	static App* instance;

	const int pagesCount = 14;
	Page** pages;

	Page* currentPage;
public:
	App();
	~App();
	static App* getInstance();
	void Run(sf::RenderWindow& window);
	Page* getPage(int page);
};

