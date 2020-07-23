#include "MushroomField.h"

MushroomField::MushroomField(long double pacer)
{       init(pacer);
        for(auto x = 0; x < 59 ; x++)
        {
             randomCoordinateGenerator();
        }
       
}

MushroomField::MushroomField()
{       init(time(NULL));
        for(auto x = 0; x < 59 ; x++)
        {
             randomCoordinateGenerator();
        }
       
}

void MushroomField::randomCoordinateGenerator()
{

    
    auto xLoc = rand()%960;
    auto yLoc = rand()%(430-101)+100;
    Check(xLoc,yLoc);
    
    
    
}

void MushroomField::initialiseField(int xLoc, int yLoc)
{
    auto shroom = std::make_shared<Mushroom>();
    shroom->getSprite()->setPosition(xLoc,yLoc);
    Mushrooms.push_back(shroom);
}
    
    


void MushroomField::init(long double l)
{
    srand(l);
    
    auto xLoc = rand()%960;
    auto yLoc = rand()%(430-101)+100;
    
    auto shroom = std::make_shared<Mushroom>();
    shroom->getSprite()->setPosition(xLoc,yLoc);
    Mushrooms.push_back(shroom);

}

void MushroomField::Check(int xLoc, int yLoc)
{
    
     for(auto x : Mushrooms)
    {
    if(xLoc == x->shroom()->getPosition().x || yLoc == x->shroom()->getPosition().y)
        {
        randomCoordinateGenerator();
        }
    }
    
    initialiseField(xLoc,yLoc);
    
}

void MushroomField::deleteMushrooms(int x)
{
    Mushrooms.erase(Mushrooms.begin()+ x);
}