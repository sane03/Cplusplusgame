#include "Bullet.h"

Bullet::Bullet():
GameEntity{"resources/bullet.PNG"},
Bullet_{std::make_shared<GameEntity>("resources/bullet.PNG")},
bulletspeed_{6},
state_{false}
{}



void Bullet::MoveBullet(std::shared_ptr<Bullet> bull)
{
    if(state_ == true)
    {
        incrementBullet(bull);
    }
    
   else if (state_ == false)
    {
     
    } 
}

void Bullet::incrementBullet(std::shared_ptr<Bullet> bull)
{
    auto Coordinate = bull->getSprite()->getPosition();
    Coordinate.y -= bulletspeed_;
    bull->getSprite()->setPosition(Coordinate);
}


