#include "CentipedeBody.h"


CentipedeBody::CentipedeBody()
    : GameEntity("resources/body.PNG")
    , Body_{ std::make_shared<GameEntity>("resources/body.PNG") }
    , right_{ true }
    , left_{ false }
    , UpReverse_{ false }
{
}

void CentipedeBody::moveCentipedeLeft(std::shared_ptr<CentipedeBody>& Centi)
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

void CentipedeBody::moveCentipedeRight(std::shared_ptr<CentipedeBody>& Centi)
{

    Centi->getSprite()->setPosition((Centi->getSprite()->getPosition().x + 5), Centi->getSprite()->getPosition().y);

    if(Centi->getSprite()->getPosition().x >= 944) {
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

void CentipedeBody::getDirection(std::shared_ptr<CentipedeBody>& x)
{

    if(x->getHeadRight() == true) {

	x->moveCentipedeRight(x);
    }
    else if(x->getHeadLeft() == true) {

	x->moveCentipedeLeft(x);
    }
}

void CentipedeBody::TurnDown(std::shared_ptr<CentipedeBody>& Centi)
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

void CentipedeBody::ReverseDirection(std::shared_ptr<CentipedeBody>& Centi)
{
    if(Centi->getHeadRight() == true) {
	Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x, Centi->getSprite()->getPosition().y - 8);
	//Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x - 5, Centi->getSprite()->getPosition().y);
	Centi->setHeadLeft(true);
	Centi->setHeadRight(false);
    }
    else if(Centi->getHeadLeft() == true) {
	Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x, Centi->getSprite()->getPosition().y - 8);
	//Centi->getSprite()->setPosition(Centi->getSprite()->getPosition().x + 5, Centi->getSprite()->getPosition().y);
	Centi->setHeadRight(true);
	Centi->setHeadLeft(false);
    }

    if(Centi->getSprite()->getPosition().y <= 10)
	setReverseDirection(false);
}
