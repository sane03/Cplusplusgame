/**
* @class Centipede
* @brief The purpose of this class is to create a game entity of type centipedeHead 
* and create the corresponding responsibilities and behaviours
*/
#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include "GameEntity.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include <list>

class Centipede : public GameEntity
{
public:
    /**
	 * @brief Creates a CentipedeHead object.
	 */
    Centipede();
    
    /**
	 * @brief Returns the Sprite to centipede head 
	 * @return Sprite : shared pointer of type Sprite
	 */
    std::shared_ptr<sf::Sprite> _centipedeHead(){return centipedeHead_->getSprite();}
    /**
	 * @brief Returns the Sprite to centipede body 
	 * @return Sprite : shared pointer of type Sprite
	 */
    std::shared_ptr<sf::Sprite> _centipedeBody(){return centipedeBody_->getSprite();}

    /**
	 * @brief Returns the Vector of centipede head segments
	 * @return Vector : shared pointer of type CentipedeHead
	 */
    std::vector<std::shared_ptr<CentipedeHead> >heads() {return Heads;}
    /**
	 * @brief Returns the Vector of centipede body segments
	 * @return Vector : shared pointer of type CentipedeBody
	 */
    std::vector<std::shared_ptr<CentipedeBody> >bodies() {return Bodys;}
    
    /**
	 * @brief Creates centipede segments and assigns positions
	 */
    void createCentipede(); 
    /**
	 * @brief deletes body segments at the position passed by parameter
     * @param x : vector int index
	 */
    void deleteBody(int x);
    /**
	 * @brief deletes head segments at the position passed by parameter
     * @param x : vector int index
	 */
    void deleteHead(int x);
    
    /**
	 * @brief creates a new head segment with position x,y passed into function
     * @param x : int position to set position
     * @param y : int position to set position
	 */
    void CreateHead(int x, int y);
    

    
    
private:
    //GameEntity accessor for head segment
    std::shared_ptr<GameEntity> centipedeHead_;
    //GameEntity accessor for body segment
    std::shared_ptr<GameEntity> centipedeBody_;
    //accessor to Centipede Head
    std::vector<std::shared_ptr<CentipedeHead> > Heads;
    //accessor to CentipedeBody
    std::vector<std::shared_ptr<CentipedeBody> > Bodys;
    
    
};
#endif