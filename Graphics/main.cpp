
#include "core.h"
#include "vector2.h"
#include "painter.h"
#include <iostream>
#include <vector>

Painter painter;

bool Update(float dt)
{
    bool quit = false;
    quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);
    
    painter.Update(dt);

    return quit;
}

void Draw(Core::Graphics& graphics)
{
    graphics.SetColor(RGB(rand() % 255, rand() % 255, rand() % 255));

    painter.Draw(graphics);
}

int main()
{
    painter.Load("picture.txt");

    char name[] = "Garrick";
    Core::Init(name, 800, 600);
    Core::RegisterUpdateFn(Update);
    Core::RegisterDrawFn(Draw);
    Core::GameLoop();
    Core::Shutdown();

    painter.Save("picture.txt");

    
    /*char name[] = "Garrick";
    Core::Init(name, 640, 480);
    Core::RegisterUpdateFn(Update);
    Core::RegisterDrawFn(Draw);
    Core::GameLoop();
    Core::Shutdown();
    
    std::cout << "Hello World!\n";*/
}

