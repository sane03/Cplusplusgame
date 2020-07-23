/**
* @class PlayerShip
* @brief The purpose of this class is to create a game entity of type mushrrom 
* and create the corresponding responsibilities and behaviours
*/

#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "GameEntity.h"
#include "Bullet.h"
#include "Movable.h"

#include <iostream>

class PlayerShip : public GameEntity, public Movable
{
public:
        
        /**
        * @brief Creates a PlayerShip object.
        */
        PlayerShip();
        
        /**
        * @brief sets PlayerShip position when object is created
        */
        void initialisePlayer();
        
        /**
        * @brief Moves player Up
        */
        void moveUp() override;
        
        /**
        * @brief Moves player Down
        */
        void moveDown() override;
        
        
        /**
        * @brief Moves player Right
        */
        void moveRight() override;
        
        /**
        * @brief Moves player Leftt
        */
        void moveLeft() override;
        
        /**
        * @brief Creates and initialises Bullet object
        */
        void LoadBullet();
        
        
        /**
        * @brief checks if the bullet has reached beyond screen bounds
        * @param bullet : shared pointer of type bullet
        * @return bool : true off_screen , false if in_screen
        */
        bool Bullet_off_screen(const std::shared_ptr<Bullet> bullet);
        
        /**
        * @brief Returns the number of lives present
        * @return int : returns the int Life_ 
        */
        int getLife() const {return Life_;}
       
        /**
        * @brief Returns a sprite associated to player
        * @return Sprite : returns a shared pointer of type Sprite
        */
        std::shared_ptr<sf::Sprite> player(){return playerShip_->getSprite();}
        
        /**
        * @brief Returns an object of GameEntity
        * @return Shared_ptr : returns a GameEntity type pointer
        */
        std::shared_ptr<GameEntity> player1(){return playerShip_;}
        
        /**
        * @brief Returns the vector of bullets
        * @return Vector: return a vector of shared pointers of type bullet
        */
        std::vector<std::shared_ptr<Bullet> >bullets() {return bullets_;}
        
        /**
        * @brief Tracks player position to bind it with bullet creation 
        * @return Vector2f :returns 2D float positions of the player position
        */
        sf::Vector2f startPos(){return player()->getPosition();}
        
        /**
        * @brief deletes bullet indexed by the int parameter passed in the function
        * @param x : int index
        */
		void deleteBullets(int x);
        
        /**
        * @brief decreases the life of the player
        */
		void ChangeLife(){ Life_ -= 1;};
        
private:
        
        //object of GameEntity
        std::shared_ptr<GameEntity> playerShip_;
        //sets the player speed for the game
        int playerspeed_;
        //life of the player
		int Life_;
        //2D position shared pointer
        std::shared_ptr<sf::Vector2f> startPos_;
        //vector of bullets
        std::vector<std::shared_ptr<Bullet> >bullets_;
		
    
};

//PlayerShip::Life=4;

#endif