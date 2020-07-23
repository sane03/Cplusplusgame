/**
* @class Spider
* @brief The purpose of this class is to create a game entity of type Spider 
* and create the corresponding responsibilities and behaviours
*/
#ifndef SPIDER_H
#define SPIDER_H

#include "GameEntity.h"
#include "Movable.h"

#include <iostream>

class Spider : public GameEntity,public Movable
{
public:
		void  SetBoolUp(bool k){up_=k;}
		void  SetBoolDown(bool k){down_=k;}
        /**
        * @brief Creates spider object and initialises its behaviors
        */
        Spider();
        /**
        * @brief Moves the Spider up
        */
        void moveUp() override;
        
        /**
        * @brief Moves the Spider down
        */
        void moveDown() override;
        /**
        * @brief Moves the Spider right
        */
        void moveRight() override;
        
        /**
        * @brief Moves the Spider left
        */
        void moveLeft() override;
        
        /**
        * @brief Decides which movement to call for Spider
        */
        void Movespider();
        
        /**
        * @brief Returns the Spider Life_
        * @return Life : const integer
        */
        int getLife() const {return Life_;}
        
        /**
        * @brief Returns the boolean to decide use the Down direction 
        * @return down_ : const boolean
        */
        bool getDown() const {return down_;}
        /**
        * @brief Returns the boolean to decide use the Up direction 
        * @return up_ : const boolean
        */
        bool getUp() const {return up_;}
        
        /**
        * @brief Returns the sprite associated to Spider
        * @return Sprite : shared pointer
        */
        std::shared_ptr<sf::Sprite> spider(){return spider_->getSprite();}
        
       /**
        * @brief Returns the GameEntity accessor object
        * @return Spider_ : GameEntity object
        */
        std::shared_ptr<GameEntity> spider1(){return spider_;}
        
private:
        
        //accessor object
        std::shared_ptr<GameEntity> spider_;
        //Spider speed
        int spiderspeed_;
        //spider life
		int Life_;
        //up direction boolean
        bool up_;
        //down direction boolean
        bool down_;
    
};


#endif