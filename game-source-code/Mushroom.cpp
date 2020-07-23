#include "Mushroom.h"

Mushroom::Mushroom():
GameEntity("resources/mushroom.PNG"),
shroom_{std::make_shared<GameEntity>("resources/mushroom.PNG")},
Life_{3}
{}

void Mushroom::decreaseLife()
{
    Life_ -= 1;
}