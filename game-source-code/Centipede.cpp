#include "Centipede.h"
#include <iostream>
Centipede::Centipede():
GameEntity("resources/body.PNG")
//isAlive_{true}
{    
    createCentipede();
}

void Centipede::createCentipede()
{
    auto hed = std::make_shared<CentipedeHead>();
    hed->getSprite()->setPosition(480,80);
    Heads.push_back(hed);
    auto hed1 = std::make_shared<CentipedeBody>();
    hed1->getSprite()->setPosition(465,80);
    Bodys.push_back(hed1); 
   auto hed2 = std::make_shared<CentipedeBody>();
    hed2->getSprite()->setPosition(450,80);
    Bodys.push_back(hed2);
    auto hed3 = std::make_shared<CentipedeBody>();
    hed3->getSprite()->setPosition(435,80);
    Bodys.push_back(hed3);
    auto hed4 = std::make_shared<CentipedeBody>();
    hed4->getSprite()->setPosition(420,80);
    Bodys.push_back(hed4); 
   auto hed5 = std::make_shared<CentipedeBody>();
    hed5->getSprite()->setPosition(405,80);
    Bodys.push_back(hed5);
    auto hed6 = std::make_shared<CentipedeBody>();
    hed6->getSprite()->setPosition(390,80);
    Bodys.push_back(hed6);

    
    

    
}


void Centipede::deleteBody(int x)
{
    Bodys.erase(Bodys.begin()+ x);

}

void Centipede::deleteHead(int x)
{
    Heads.erase(Heads.begin()+ x);

}

void Centipede::CreateHead(int x, int y)
{
    auto head = std::make_shared<CentipedeHead>();
    head->getSprite()->setPosition(x,y);
    Heads.push_back(head);
}