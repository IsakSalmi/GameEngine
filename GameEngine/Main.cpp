#include "Physics/Obstacle.h"
#include "Renderer/Renderer.h"
#include "Renderer/RenderObject.h"
#include "Utility/ObjectUtility.h"
#include "Entity/Entity.h"
#include <iostream>


const int FPS = 60;
const int frameDelay = 1000 / FPS;


int main(int argc, char* args[])
{
    Obstacle box = Obstacle(2, 2);
    SDL_Init(SDL_INIT_EVERYTHING);
    Rend::Renderer rend = Rend::Renderer(1920 ,1080);
    // Keep the main loop until the window is closed (SDL_QUIT event)
    bool exit = false;
    SDL_Event eventData;


    std::shared_ptr<Ent::Entity> temp1 = std::make_shared<Ent::Entity>();
    rend.addObjectToRender(temp1);
    std::shared_ptr<Ent::Entity> temp2 = std::make_shared<Ent::Entity>();
    temp2->setWidhtAndHeight({30, 500});
    temp2->setPoistionXY({500,50});
    rend.addObjectToRender(temp2);
  
    std::shared_ptr<Ent::Entity> temp3 = std::make_shared<Ent::Entity>();
    temp3->setWidhtAndHeight({30, 500});
    temp3->setPoistionXY({0,50});
    rend.addObjectToRender(temp3);

    bool running = true;
    Uint32 frameStart;
    int frameTime;
    int frameCount = 0;

    Utility::ObjectUtility utility;

    int32_t dir = 5;
    while (running)
    {
        rend.renderBackground(255,0,0,255);
        frameStart = SDL_GetTicks();  // Get the number of milliseconds since the SDL library was initialized

        // Event handling
        while (SDL_PollEvent(&eventData)) {
            if (eventData.type == SDL_QUIT)
            {
                running = false;
                break;
            }
            if (eventData.type == SDL_MOUSEBUTTONUP) {
                if (eventData.button.state == SDL_RELEASED) {
                    rend.removeObject("nullID");
                }
            }
        }
        if(utility.checkCollision(temp1->getRect(), temp2->getRect())){
            dir = -5;
        }
        else if (utility.checkCollision(temp1->getRect(), temp3->getRect())) {
            dir = 5;
        }
        else {
        }
        temp1->moveXY({dir,-1});

        frameTime = SDL_GetTicks() - frameStart;  // Calculate how long this frame took

        rend.renderObject();
        frameCount++;
        SDL_Delay(frameDelay - frameTime);  // Delay to fill the remaining time of the frame
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime); 
    }
    return 0;
}
