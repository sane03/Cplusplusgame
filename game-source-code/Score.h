/**
* @class Score
* @brief The purpose of this class is to calculate the score accumulated in the game
*/

#ifndef SCORE_H
#define SCORE_H
#include <fstream>
#include <string>
#include "Constants.h"

#include <memory>

using namespace std;

class Score
{
	
	
public:

    /**
	 * @brief Creates score object and initialises score
	 */
	Score();

    /**
	 * @brief Reads high score from the score file
	 */
	int readHighScore();
    
    /**
	 * @brief Writes high score to the file 
	 */
	void storeHighScore(){ofstream myfile;myfile.open ("score.txt");myfile << points(); myfile.close();}
	
    /**
	 * @brief Returns the highscore  
	 * @return HighScore : int.
	 */
	int getHighScore(){return HighScore;}
    
    /**
	 * @brief Returns the score accumulated in the game 
	 */
	void setScore(){score=score+15;}
    
    /**
	 * @brief Adds 1 to the score in the game 
	 */
	void setONScore(){score=score+1;}
    
    /**
	 * @brief Returns the score accumulated in the game 
	 * @return score : constant int.
	 */
	int getScore() const {return score;}
    
    /**
	 * @brief Returns the highest score accumulated in the game 
	 * @return int : score if its the highest accumulated, HighScore set default
	 */
	int points(){if(getScore()>=getHighScore())return getScore(); else return getHighScore(); };
    
    
private:
    //game score
	int score;
    //game high score
	int HighScore;
    
};

#endif
