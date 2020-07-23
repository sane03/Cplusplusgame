#include "GameProcess.h"
#include <iostream>
using namespace std;
GameProcess::GameProcess():
collisions{std::make_shared<CollisionHandler>()},
background_{std::make_shared<BackgroundsHandler>()},
playerShip_{std::make_shared<PlayerShip>()},
centipedeBody_{std::make_shared<Centipede>()},
centipedeHead_{std::make_shared<Centipede>()},
bullet_{std::make_shared<Bullet>()},
hids_{std::make_shared<CentipedeHead>()},
Bods_{std::make_shared<CentipedeBody>()},
mushroom_{std::make_shared<Mushroom>()},
field_{std::make_shared<MushroomField>()},
spider_{std::make_shared<Spider>()},
delay_{sf::seconds(0.045f)},
gameState_{GameState::SplashScreen},
clock_{std::make_shared<sf::Clock>()},
period_{sf::seconds(5.0f)}
{
 setText();   
}


void GameProcess::receiveInput(Action direction)
{
    switch(direction)
    {
        case Action::UP:
        move(direction);
        break;
        
        case Action::DOWN:
        move(direction);
        break;
        
        case Action::LEFT:
        move(direction);
        break;
        
        case Action::RIGHT:
        move(direction);
        break;
        
        case Action::SHOOT:
        move(direction);
        break;
        
        default:
        break;
        
    }
    
    
}

void GameProcess::move(const Action& direction)
{
    switch(direction)
    {
        case Action::UP:
        playerShip_->moveUp();
        break;
        
        case Action::DOWN:
        playerShip_->moveDown();
        break;
        
        case Action::LEFT:
        playerShip_->moveLeft();
        break;
        
        case Action::RIGHT:
        playerShip_->moveRight();
        break;
        
        case Action::SHOOT:
        
        bullet_->setStates(true);
        bullet_->Position(playerShip_->startPos());
         if(timer_.getElapsedTime() > delay_)
         {
            playerShip_->LoadBullet(); 
            
         }
         timer_.restart();
         timer2_.restart();
        
        
        break;
        
        default:
        break;
        
    }
    
}

void GameProcess::GameLoop()
{
    for ( auto& x : centipedeHead()->heads())
    {
    x->getDirection(x);
    }
    for ( auto& x : centipedeBody()->bodies())
    {
    x->getDirection(x);
    }

    for (auto& x : playerShip()->bullets())
    {
       bulletObj()->MoveBullet(x); 
    }
    
    
     if(clock_->getElapsedTime() > period_)
     {
         spider_->Movespider();
     }
     if(timer2_.getElapsedTime() < period_)
     {
         collisions->SpiderMushroomCollision(spider_,field_);
     } 
     
     collisionHandler_();
     OffscreenObjectHandler_();
     createText(ScoreCount.getScore(),playerShip()->getLife());
     gameState();

   
}

void GameProcess::collisionHandler_()
{
    collisions->BulletBodyCollision(playerShip_,centipedeBody_,centipedeHead_,field_,ScoreCount);
    collisions->BulletHeadCollision(playerShip_,centipedeBody_,centipedeHead_,ScoreCount);
    collisions->BulletMushroomCollision(playerShip_,field_,ScoreCount);
    collisions->MushroomBodyCollisions(centipedeBody_,field_,Bods_);
    collisions->MushroomHeadCollision(centipedeHead_,field_);
    collisions->PlayerBodyCollision(playerShip_,centipedeBody_);
    collisions->PlayerHeadCollision(playerShip_,centipedeHead_);
    collisions->PlayerSpiderCollision(playerShip_,spider_);
    collisions->BulletSpiderCollision(playerShip_,spider_,ScoreCount);
 } 
 
 void GameProcess::setText()
{
    if(!font.loadFromFile("resources/sansation.TTF"))
		throw FontNotFound();
	//Set Text defaults
	else{
		text.setFont(font);
		text.setCharacterSize(23);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::Red);
	}
}

 
void GameProcess::createText(int score, int Life)
{
    string Strng1 = "Score ";
	string Strng2 = std::to_string(score);
    string Strng3 = "Lives ";
    string Strng4 = std::to_string(Life);
    text.setString(Strng1 + Strng2 + " "+ Strng3 + Strng4);  
}

void GameProcess::OffscreenObjectHandler_()
{

	auto vec1 = playerShip_->bullets();
for (unsigned int i =0; i < vec1.size(); i++)
 {if(playerShip_->Bullet_off_screen(vec1[i]) == true) 
 {playerShip()->deleteBullets(i);

 }}
 } 
 
 void GameProcess::gameState()
 {
     if(centipedeHead()->heads().size() == 0 && centipedeBody()->bodies().size() == 0) 
         {
             setGameState(GameState::GameWin);
         }
     else if(playerShip_->getLife() == 0)
     {
         setGameState(GameState::GameOver);
     }
              ScoreCount.storeHighScore();
 }