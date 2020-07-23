/**
* @class CentipedeHead
* @brief The purpose of this class is to create a game entity of type centipedeHead 
* and create the corresponding responsibilities and behaviours
*/

#ifndef CENTIPEDEHEAD_H
#define CENTIPEDEHEAD_H

#include "GameEntity.h"


class CentipedeHead : public GameEntity
{
public:
    /**
	 * @brief Creates a CentipedeHead object.
	 */
    CentipedeHead();
    
    /**
	 * @brief Returns the right direction decision flag
	 * @return right_ : constant bool.
	 */
    bool getHeadRight() const{return right_;}
    
    /**
	 * @brief  Returns the left direction decision flag
	 * @return left_ : constant bool
	 */
    bool getHeadLeft() const{return left_;}
    
    /**
	 * @brief  Sets the right_ decision flag
	 * @param right : constant bool
	 */
    void setHeadRight(const bool& right){right_ = right;}
    
    /**
	 * @brief Returns the reverse direction boolean flag 
	 * @return UpReverse_ : constant bool.
	 */
    bool getReverseDirection() const {return UpReverse_;}
    
     /**
	 * @brief  Sets the UpReverse_ decision flag
	 * @param UpReverse : constant bool
	 */
    void setReverseDirection(const bool& UpReverse){UpReverse_ = UpReverse;}
    
     /**
	 * @brief  Reverses the centipede direction
	 * @param Centi : shared pointer of type CentipedeHead
	 */
    void ReverseDirection(std::shared_ptr<CentipedeHead>& Centi);
    
    /**
	 * @brief  Sets the left_ direction decision flag
	 * @param left : constant bool
	 */
    void setHeadLeft(const bool& left){left_ = left;}
    
    /**
	 * @brief  Decides the direction the centipede moves
	 * @param Centi : shared pointer of type CentipedeHead
	 */
    void getDirection(std::shared_ptr<CentipedeHead>& Centi);
    /**
	 * @brief Moves the centipede Right
	 * @param Centi : shared pointer of type CentipedeHead
	 */
    void moveCentipedeRight(std::shared_ptr<CentipedeHead>& Centi);
    /**
	 * @brief  Moves Centipede left
	 * @param Centi : shared pointer of type CentipedeHead
	 */
    void moveCentipedeLeft(std::shared_ptr<CentipedeHead>& Centi);
    
    /**
	 * @brief Returns the Sprite to centipede head 
	 * @return Sprite : shared pointer of type Sprite
	 */
    std::shared_ptr<sf::Sprite> Head() {return Head_->getSprite();}
    
    /**
	 * @brief  Turns the centipede down
	 * @param Centi : shared pointer of type CentipedeHead
	 */
    void TurnDown(std::shared_ptr<CentipedeHead>& Centi);

private:
    //gameentity accessor
    std::shared_ptr<GameEntity> Head_;
    //right direction flag
    bool right_;
    //left direction flag
    bool left_;
    //reverse direction flag
    bool UpReverse_;
};
#endif