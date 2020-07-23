/**
* @class GameEntity
* @brief The purpose of this class is to load game entity images with the use of the
* ImageHandler object. This class also provides access to the sprite of the game entity,
* game constants, game entity states and scaling characteristics. Inheritance was extensively
* implemented in the design architecture and there this class serves as the main base class for
* all game entities. 
*/


#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "ImageHandler.h"
#include "Constants.h"
//Exceptions
class GameEntityNotFound{};

class GameEntity
{
public:
    /**
	 * @brief Creates a GameEntity object.
	 * @param filename : string constant of the file name of the image of the game entity.
	 */
	GameEntity(const std::string& filename);
	
	/**
	 * @brief Returns the sprite of the game entity.
	 * @return _entitySprite : Shared pointer of type sf::Sprite.
	 */
	std::shared_ptr<sf::Sprite> getSprite() {return entitySprite_;}
	
	/**
	 * @brief Retruns a shared pointer to a Constants object which is used to access game constants.
	 * @return _constants : Shared pointer of type Constants.
	 */
	std::shared_ptr<Constants> constants(){return constants_;}
	
	/**
	 * @brief Returns a boolean corresponding to the current state of the game entity.
	 * @return _state: bool.
	 */
	bool isLive(){return state_;}
	
	/**
	 * @brief Sets the current state of the game entity.
	 * @param state : bool.
	 */
	void setState(bool state){state_ = state;}

	
private:
	//State of the game entity used in domain algorithms and game loop.
	bool state_;
	//Shared pointer to an ImageHandler object. Used for image loading.
	std::shared_ptr<ImageHandler> imageHandler_;
	//Shared pointer of type sf::Sprite used by the image handler to load the corresponding game entity sprites.
	std::shared_ptr<sf::Sprite> entitySprite_;
	//This allows any GameEntity to access the default constants.
	std::shared_ptr<Constants> constants_;

    
};
#endif