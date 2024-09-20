#include "Physics/Obstacle.h"
#include "Renderer/Renderer.h"
#include "Renderer/RenderObject.h"
#include "Entity/Entity.h"
#include <iostream>


const int FPS = 60;
const int frameDelay = 1000 / FPS;


int main(int argc, char* args[])
{
    Obstacle box = Obstacle(2, 2);
    SDL_Init(SDL_INIT_EVERYTHING);
    Rend::Renderer rend = Rend::Renderer(640,480);
    // Keep the main loop until the window is closed (SDL_QUIT event)
    bool exit = false;
    SDL_Event eventData;





    std::shared_ptr<Ent::Entity> temp3 = std::make_shared<Ent::Entity>();
    rend.addObjectToRender(temp3);

    bool running = true;
    Uint32 frameStart;
    int frameTime;
    int frameCount = 0;
    while (running)
    {
        rend.renderBackground(255,0,0,255);
        frameStart = SDL_GetTicks();  // Get the number of milliseconds since the SDL library was initialized

        // Event handling
        while (SDL_PollEvent(&eventData))
        {
            if (eventData.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }

        // Frame time control
        frameTime = SDL_GetTicks() - frameStart;  // Calculate how long this frame took

        // If the frame completed too quickly, delay to maintain the frame rate
        printf("Started\n");

        rend.renderObject();
        printf("Rendered\n");
        temp3->moveXY(std::pair<int, int>(1, 0));
        frameCount++;
        printf("frameCount: %d\n", frameCount);
        SDL_Delay(frameDelay - frameTime);  // Delay to fill the remaining time of the frame
            
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime); 
    }
    return 0;
}
