/**
 * @class Game
 * @brief Game Class: This class forms part of the presentation layer. The purpose of this class
 * is to receive all key inputs and supply them to the domain for processing. This class is also
 * responsible displaying all game objects.
*/

#ifndef GAME_H
#define GAME_H

#include "GameProcess.h"
#include "Constants.h"

#include <iostream>
using namespace std;

//Exceptions
class SplashScreenNotFound{};
class GameBackgroundNotFound{};


class Game {
    
public:

    /**
	 * @brief Creates a Game object which creates a valid window and a game process object.
	 
	 */

    Game();
    
    /**
	 * @brief Starts the game loop. As long as the window is open the game loop will run.
	 */
    void run();
    

    
private:
    
    // Score object linking the presentation layer and the domain layer to access the score.
    std::shared_ptr<Score> display;
    // Constants object used to access game constants such as window dimensions.
	Constants constants_;
	// RenderWindow object responsible for creating the game window and drawing game objects.
	sf::RenderWindow window_;
	//GameProcess object linking the presentation layer and the domain layer.
	std::shared_ptr<GameProcess> process_;
    
    /**
	 * @brief Receives updated game entitity states and draws them and the background.
	 */
     void gameBackground();
	/**
	 * @brief Processes relevant events.
	 */
	void processEvents_();
	
	/**
	 * @brief Receives key relevant key input from user and supplies it.
	 * to the domain layer for processing.
	 * @param Key code of pressed key.
	 */
	void processKeys(sf::Keyboard::Key);
	
	/**
	 * @brief Determines what is drawn on the screen depending on the state of the game.
	 */
	void render_();
	
	/**
	 * @brief Draws the splash screen.
	 */
	void displaySplash();
	
	/**
	 * @brief Draws "You Win" once game has been won.
	 */
	void displayWin();
	
	/**
	 * @brief Draws "You Lose" once game has been lost.
	 */
	void displayLose();
	


};
#endif