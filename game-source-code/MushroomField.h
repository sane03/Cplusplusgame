/**
* @class MushroomField
* @brief The purpose of this class is to create a collection of type mushroom 
* and allocates random positions to them for display
*/


#ifndef MUSHROOMFIELD_H
#define MUSHROOMFIELD_H

#include <cstdlib>
#include <ctime>
#include "Mushroom.h"

class MushroomField 
{
    
public:
    /**
	 * @brief Generates a field randomly placed mushrooms
	 */
	MushroomField(long double  );
    MushroomField();
    
       /**
	 * @brief Sets the 2D locations of each mushroom
	 * @param x : int to set the x parameter of the mushroom 
     * @param y : int to set the y parameter of the mushroom
	 */
    void initialiseField(int x, int y);
    
       /**
	 * @brief Generates random x,y numbers within the specified range
	 */
    void randomCoordinateGenerator();
    
       /**
	 * @brief Creates the initial randomly placed mushroom
	 */
    void init(long double);
	
    
    /**
	 * @brief Checks if the 2D locations of each mushroom is in the same position
	 * @param x : int to check the x parameter of the mushroom 
     * @param y : int to check the y parameter of the mushroom
	 */
    void Check(int x, int y);
    
       /**
	 * @brief Deletes a mushroom at the location passed as the argument 
     * from the mushroom vector
	 * @param x : int.
	 */
    void deleteMushrooms(int x);
    
    /**
	 * @brief Returns the vector of mushrooms created
	 * @return Mushrooms : vector of shared pointers of type Mushroom.
	 */
     std::vector<std::shared_ptr<Mushroom> >getMushroomVector(){return Mushrooms;}
    
    
private:
    //vector of Type mushroom that stores the collection of  Mushrooms
    std::vector<std::shared_ptr<Mushroom> > Mushrooms;
   
    
    
};
#endif