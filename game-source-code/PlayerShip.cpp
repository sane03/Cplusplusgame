#include "PlayerShip.h"

PlayerShip::PlayerShip():
GameEntity{"resources/blaster.PNG"},
playerShip_{std::make_shared<GameEntity>("resources/blaster.PNG")},
playerspeed_{8},
Life_{3}
{
	playerShip_->setState(true);
	initialisePlayer();

}

void PlayerShip::initialisePlayer()
{
    playerShip_->getSprite()->setPosition(playerShip_->constants()->windowCenter().x, 500); 
    
}

void PlayerShip::moveUp()
{ 
    auto Coordinate = playerShip_->getSprite()->getPosition();
 //   std::cout<<playerShip_->getSprite()->getPosition().x<<"   "<<   playerShip_->getSprite()->getPosition().y<<std::endl;
   if(Coordinate.y <= playerShip_->constants()->windowDimensions().y - 100)
    {
      Coordinate.y  = playerShip_->constants()->windowDimensions().y-100;
    }
    else
      Coordinate.y -= playerspeed_;

  playerShip_->getSprite()->setPosition(Coordinate);
}

void PlayerShip::moveDown()
{
    auto Coordinate = playerShip_->getSprite()->getPosition();
   
    if((Coordinate.y + 10.f) >= playerShip_->constants()->windowDimensions().y)
    {
      Coordinate.y  = playerShip_->constants()->windowDimensions().y - 10.f;
    }
    else
      Coordinate.y += playerspeed_;

  playerShip_->getSprite()->setPosition(Coordinate);
    
}

void PlayerShip::moveLeft()
{
    auto Coordinate = playerShip_->getSprite()->getPosition();
   
    if(Coordinate.x <= 10)
    {
      Coordinate.x  = 10;
    }
    else
      Coordinate.x -= playerspeed_;

  playerShip_->getSprite()->setPosition(Coordinate);
    
    
}

void PlayerShip::moveRight()
{
    auto Coordinate = playerShip_->getSprite()->getPosition();
   
    if(Coordinate.x + 16 >= playerShip_->constants()->windowDimensions().x)
    {
      Coordinate.x  = playerShip_->constants()->windowDimensions().x - 16;
    }
    else
      Coordinate.x += playerspeed_;

  playerShip_->getSprite()->setPosition(Coordinate);
    
}

void PlayerShip::LoadBullet()
{
    auto bullet = std::make_shared<Bullet>();
    bullet->getSprite()->setPosition(startPos());
    bullets_.push_back(bullet);
}

void PlayerShip::deleteBullets(int x)
{
    bullets_.erase(bullets_.begin()+ x);
}

bool PlayerShip::Bullet_off_screen(const std::shared_ptr<Bullet> _entity1)
{
	auto Pos1 = _entity1->getSprite()->getPosition();
	if(Pos1.y==0)
	return true;
	else 
		return false;
}