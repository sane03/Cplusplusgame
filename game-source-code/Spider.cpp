#include "Spider.h"

Spider::Spider():
GameEntity{"resources/spider.PNG"},
spider_{std::make_shared<GameEntity>("resources/spider.PNG")},
spiderspeed_{8},
Life_{3},
up_{true},
down_{false}
{
    getSprite()->setPosition(8,228);
}

void Spider::moveUp()
{
    auto Coordinate = getSprite()->getPosition();
    Coordinate.y -= spiderspeed_;
    getSprite()->setPosition(Coordinate);
   
}

void Spider::moveDown()
{
    auto Coordinate = getSprite()->getPosition();
    Coordinate.y += spiderspeed_;
    getSprite()->setPosition(Coordinate);
    
}

void Spider::moveLeft()
{
    
    auto Coordinate = getSprite()->getPosition();
    Coordinate.x -= spiderspeed_;
    getSprite()->setPosition(Coordinate);
    
}

void Spider::moveRight()
{
    auto Coordinate = getSprite()->getPosition();
    Coordinate.x += spiderspeed_;
    getSprite()->setPosition(Coordinate);
    
}

 void Spider::Movespider()
 
 {	
     if(getUp() == true)
		 
     {   
         moveUp();
         if (getSprite()->getPosition().y <= 100.f)
         {
			 moveRight();
			 getSprite()->setPosition(getSprite()->getPosition().x,100.f);
            
            up_ = false;
            down_ = true; 
         }
     }
    else if (getDown() == true )
		{
         moveDown();
		 
         if (getSprite()->getPosition().y >= 500.f)
         {
             moveRight();
			  getSprite()->setPosition(getSprite()->getPosition().x,500.f);
            up_ = true;
            down_ = false; 
         }
		}
			
}
