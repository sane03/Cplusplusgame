#include "Game.h"

Game::Game():
display{std::make_shared<Score>()},
window_{sf::VideoMode(constants_.windowDimensions().x,constants_.windowDimensions().y),"Centipede"},
process_{std::make_shared<GameProcess>()}
{}


void Game::run()
{
    
    while(window_.isOpen())    
    {   
        window_.setFramerateLimit(35);
        processEvents_();
        render_();
    }
}

void Game::processEvents_()
{
    sf::Event event;
    while(window_.pollEvent(event))
    {
        switch(event.type)
        {
            
            case sf::Event::Closed:
            window_.close();
            break;
            
            
            case sf::Event::KeyPressed:
            processKeys(event.key.code);
            break;
            
            default:
            break;
        }
        
    }
}

void Game::processKeys(sf::Keyboard::Key key)
{
    switch(key)
    {
        
        case sf::Keyboard::Space:
        process_->setGameState(GameState::GamePlay);
        break;
        
        case sf::Keyboard::Escape:
        window_.close();
        break;
        
        default:
        break;
    }
    
    //Makes sure no gameplay inputs are processed during SplashScreen State
    
    if (process_->currentState() == GameState::GamePlay)
    {
        switch(key)
        {
       
        case sf::Keyboard::S:
        process_->receiveInput(Action::SHOOT);
        break;
        
        case sf::Keyboard::Up:
        process_->receiveInput(Action::UP);
        break;
        
        case sf::Keyboard::Down:
        process_->receiveInput(Action::DOWN);
        break;
        
        case sf::Keyboard::Left:
        process_->receiveInput(Action::LEFT);
        break;
        
        case sf::Keyboard::Right:
        process_->receiveInput(Action::RIGHT);
        break;
        
        default:
        break;
            
        }
        
    }
    
}

void Game::render_()
{
    window_.clear();
    switch(process_->currentState())
    {
        case GameState::SplashScreen:
        displaySplash();
        break;
        
        case GameState::GamePlay:
        {
        process_->GameLoop();
        gameBackground();
        break;
        }
        
        case GameState::GameWin:
        displayWin();
        break;
        
        case GameState::GameOver:
        displayLose();
        break;
        
        default:
        break;
        
    }
}

void Game::displaySplash()
{
    
    window_.draw(*(process_->background()->splashScreen()));
    window_.display();
    
}

void Game::displayWin()
{
    
    window_.draw(*(process_->background()->gameWin()));
    window_.display();
    
}

void Game::displayLose()
{
    
    window_.draw(*(process_->background()->gameOver()));
    window_.display();
    
}


void Game::gameBackground()
{
    window_.draw(*(process_->background()->gameScreen()));
    window_.draw(*(process_->playerShip()->player()));
    window_.draw(*(process_->spider()->getSprite()));
	
    window_.draw(process_->getText());

    
    for (const auto& x : process_->centipedeHead()->heads())
    {
        window_.draw(*(x->getSprite()));
    }
    for (const auto& x : process_->centipedeBody()->bodies())
    {
        window_.draw(*(x->getSprite()));
    }
    
     for (const auto& x : process_->FieldObj()->getMushroomVector())
    {
        window_.draw(*(x->getSprite()));
    }
    
    if(process_->bulletObj()->getState() == true)
    {   
    
        for (const auto& x : process_->playerShip()->bullets())
    {
            window_.draw(*(x->getSprite()));
    }
         
    }
    
    
    window_.display();
}