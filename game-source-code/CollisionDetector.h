/**
 * @class CollisionDetector
 * @file CollisionDetector.h
 * @brief This class is responsible for detecting collision between entity objects in the game
 */


#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "GameEntity.h"

class CollisionDetector
{
        public:
     /**
      * @brief Default Constructor, initialize objects used in class
      */
    CollisionDetector();
  
   /**
    * @brief Copy constructor 
    */
    CollisionDetector(const CollisionDetector& obj);
    /**
     * @brief Function to detect collision between entities
     * @param _entity1, object 1 of entity type investigated
     * @param _entity2, object 2 of entity type investigated
     */
    bool isCollided(const std::shared_ptr<GameEntity> _entity1, const std::shared_ptr<GameEntity> _entity2);


    
};
#endif