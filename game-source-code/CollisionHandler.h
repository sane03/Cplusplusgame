/**
* @class CollisionHandler
* @brief The purpose of this class is to resolve the collision decisions that occur during gameplay
*/

#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include "PlayerShip.h"
#include "Centipede.h"
#include "Bullet.h"
#include "Spider.h"
#include "CollisionDetector.h"
#include "Score.h"
#include "MushroomField.h"

 
class CollisionHandler
{
     
public:

 CollisionHandler();
 
 /**
 * @brief Resolves the collision of the player and centipede head
 * @param playerShip : shared pointer of type playerShip,
 * @param centipedeHead :  shared pointer of type centipede
 */
 void PlayerHeadCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeHead);
 /**
 * @brief Resolves the collision of the player and centipede body
 * @param playerShip : shared pointer of type playerShip,
 * @param centipedeHead :  shared pointer of type centipede
 */
 void PlayerBodyCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeBody);
 /**
 * @brief Resolves the collision of the bullet and centipede head , and increases score
 * @param playerShip : shared pointer of type playerShip,
 * @param centipedeHead :  shared pointer of type centipede
 * @param ScoreCount : int
 */
 void BulletHeadCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeBody,shared_ptr<Centipede>& centipedeHead,Score&);
 
 /**
 * @brief Resolves the collision of the bullet and centipede body,creates mushroom
 * at collision position, next segment becomes head and increases score
 * @param playerShip : shared pointer of type playerShip,
 * @param centipedeBody :  shared pointer of type centipede
 * @param centipedeHead :  shared pointer of type centipede
 * @param field_ : shared pointer of type MushroomField
 * @param ScoreCount : int
 */
 void BulletBodyCollision(shared_ptr<PlayerShip>& playership_,shared_ptr<Centipede>& centipedeBody,shared_ptr<Centipede>& centipedeHead, shared_ptr<MushroomField>& field_, Score&);
 /**
 * @brief Resolves the collision of the mushroom and centipede head
 * @param field : shared pointer of type MushroomField,
 * @param centipedeHead :  shared pointer of type centipede
 */
 void MushroomHeadCollision(shared_ptr<Centipede>& centipedeHead, shared_ptr<MushroomField>& field);
 /**
 * @brief Resolves the collision of the mushroom and centipede body
 * @param field : shared pointer of type MushroomField,
 * @param centipedeHead :  shared pointer of type centipede
 * @param Body : shared pointer of type centipedeBody
 */
 void MushroomBodyCollisions(shared_ptr<Centipede>& centipedeBody, shared_ptr<MushroomField>& field,shared_ptr<CentipedeBody>& Body );
  /**
 * @brief Resolves the collision of the mushroom and bullet, and increases score
 * @param playerShip : shared pointer of type playerShip,
 * @param field : shared pointer of type MushroomField,
 * @param ScoreCount : int
 */
 void BulletMushroomCollision(shared_ptr<PlayerShip>& playership_, shared_ptr<MushroomField>& field_,Score&);
  /**
 * @brief Resolves the collision of the player and Spider
 * @param playerShip : shared pointer of type playerShip,
 * @param spider : shared pointer of type Spider,
 */
 void PlayerSpiderCollision(shared_ptr<PlayerShip>& playership_, shared_ptr<Spider>& spider);
  /**
 * @brief Resolves the collision of the Spider and bullet, and increases score
 * @param playerShip : shared pointer of type playerShip,
 * @param spider : shared pointer of Spider,
 * @param ScoreCount : int
 */
 void BulletSpiderCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Spider>& spider,Score& ScoreCount);
  /**
 * @brief Resolves the collision of the mushroom and spider, and occasionally deletes the mushroom
 * @param spider : shared pointer of type Spider,
 * @param field : shared pointer of type MushroomField,
 */
 void SpiderMushroomCollision(shared_ptr<Spider>& spider,shared_ptr<MushroomField>& field);

private:

    //accessor to Collision Detector
    CollisionDetector collision_;
    
 
 };
 #endif