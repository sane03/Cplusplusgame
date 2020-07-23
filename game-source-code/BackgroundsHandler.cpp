#include "BackgroundsHandler.h"

BackgroundsHandler::BackgroundsHandler():
    splashScreen_(std::make_shared<GameEntity>("resources/SplashScreen.JPG")),
    gameScreen_(std::make_shared<GameEntity>("resources/GamePlaySD.PNG")),
    gameOver_(std::make_shared<GameEntity>("resources/GameOver.PNG")),
    gameWin_(std::make_shared<GameEntity>("resources/GameWin.PNG"))
{
    splashScreen_->getSprite()->setPosition(splashScreen_->constants()->windowCenter());
   
	gameScreen_->getSprite()->setPosition(gameScreen_->constants()->windowCenter());
    gameWin_->getSprite()->setPosition(gameWin_->constants()->windowCenter());
   
	gameOver_->getSprite()->setPosition(gameOver_->constants()->windowCenter());
	
    
}