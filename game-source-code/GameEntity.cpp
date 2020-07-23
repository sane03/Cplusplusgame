#include "GameEntity.h"

GameEntity::GameEntity(const std::string& filename):
state_{false},
imageHandler_(std::make_shared<ImageHandler> (filename)),
entitySprite_(std::make_shared<sf::Sprite>()),
constants_(std::make_shared<Constants>())
{
    
    entitySprite_ = imageHandler_->setImage();
    entitySprite_->setOrigin(entitySprite_->getLocalBounds().width/2, entitySprite_->getLocalBounds().height/2);
  

}
