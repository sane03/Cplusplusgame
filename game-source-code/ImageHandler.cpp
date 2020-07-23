#include "ImageHandler.h"

ImageHandler::ImageHandler(const std::string& filename):
texture_{std::make_shared<sf::Texture>()},
sprite_{std::make_shared<sf::Sprite>()},
filename_{filename}
{}

std::shared_ptr<sf::Sprite> ImageHandler::setImage()
{
    if(!texture_->loadFromFile(filename_))
        throw ImageNotFound();
    else{
        sprite_->setTexture(*texture_);
        return  sprite_;
    }
}