#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/Game.h"

///////////////////////////////////////////////////test resource loading////////////////////////////
TEST_CASE("Exception Thrown when Images Not Found")
{
    CHECK_THROWS_AS(GameEntity Splash("resources/SplashScree.JPG"),ImageNotFound);
    CHECK_THROWS_AS(GameEntity gamePlay("resources/GamePlayS.JPG"),ImageNotFound);
	
}



//-----------------------------------------------Testing Player Movements------------------------------------
TEST_CASE("Player moves right correctly")
{
	auto xyCoordinate=	sf::Vector2f(473,0);
	PlayerShip player;
	player.player()->setPosition(465,0);
	player.moveRight();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.y==xyCoordinate.y);
	CHECK(retrieve.x==xyCoordinate.x);
}


TEST_CASE("Player moves left correctly")
{
	auto xyCoordinate=	sf::Vector2f(482,0);
	PlayerShip player;
	player.player()->setPosition(490,0);
	player.moveLeft();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.y==xyCoordinate.y);
	CHECK(retrieve.x==xyCoordinate.x);
	
}

TEST_CASE("Player moves down correctly")
{
	auto xyCoordinate=	sf::Vector2f(0,493);
	PlayerShip player;
	player.player()->setPosition(0,485);
	player.moveDown();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.x==xyCoordinate.x);
	CHECK(retrieve.y==xyCoordinate.y);
}

TEST_CASE("Player moves up correctly")
{

	auto xyCoordinate=	sf::Vector2f(0,487);
	PlayerShip player;
	player.player()->setPosition(0,495);
	player.moveUp();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.y==xyCoordinate.y);
	CHECK(retrieve.x==xyCoordinate.x);

}


///////////////////////////////////////////////////////////////Testing Bounds of player play area//////////////////////////////////////
 
TEST_CASE("Player_play area bounded upwards")
{
	auto xyCoordinate=	sf::Vector2f(0,440);
	PlayerShip player;
	player.player()->setPosition(0,440);
	player.moveUp();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.y==xyCoordinate.y);
	CHECK(retrieve.x==xyCoordinate.x);
	
}


TEST_CASE("Player play area Left bounded")
{
	auto xyCoordinate=	sf::Vector2f(10,500);
	PlayerShip player;
	player.player()->setPosition(10,500);
	player.moveLeft();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.y==xyCoordinate.y);
	CHECK(retrieve.x==xyCoordinate.x);
}

TEST_CASE("Player play area Right bounded")
{
	auto xyCoordinate=	sf::Vector2f(944,500);
	PlayerShip player;
	player.player()->setPosition(944,500);
	player.moveRight();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.y==xyCoordinate.y);
	CHECK(retrieve.x==xyCoordinate.x);
}

TEST_CASE("Player play area Down bounded")
{
	auto xyCoordinate=	sf::Vector2f(0,530);
	PlayerShip player;
	player.player()->setPosition(0,525);
	player.moveDown();
    player.moveDown();
	auto retrieve= player.player()->getPosition();
	CHECK(retrieve.x==xyCoordinate.x);
	CHECK(retrieve.y==xyCoordinate.y);
}

//_-----------------------------------Bullet moves up-----------------------------------------------
TEST_CASE("Bullet moves UP when shoot is pressed")
{
    auto bullet = std::make_shared<Bullet>();
    bullet->getSprite()->setPosition(470,280);
    bullet->incrementBullet(bullet);
    CHECK(bullet->getSprite()->getPosition().x == 470.f);
    CHECK(bullet->getSprite()->getPosition().y == 274.f);    
}

//------------------------------------Centipede Movements work---------------------------------------

TEST_CASE("Centipede move LEFT works")
{
    auto Body = std::make_shared<CentipedeBody>();
    Body->getSprite()->setPosition(470,280);
    Body->moveCentipedeLeft(Body);
    CHECK(Body->getSprite()->getPosition().x == 465.f);
    CHECK(Body->getSprite()->getPosition().y == 280.f);    
}

TEST_CASE("Centipede move RIGHT works")
{
    auto Body = std::make_shared<CentipedeBody>();
    Body->getSprite()->setPosition(470,280);
    Body->moveCentipedeRight(Body);
    CHECK(Body->getSprite()->getPosition().x == 475.f);
    CHECK(Body->getSprite()->getPosition().y == 280.f);    
}

TEST_CASE("Centipede move Right Boundary Turn Down Behaviour works")
{
    auto Body = std::make_shared<CentipedeBody>();
    Body->getSprite()->setPosition(944,280);
    Body->TurnDown(Body);
    CHECK(Body->getSprite()->getPosition().x == 944.f);
    CHECK(Body->getSprite()->getPosition().y == 288.f);    
}

TEST_CASE("Centipede move Left Boundary Turn Down Behaviour works")
{
    auto Body = std::make_shared<CentipedeBody>();
    Body->getSprite()->setPosition(10,280);
    Body->setHeadLeft(true);
    Body->setHeadRight(false);//make it simulate a move left function
    Body->TurnDown(Body);
    CHECK(Body->getSprite()->getPosition().x == 10.f);
    CHECK(Body->getSprite()->getPosition().y == 288.f);    
}



//----------------------------------------------------------------------------------------------------------

TEST_CASE("Centipede move Up once it hits bottom of player bound from right")
{
    auto Body = std::make_shared<CentipedeBody>();
	
    Body->getSprite()->setPosition(10,525);
	
    Body->setHeadLeft(true);
    Body->setHeadRight(false);//make it simulate a move left function
	

    Body->ReverseDirection(Body);
    CHECK(Body->getSprite()->getPosition().x == 10.f);
    CHECK(Body->getSprite()->getPosition().y == 517.f);    
}

TEST_CASE("Centipede move Up once it hits bottom of player bound from left")
{
    auto Body = std::make_shared<CentipedeBody>();
	
    Body->getSprite()->setPosition(944,525);
	
    Body->setHeadLeft(false);
    Body->setHeadRight(true);//make it simulate a move left function
	

    Body->ReverseDirection(Body);
    CHECK(Body->getSprite()->getPosition().x == 944.f);
    CHECK(Body->getSprite()->getPosition().y == 517.f);    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*TEST_CASE("Centipede switches to move down once it reaches top of screen from left ")
{
  auto Body = std::make_shared<CentipedeBody>();
	
    Body->getSprite()->setPosition(944,0);
	
    Body->setHeadLeft(false);
    Body->setHeadRight(true);//make it simulate a move left function
	

    Body->ReverseDirection(Body);
	
    CHECK(Body->getSprite()->getPosition().x == 944.f);
    CHECK(Body->getSprite()->getPosition().y == 517.f);  
}*/


////////////////////////////////////////////////////////////////////Spider/////////////////////////////////////////////////////////////////////////////////


TEST_CASE("Spidermoves across player area")
{
    auto spiders = std::make_shared<Spider>();
	
    spiders->getSprite()->setPosition(500,440);
	
    spiders->moveDown();
	spiders->moveDown();

    CHECK(spiders->getSprite()->getPosition().x == 500.f);
    CHECK(spiders->getSprite()->getPosition().y == 456.f);    
}

///////////////////////////////////////////////////spider Vertical bounds ////////////////////////////////////////////////////////////////////////

TEST_CASE("Spidermoves is vertically up bound")
{
    auto spiders = std::make_shared<Spider>();
    spiders->getSprite()->setPosition(500,100);
	spiders->SetBoolUp(true);
	spiders->SetBoolDown(false);
    spiders->Movespider();
	spiders->SetBoolUp(true);
	spiders->SetBoolDown(false);
    spiders->Movespider();


    CHECK(spiders->getSprite()->getPosition().y >= 100.f);
    CHECK(spiders->getSprite()->getPosition().x == 516.f);    
}


TEST_CASE("Spidermoves is vertically down bound")
{
    auto spiders = std::make_shared<Spider>();
    spiders->getSprite()->setPosition(500,530);
	spiders->SetBoolUp(false);
	spiders->SetBoolDown(true);
    spiders->Movespider();


    CHECK_FALSE(spiders->getSprite()->getPosition().y >= 530.f);
    CHECK(spiders->getSprite()->getPosition().x == 508.f);    
}


///////////////////////////////////////////////////spider Horizontal bounds ////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////Mushroom ///////////////////////////////////////////////////////

TEST_CASE("Mushrooms are randomly placed")
{
			auto Shrooms = std::make_unique<MushroomField>(1234567890);
			auto Rooms = std::make_unique<MushroomField>(98673642344);
			auto j= Rooms->getMushroomVector().at(36)->getSprite()->getPosition();
			auto K= Shrooms->getMushroomVector().at(36)->getSprite()->getPosition();

			CHECK_FALSE(j.y==K.y);
			CHECK_FALSE (j.x==K.x);
}



////////////////////////////////////////collision detection //////////////////////////////


TEST_CASE("Collision detection  works ")
{	Score score;
	CollisionDetector detector;
	 auto centi = std::make_shared<CentipedeHead>();
	 auto play = std::make_shared<PlayerShip>();
	 centi->getSprite()->setPosition(500,500);
	 play->getSprite()->setPosition(500,500);
	 CHECK( detector.isCollided(centi,play));
}

TEST_CASE("Collision detection  works ")
{	Score score;
	CollisionDetector detector;
	 auto centi = std::make_shared<CentipedeHead>();
	 auto play = std::make_shared<PlayerShip>();
	 centi->getSprite()->setPosition(400,400);
	 play->getSprite()->setPosition(500,500);
	 CHECK_FALSE( detector.isCollided(centi,play));
}


///////////////////////////////////////////////////////////



