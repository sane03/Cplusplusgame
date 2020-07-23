/**
* @class Constants
* @brief The purpose of this class is to eliminate the use of magic numbers by providing
* all classes with standard game constants.
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "SFML/Graphics.hpp"

class Constants
{
public:
    /**
	 * @brief Creates a Constants object.
	 */
    Constants();
    
    /**
	 * @brief Returns the window dimensions of the game window.
	 * @return _windowDimensions : sf::Vector2f constant.
	 */
    const sf::Vector2f windowDimensions(){return windowDimensions_;}
    
    /**
	 * @brief Returns the position of the center of the window.
	 * @return _windowCenter : sf::Vector2f constant.
	 */

    const sf::Vector2f windowCenter(){return windowCenter_;}
    
private:
    //2D Window Dimensions.
	const sf::Vector2f windowDimensions_;
	//Position of window center.
	const sf::Vector2f windowCenter_;
    
};
#endif
