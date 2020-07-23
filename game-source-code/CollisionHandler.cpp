#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
    
}

void CollisionHandler::PlayerHeadCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeHead)
{
    auto vec3 = centipedeHead->heads();
    for(unsigned int i = 0; i < vec3.size(); i++) {
        if(collision_.isCollided(vec3[i], playerShip->player1()) == true) {
            playerShip->ChangeLife();
            playerShip->initialisePlayer();
        }
    }
}

void CollisionHandler::PlayerBodyCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeBody)
{
    auto vec2 = centipedeBody->bodies();
    for(unsigned int i = 0; i < vec2.size(); i++) {
        if(collision_.isCollided(vec2[i], playerShip->player1()) == true) {
            playerShip->ChangeLife();
            playerShip->initialisePlayer();
        }
    }
}

void CollisionHandler::BulletHeadCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeBody,shared_ptr<Centipede>& centipedeHead,Score& ScoreCount)
{
    auto vec1 = playerShip->bullets();
    auto vec2 = centipedeBody->bodies();
    auto vec3 = centipedeHead->heads();
    // bullet collisions with Centipede head segments
    for(unsigned int i = 0; i < vec1.size(); i++) {
        for(unsigned int v = 0; v < vec3.size(); v++) {
            if(collision_.isCollided(vec1[i], vec3[v]) == true && vec2.size() != 0) {
                if(vec3[v]->getSprite()->getPosition().x - 15 == vec2[0]->getSprite()->getPosition().x) {
                    centipedeHead->deleteHead(v);
                    centipedeHead->CreateHead(
                    vec2[0]->getSprite()->getPosition().x, vec2[0]->getSprite()->getPosition().y);
                    centipedeBody->deleteBody(0);
                    ScoreCount.setScore();

                } else{
                    centipedeHead->deleteHead(v);
                ScoreCount.setScore();}
            }

            else if(collision_.isCollided(vec1[i], vec3[v]) == true && vec2.size() == 0) {
                centipedeHead->deleteHead(v);
                ScoreCount.setScore();
            }
        }
    }
}

void CollisionHandler::BulletBodyCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Centipede>& centipedeBody,shared_ptr<Centipede>& centipedeHead,shared_ptr<MushroomField>& field, Score& ScoreCount)
{
    auto vec1 = playerShip->bullets();
    auto vec2 = centipedeBody->bodies();
    auto vec3 = centipedeHead->heads();
     for (unsigned int i =0; i < vec1.size(); i++)
    {  
    // bullet collisions with body segments
    for(unsigned int x = 0; x < vec2.size(); x++) {

        if(collision_.isCollided(vec1[i], vec2[x]) == true && x != vec2.size() - 1) {
            centipedeBody->deleteBody(x);
            field->initialiseField(vec2[x]->getSprite()->getPosition().x, vec2[x]->getSprite()->getPosition().y);
            centipedeHead->CreateHead(
            vec2[x + 1]->getSprite()->getPosition().x, vec2[x + 1]->getSprite()->getPosition().y);
            centipedeBody->deleteBody(x + 1);
            playerShip->deleteBullets(i);
            ScoreCount.setScore();
        } else if(collision_.isCollided(vec1[i], vec2[x]) == true && x == vec2.size() - 1) {
            centipedeBody->deleteBody(x);
            field->initialiseField(vec2[x]->getSprite()->getPosition().x, vec2[x]->getSprite()->getPosition().y);
            playerShip->deleteBullets(i);
            ScoreCount.setScore();
        }
    }

 
}
}

void CollisionHandler::MushroomHeadCollision(shared_ptr<Centipede>& centipedeHead, shared_ptr<MushroomField>& field)
{
    auto vec3 = centipedeHead->heads();
    auto vec4 = field->getMushroomVector();
    // Mushroom collisions with centipede head segments
    for(unsigned int x = 0; x < vec4.size(); x++) {

        for(unsigned int i = 0; i < vec3.size(); i++) {

            if(collision_.isCollided(vec4[x], vec3[i]) == true) {
                if(vec3[i]->getHeadRight() == true) {

                    if(vec3[i]->getReverseDirection() == false) {
                        vec3[i]->TurnDown(vec3[i]);
                    } else
                        vec3[i]->ReverseDirection(vec3[i]);
                } else if(vec3[i]->getHeadLeft() == true) {

                    if(vec3[i]->getReverseDirection() == false) {
                        vec3[i]->TurnDown(vec3[i]);
                    } else
                        vec3[i]->ReverseDirection(vec3[i]);
                }
            }
        }
    }
}

void CollisionHandler::MushroomBodyCollisions(shared_ptr<Centipede>& centipedeBody, shared_ptr<MushroomField>& field,shared_ptr<CentipedeBody>& Body)
{
    auto vec2 = centipedeBody->bodies();
    auto vec4 = field->getMushroomVector();
     for(unsigned int x = 0; x < vec4.size(); x++) {
    // Mushroom collisions with centipede body Segments
    for(unsigned int i = 0; i < vec2.size(); i++) {
        if(collision_.isCollided(vec4[x], vec2[i]) == true) {
            if(Body->getHeadRight() == true) {
                if(vec2[i]->getReverseDirection() == false) {
                    vec2[i]->TurnDown(vec2[i]);
                }

                else
                    vec2[i]->ReverseDirection(vec2[i]);
            }

            if(Body->getHeadLeft() == true) {

                if(vec2[i]->getReverseDirection() == false) {
                    vec2[i]->TurnDown(vec2[i]);
                }

                else
                    vec2[i]->ReverseDirection(vec2[i]);
            }
        }
    }
}
}

void CollisionHandler::BulletMushroomCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<MushroomField>& field,Score& ScoreCount)
{
    auto vec1 = playerShip->bullets();
    auto vec4 = field->getMushroomVector();
    // bullets collision with mushrooms
    for(unsigned int x = 0; x < vec4.size(); x++) {
    for(unsigned int i = 0; i < vec1.size(); i++) {
        if(collision_.isCollided(vec4[x], vec1[i]) == true && vec4[x]->getLife() == 0) {
            field->deleteMushrooms(x);
            playerShip->deleteBullets(i);
            ScoreCount.setScore();

        } else if(collision_.isCollided(vec4[x], vec1[i]) == true && vec4[x]->getLife() != 0) {
            vec4[x]->decreaseLife();
            playerShip->deleteBullets(i);
            ScoreCount.setONScore();
        }
    }
}
}

void CollisionHandler::PlayerSpiderCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Spider>& spider)
{
    if(collision_.isCollided(playerShip->player1(),spider)==true)
 {
            playerShip->ChangeLife();
            playerShip->initialisePlayer();
           
 }
 
}

void CollisionHandler::BulletSpiderCollision(shared_ptr<PlayerShip>& playerShip, shared_ptr<Spider>& spider,Score& ScoreCount)
{
     auto vec1 = playerShip->bullets();
     for(unsigned int i = 0; i < vec1.size(); i++)
         {
             if(collision_.isCollided(spider, vec1[i]) == true) 
                 {	spider->getSprite()->setPosition(-40,228);
                     ScoreCount.setScore();
                 }
}
}

void CollisionHandler::SpiderMushroomCollision(shared_ptr<Spider>& spider,shared_ptr<MushroomField>& field)
{
    auto vec4 = field->getMushroomVector();
    for(unsigned int x = 0; x < vec4.size(); x++) 
        {
            if(collision_.isCollided(spider, vec4[x]) == true) 
            {
                field->deleteMushrooms(x);
            }
        }
    
}