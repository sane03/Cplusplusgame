#include "CentipedeHead.h"
#include <iostream>
CentipedeHead::CentipedeHead()
    : GameEntity{ "resources/head.PNG" }
    , Head_{ std::make_shared<GameEntity>("resources/head.PNG") }
    , right_{ true }
    , left_{ false }
    , UpReverse_{ false }
{
}

void CentipedeHead::moveCentipedeLeft(std::shared_ptr<CentipedeHead>& Centi)
{
    
    Centi->getSprite()->setPosition((Centi->getSprite()->getPosition().x - 5), Centi->getSprite()->getPosition().y);

    if(Centi->getSprite()->getPosition().x <= 10) {

	if(Centi->getSprite()->getPosition().y >= 530) {
	    setReverseDirection(true);
	    ReverseDirection(Centi);
	}
	else if(Centi->getReverseDirection() == false)
	    TurnDown(Centi);
	if(Centi->getReverseDirection() == true) {
	    ReverseDirection(Centi);
	}
    }
     
}

void CentipedeHead::moveCentipedeRight(std::shared_ptr<CentipedeHead>& Centi)
{

    Centi->getSprite()->setPosition((Centi->getSprite()->getPosition().x + 5), Centi->getSprite()->getPosition().y);

    if(Centi->getSprite()->getPosition().x  >= 944) {

	if(Centi->getSprite()->getPosition().y >= 530) {
	    setReverseDirection(true);
	    ReverseDirection(Centi);
	}
	else if(Centi->getReverseDirection() == false)
	    TurnDown(Centi);

	if(Centi->getReverseDirection() == true) {
	    ReverseDirection(Centi);
	}
    }
}

void CentipedeHead::getDirection(std::shared_ptr<CentipedeHead>& x)
{

    if(x->getHeadRight() == true) {

	x->moveCentipedeRight(x);
    }
    else if(x->getHeadLeft() == true) {

	x->moveCentipedeLeft(x);
    }
}

void CentipedeHead::TurnDown(std::shared_ptr<CentipedeHead>& Centi)
{
    if(Centi->getHeadRight() == true) {
		Centi->getSprite()->rotate(90);
	Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x, Centi->getSprite()->getPosition().y + 8);
	Centi->getSprite()->rotate(90);
	Centi->setHeadLeft(true);
	Centi->setHeadRight(false);
    }
    else if(Centi->getHeadLeft() == true) {
    Centi->getSprite()->rotate(-90);
	Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x, Centi->getSprite()->getPosition().y + 8);
	
	Centi->getSprite()->rotate(-90);
	Centi->setHeadRight(true);
	Centi->setHeadLeft(false);
    }
}

void CentipedeHead::ReverseDirection(std::shared_ptr<CentipedeHead>& Centi)
{
    if(Centi->getHeadRight() == true) {
		
	Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x, Centi->getSprite()->getPosition().y - 8);

	Centi->setHeadLeft(true);
	Centi->setHeadRight(false);
    }
    else if(Centi->getHeadLeft() == true) {

	Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x, Centi->getSprite()->getPosition().y - 8);
	Centi->setHeadRight(true);
	Centi->setHeadLeft(false);
    }

    if(Centi->getSprite()->getPosition().y <= 0)
	setReverseDirection(false);
}
