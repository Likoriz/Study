#pragma once
#include "Page.h"
#include "TestChecker.h"

class App
{
private:
	static App* instance;

	TestChecker* check;

	const int pagesCount = 18;
	Page** pages;

	Page* currentPage;

	std::wstring input;
	int state = -1;

	int curKahn = 13;
	int curTarjan = 13;
public:
	App();
	~App();
	static App* getInstance();
	void Run(sf::RenderWindow& window);
	Page* getPage(int page);
	std::wstring getInput();
	void setInput(std::wstring input_);
	int getState();
	void setState(int state_);
	int getCurKahn();
	void setCurKahn(int cur_);
	int getCurTarjan();
	void setCurTarjan(int cur_);
	std::wstring runKahn();
	std::wstring runTarjan();
	bool isNumber(const std::wstring& str);
};

