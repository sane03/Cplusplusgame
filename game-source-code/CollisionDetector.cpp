 #include "CollisionDetector.h"
#include <iostream>
using namespace std;
CollisionDetector::CollisionDetector()
{}

CollisionDetector::CollisionDetector(const CollisionDetector& obj)
    {}

bool CollisionDetector::isCollided(const std::shared_ptr<GameEntity> _entity1, const std::shared_ptr<GameEntity> _entity2)
{
	
	
    sf::Vector2f Pos1 = _entity1->getSprite()->getPosition();
    sf::Vector2f Pos2 = _entity2->getSprite()->getPosition();
    return !((Pos1.y < Pos2.y - 8) || (Pos1.y - 8 > Pos2.y) || (Pos1.y == Pos2.y && Pos1.x > Pos2.x + 7)

        || (Pos1.y == Pos2.y && Pos1.x + 7 < Pos2.x) || (Pos1.x == Pos2.x && Pos1.y < Pos2.y - 8) ||
        (Pos1.x == Pos2.x && Pos1.y - 8 > Pos2.y) || (Pos1.x + 7 < Pos2.x) || (Pos1.x > Pos2.x + 7));

}

    