/**
* @class BackgroundHandler
* @brief The purpose of this class is to create game entities which constitute
* to the background of the game. These include the splash screen, game background, and 
* game over and game win text images.
*/

#ifndef BACKGROUNDSHANDLER_H
#define BACKGROUNDSHANDLER_H

#include "GameEntity.h"



class BackgroundsHandler
{
public:
    /**
	 * @brief Creates a BackgroundHandler object to manage background images.
	 * @return 
	 */
	BackgroundsHandler();
	
	/**
	 * @brief Returns a shared pointer to the sprite of _splashScreen.
	 * @return shared pointer to the sprite of the splash screen.
	 */
	std::shared_ptr<sf::Sprite> splashScreen(){return splashScreen_->getSprite();}
	
	/**
	 * @brief Returns a shared pointer to the sprite of _gameScreen.
	 * @return shared pointer to the sprite of the game play background.
	 */
	std::shared_ptr<sf::Sprite> gameScreen(){return gameScreen_->getSprite();}
	
	/**
	 * @brief Returns a shared pointer to the sprite of _gameOver.
	 * @return shared pointer to the sprite of the game over text image.
	 */
	std::shared_ptr<sf::Sprite> gameOver(){return gameOver_->getSprite();}
	
	/**
	 * @brief Returns a shared pointer to the sprite of _gameWin.
	 * @return shared pointer to the sprite of the game win text image.
	 */
	std::shared_ptr<sf::Sprite> gameWin(){return gameWin_->getSprite();}
	
private:
	//Shared pointer to a GameEntity representing the splash screen.
	std::shared_ptr<GameEntity> splashScreen_;
	//Shared pointer to a GameEntity representing the game background.
	std::shared_ptr<GameEntity> gameScreen_;
	//Shared pointer to a GameEntity representing the game over text image.
	std::shared_ptr<GameEntity> gameOver_;
	//Shared pointer to a GameEntity representing the game win text image.
	std::shared_ptr<GameEntity> gameWin_;
};

#endif
