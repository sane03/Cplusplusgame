/**
* @class CentipedeBody
* @brief The purpose of this class is to create a game entity of type centipedeBody 
* and create the corresponding responsibilities and behaviours
*/

#ifndef CENTIPEDEBODY_H
#define CENTIPEDEBODY_H

#include "GameEntity.h"



class CentipedeBody : public GameEntity
{

public:
    /**
	 * @brief Creates a CentipedeBody object.
	 */
    CentipedeBody();
    
    /**
	 * @brief Returns the right direction decision flag
	 * @return right_ : constant bool.
	 */
    bool getHeadRight() const {return right_;}
    /**
	 * @brief  Returns the left direction decision flag
	 * @return left_ : constant bool
	 */
    bool getHeadLeft() const {return left_;}
    
    /**
	 * @brief Returns the reverse direction boolean flag 
	 * @return UpReverse_ : constant bool.
	 */
    bool getReverseDirection() const{return UpReverse_;}
    
    /**
	 * @brief  Sets the right_ decision flag
	 * @param right : constant bool
	 */
    void setHeadRight(const bool& right){right_ = right;}
    
    /**
	 * @brief  Sets the UpReverse_ decision flag
	 * @param UpReverse : constant bool
	 */
    void setReverseDirection(const bool& UpReverse){UpReverse_ = UpReverse;}
    
    /**
	 * @brief  Sets the left_ direction decision flag
	 * @param left : constant bool
	 */
    void setHeadLeft(const bool& left){left_ = left;}
    
    /**
	 * @brief  Decides the direction the centipede moves
	 * @param Centi : shared pointer of type CentipedeBody
	 */
    void getDirection(std::shared_ptr<CentipedeBody>&);
    
    /**
	 * @brief Moves the centipede Right
	 * @param Centi : shared pointer of type CentipedeBody
	 */
    void moveCentipedeRight(std::shared_ptr<CentipedeBody>&);
    
    /**
	 * @brief  Moves Centipede left
	 * @param Centi : shared pointer of type CentipedeBody
	 */
    void moveCentipedeLeft(std::shared_ptr<CentipedeBody>&);
    
    /**
	 * @brief Returns the Sprite to centipede head 
	 * @return Sprite : shared pointer of type Sprite
	 */
    std::shared_ptr<sf::Sprite> Body(){return Body_->getSprite();}
    
   // void RightTurnDown(std::shared_ptr<CentipedeBody>&Centi );
    
    //void LeftTurnDown(std::shared_ptr<CentipedeBody>&Centi);
    /**
	 * @brief  Turns the centipede down
	 * @param Centi : shared pointer of type CentipedeBody
	 */
    void TurnDown(std::shared_ptr<CentipedeBody>&Centi);
    /**
	 * @brief  Reverses the centipede direction
	 * @param Centi : shared pointer of type CentipedeBody
	 */
    void ReverseDirection(std::shared_ptr<CentipedeBody>& Centi);

private:
    std::shared_ptr<GameEntity> Body_;
    bool right_;
    bool left_;
    bool UpReverse_;
};
#endif