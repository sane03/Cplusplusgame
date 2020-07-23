/**
* @class Mushroom
* @brief The purpose of this class is to create a game entity of type mushroom 
* and create the corresponding responsibilities and behaviours
*/

#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "GameEntity.h"

class Mushroom : public GameEntity
{
    
public:
    /**
	 * @brief Creates a Mushroom object.
	 */
    Mushroom();
    
    /**
	 * @brief Returns a shared pointer to the Sprite of the mushroom.
	 * @return Sprite : Shared pointer of type Sprite
	 */
    std::shared_ptr<sf::Sprite> shroom(){return shroom_->getSprite();}
    
    /**
	 * @brief Returns the number of lives of the Mushroom 
	 * @return Life_ : constant int.
	 */
    int getLife() const {return Life_;}
    
    /**
	 * @brief decreases the Life variable for a Mushroom object.
	 */
    void decreaseLife();
    
private:
    //object of GameEntity
    std::shared_ptr<GameEntity> shroom_;
    //life of mushroom
    int Life_;
    
    
};
#endif