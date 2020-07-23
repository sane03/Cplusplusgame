/**
 * @class GameProcess
 * @brief GameProcess: This class forms part of the domain layer. The purpose of this class
 * is to create all game entities, receive and process key inputs from the presentation layer,
 * carry out game sequences and algorithms and provide the presentation layer with game state updates.
 * This class is basically the core of the whole game design.
*/

#ifndef GAMEPROCESS_H
#define GAMEPROCESS_H
#include "Score.h"
#include "BackgroundsHandler.h"
#include "PlayerShip.h"
#include "Centipede.h"
#include "Bullet.h"
#include "CollisionDetector.h"
#include "CollisionHandler.h"
#include "MushroomField.h"
#include "Spider.h"
#include <vector>

//Exception
class FontNotFound{};

enum class GameState{
    
    SplashScreen = 1,
    GamePlay,
    GamePause,
    GameWin,
    GameOver
};

enum class Action{
    
    RIGHT = 1,
    LEFT,
    UP,
    DOWN,
    SHOOT
    
};

class GameProcess
{
    
public:
    /**
	 * @brief All game entity objects are created when a GameProcess object is created.
	 */
    GameProcess();
    
    /**
	 * @brief deletes the bullets when the go beyond screen bounds
	 */
    void OffscreenObjectHandler_();
    
    /**
	 * @brief Returns the BackgroundsHandler object accessor
	 */
    std::shared_ptr<BackgroundsHandler> background() {return background_;}
    
      /**
	 * @brief Returns the enum Type  accessor of GameState
	 */
    GameState currentState() {return gameState_;}
    
    /**
	 * @brief sets the gamestate of the game
     * @param State : enum Type GameState 
	 */
    void setGameState(GameState state) {gameState_ = state;}
    
    /**
	 * @brief checks if the entities are dead and sets the gamestate
	 */
    void gameState();
     
     /**
	 * @brief returns the clock_ object
     * @return clock_ : sf::Clock
	 */
    std::shared_ptr<sf::Clock> clock() {return clock_;}
    /**
	 * @brief returns the playerShip_ object
     * @return clock_ : shared pointer of type playerShip_
	 */
    std::shared_ptr<PlayerShip> playerShip() {return playerShip_;}
    /**
	 * @brief returns the centipedeBody_ object
     * @return centipedeBody_ : shared pointer of type cenetipedeBody_
	 */
    std::shared_ptr<Centipede> centipedeBody() {return centipedeBody_;}
    /**
	 *@brief returns the centipedeHead_ object
     *@return centipedeHead_ : shared pointer of type centipedeHead_
	 */
    std::shared_ptr<Centipede> centipedeHead() {return centipedeHead_;}
   /**
	 * @brief returns the hids_ object
     * @return hids_ : shared pointer of type hids_
	 */
    std::shared_ptr<CentipedeHead> hids() {return hids_;}
    /**
	 * @brief returns the Bods_ object
     * @return Bods_ : shared pointer of type Bods_
	 */
    std::shared_ptr<CentipedeBody> bods() {return Bods_;}
    /**
	 * @brief returns the bullet_ object
     * @return bullet_ : shared pointer of type bullet_
	 */
    std::shared_ptr<Bullet> bulletObj() {return bullet_;}
    /**
	 * @brief returns the mushroom_ object
     * @return mushroom_ : shared pointer of type Mushroom
	 */
    std::shared_ptr<Mushroom> MushroomObj() {return mushroom_;}
    /**
	 * @brief returns the spider_ object
     * @return field_ : shared pointer of type MushroomField
	 */
    std::shared_ptr<MushroomField> FieldObj() {return field_;}
    /**
	 * @brief returns the spider_ object
     * @return field_ : shared pointer of type MushroomField
	 */
    std::shared_ptr<Spider> spider() {return spider_;}
    
    /**
	 * @brief evaluates the input received
     * @param direction : enum Type for direction
	 */
    void receiveInput(Action direction);
    /**
	 * @brief Evaluates the actions of the keyboard input to player
     * @param direction : enum Type for direction
	 */
    void move(const Action& direction);
    /**
	 * @brief updates the game entity states 
	 */
    void GameLoop();
    /**
	 * @brief sets the text fonts and colors 
	 */
    void setText();
    /**
	 * @brief sets the score and lives to texts
	 */
    void createText (int,int );
    /**
	 * @brief sets the score and lives to texts
     * @return text : const sf::Text type
	 */
    sf::Text getText() const{return text;}
    
    
private:
    //score accessor object
    Score ScoreCount;
    //collisionHandler accessor object
    std::shared_ptr<CollisionHandler> collisions;
    //BacksgroundsHandler accessor object
    std::shared_ptr<BackgroundsHandler> background_;
    //playerShip accessor object
    std::shared_ptr<PlayerShip> playerShip_;
    //centipede accessor object
    std::shared_ptr<Centipede> centipedeBody_;
    //centipede accessor object
    std::shared_ptr<Centipede> centipedeHead_;
     //Bullet accessor object
    std::shared_ptr<Bullet> bullet_;
    //centipedeHead accessor object
    std::shared_ptr<CentipedeHead> hids_;
    //centipedeBody accessor object
    std::shared_ptr<CentipedeBody> Bods_;
     //Mushroom accessor object
    std::shared_ptr<Mushroom> mushroom_;
     //MushroomField accessor object
    std::shared_ptr<MushroomField> field_;
     //Spider accessor object
    std::shared_ptr<Spider> spider_;
    //time delay 
    const sf::Time delay_;
    //GameState object
    GameState gameState_;
    //clock timer
    sf::Clock timer_;
    //clock timer2
    sf::Clock timer2_;
    
    std::shared_ptr<sf::Clock> clock_;
    
    const sf::Time period_;
    //collision detector accessor object
    CollisionDetector collision_;
    //font object
    sf::Font font;
    //text object
    sf::Text text;
    //resolves the game states
    void stateHandler_();
    //checks the collisions 
    void collisionHandler_();

};
#endif

