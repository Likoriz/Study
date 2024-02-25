#include "App.h"
#include "Kahn.h"
#include "Tarjan.h"

using namespace std;
using namespace sf;

int main()
{
    App* app = App::getInstance();
    RenderWindow window(VideoMode::getDesktopMode(), "Study", Style::Close);
    
    app->Run(window);

    return 0;
}