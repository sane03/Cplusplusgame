/**
* @class Bullet
* @brief The purpose of this class is to create a game entity of type bullet 
* and create the corresponding responsibilities and behaviours
*/

#ifndef BULLET_H
#define BULLET_H
#include <memory>
#include <vector>
#include "GameEntity.h"
#include <iostream>

class Bullet :public GameEntity
{
    
public:
    
    /**
    * @brief Creates bullet object and initialises its behaviors
    */
    Bullet();
    
    /**
    * @brief Checks if bullet has been activated
    * @param bullet : shared pointer of type bullet
    */
    void MoveBullet(std::shared_ptr<Bullet> bullet);
    /**
    * @brief Moves bullet up
    * @param bullet : shared pointer of type bullet
    */
    void incrementBullet(std::shared_ptr<Bullet> bullet);
    
    /**
    * @brief Sets initial bullet position to player position
    * @param Pos : Vector2f type with coordinates
    */
    void Position(sf::Vector2f pos){PlayerPosition_ = pos;}
    /**
    * @brief Sets the state of the bullet
    * @param state : bool
    */
    void setStates(bool state){state_ = state;}
    
    /**
    * @brief Returns a Sprite associated to bullet
    * @return Sprite : shared pointer of type Sprite
    */
    std::shared_ptr<sf::Sprite> bullet(){return Bullet_->getSprite();}
   
   /**
    * @brief Returns the state of the bullet
    * @return state_ : bool
    */
    bool getState() {return state_;}
   

    
    
private:
    //2D position
    sf::Vector2f PlayerPosition_;
    //accessor to GameEntity
    std::shared_ptr<GameEntity> Bullet_;
    //speed of bullet
    int bulletspeed_;
    //state of bullet
    bool state_;
    
    
    
    
    
};
#endif