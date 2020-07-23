/**
* @class ImageHandler
* @brief The purpose of this class is load all game entity images and create the corresponding
* game entity sprites.
*/


#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H
#include "SFML/Graphics.hpp"
#include <memory>
#include <vector>
#include <string>

//exceptions

class ImageNotFound{};

class ImageHandler
{
public:
    /**
	 * @brief Creates an ImageHandler object.
	 * @param filename : string constant.
	 */
	ImageHandler(const std::string& filename_);
	
	/**
	 * @brief Loads image and sets the corresponding texture and sprite.
	 * @return _sprite : Shared pointer to the load game entity sprite.
	 */
	std::shared_ptr<sf::Sprite> setImage();

private:
	//Texture used for image loading.
	std::shared_ptr<sf::Texture> texture_;
	//Sprite used for texture setting.
	std::shared_ptr<sf::Sprite> sprite_;
	//Filename used as a reference for image loading.
	const std::string filename_;

    
};

#endif
    
    
    
    
    