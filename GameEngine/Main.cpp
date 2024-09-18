#include "RunWindow.h"
#include "Obstacle.h"

int main(int argc, char* args[])
{
    RunWindow test = RunWindow();
    Obstacle box = Obstacle(2, 2);
    return test.Run();
}
