#include "Obstacle.h"
#include "Renderer/Renderer.h"

int main(int argc, char* args[])
{
    Obstacle box = Obstacle(2, 2);
    SDL_Init(SDL_INIT_EVERYTHING);
    Rend::Renderer rend = Rend::Renderer(640,480,60);
    // Keep the main loop until the window is closed (SDL_QUIT event)
    bool exit = false;
    SDL_Event eventData;

    rend.renderBackground(255,0,0,255);
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
    }
    rend.~Renderer();
    return 0;
}
