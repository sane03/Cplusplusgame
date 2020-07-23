/**
* @class Movable 
* @brief This is an Abstract Base Class that models movement of of entities
*/

#ifndef MOVABLE_H
#define MOVABLE_H
#include "Constants.h"
#include "Coordinates.h"

class Movable
{
public:

    /**
    * @brief default constructor
    */
    Movable();
    
    /**
    * @brief Virtual function to model move Up
    */
    virtual void  moveUp() = 0;
    /**
    * @brief Virtual function to model move Down
    */
    virtual void  moveDown() = 0;
    /**
    * @brief Virtual function to model move Left
    */
    virtual void  moveLeft() = 0;
    /**
    * @brief MVirtual function to model move Right
    */
    virtual void  moveRight() = 0;
   
    
};
#endif