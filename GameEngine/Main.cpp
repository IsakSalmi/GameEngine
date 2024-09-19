#include "Obstacle.h"
#include "Renderer/Renderer.h"
#include "Renderer/RenderObject.h"

int main(int argc, char* args[])
{
    Obstacle box = Obstacle(2, 2);
    SDL_Init(SDL_INIT_EVERYTHING);
    Rend::Renderer rend = Rend::Renderer(640,480);
    // Keep the main loop until the window is closed (SDL_QUIT event)
    bool exit = false;
    SDL_Event eventData;

    rend.renderBackground(255,0,0,255);
    std::unique_ptr<Rend::RenderObject> temp = std::make_unique<Rend::RenderObject>();
    temp->setPos(20,20);
    rend.addObjectToRender(std::move(temp));

    std::unique_ptr<Rend::RenderObject> temp1 = std::make_unique<Rend::RenderObject>();
    temp1->setPos(300,20);
    rend.addObjectToRender(std::move(temp1));

    std::unique_ptr<Rend::RenderObject> temp2 = std::make_unique<Rend::RenderObject>();
    temp2->setPos(20,300);
    rend.addObjectToRender(std::move(temp2));
    while (!exit)
    {
        while (SDL_PollEvent(&eventData))
        {
            switch (eventData.type)
            {
            case SDL_QUIT:
                exit = true;
                break;
            }
        }
        rend.renderObject();
    }
    return 0;
}
