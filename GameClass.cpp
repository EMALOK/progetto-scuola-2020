#include "headers/GameClass.hpp"
#include "headers/GameUtils.hpp"
#include <math.h>
#include <iostream> //debug 

#define K_DEC 4.f //costante di decelerazione
#define A_SPEED 450 //accelerazione orizzontale
#define PLAYER_MAX_VH 400 //velocita orizzontale massima del player
#define GRAVITY 900 //gravità
#define INITIAL_JUMP_V -1000 //velocità iniziale del salto
#define WINDOW_WIDTH 1400 //larghezza della finestra
#define WINDOW_HEIGHT 900 //altezza della finestra
#define CAMERA_TRIGGER_X 500 //movimento necessario per far muovere la camera lungo l'asse x
#define CAMERA_TRIGGER_Y 200 //movimento necessario per far muovere la camera lungo l'asse y

//Funzioni

//Update

void Game::update(sf::Time delta_time)
{
    pollEvents();


    //se il delta time supera il mezzo secondo molto probabilmente significa che l'utente non aveva la finestra in focus
    //quindi, reset del delta time per dare un effetto di pausa
    if (delta_time.asSeconds() >= 0.4f)
        delta_time = sf::seconds(0);

    //  Gravità
    if (abs(player->getAcceleration().y) <= 0.1f)
        player->setAcceleration(sf::Vector2f(player->getAcceleration().x, GRAVITY));

    /*  CONTROLLO TASTI MOVIMENTO   */

    bool left_control = false;
    bool right_control = false;
    bool jump_control = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        left_control = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        right_control = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        jump_control = true;

    //destra
    if (right_control)
    {
        player->setAcceleration(sf::Vector2f(A_SPEED, player->getAcceleration().y));
    }
    else if (!left_control) //se destra e sinistra non sono premuti
    {
        player->setAcceleration(sf::Vector2f(0, player->getAcceleration().y)); //impostiamo l'accelerazione a 0
    }
    
    //sinistra
    if (left_control)
    {
        player->setAcceleration(sf::Vector2f(-A_SPEED, player->getAcceleration().y));
    }
    else if (!right_control) //se destra e sinistra non sono premuti
    {
        player->setAcceleration(sf::Vector2f(0, player->getAcceleration().y)); //impostiamo l'accelerazione a 0
    }

    //salto
    if (jump_control)
    {
        //controllo se è possibile saltare
        if (player->getSpeed().y == 0) {
            player->setSpeed(sf::Vector2f(player->getSpeed().x, INITIAL_JUMP_V)); //salto
        }
    }

    /*  FISICA  */
    
    //  DEBUG
    /*std::cout << "acc.x " << player->getAcceleration().x << " ";
    std::cout << "acc.y " << player->getAcceleration().y << " ";
    std::cout << "vel.x " << player->getSpeed().x << " ";
    std::cout << "vel.y " << player->getSpeed().y << "\n";*/

    //  Decelerazioni per attrito
    //quando l'accelerazione è uguale a 0 -> applica attrito
    if (player->getAcceleration().x == 0 || GameUtils::discordi(player->getAcceleration().x, player->getSpeed().x))
        player->setSpeed(sf::Vector2f(GameUtils::lerp1d(player->getSpeed().x, 0.f, K_DEC * delta_time.asSeconds()), player->getSpeed().y));
    if (player->getAcceleration().y == 0 || GameUtils::discordi(player->getAcceleration().y, player->getSpeed().y))
        player->setSpeed(sf::Vector2f(player->getSpeed().x, GameUtils::lerp1d(player->getSpeed().y, 0.f, K_DEC * delta_time.asSeconds())));
    
    //  Se la velocità è molto vicina a 0, impostarla direttamente a 0 (solo quando non è presente un'accelerazione)
    if (abs(player->getSpeed().x) <= 0.1f && player->getAcceleration().x == 0)
        player->setSpeed(sf::Vector2f(0.f, player->getSpeed().y));
    if (abs(player->getSpeed().y) <= 0.1f && player->getAcceleration().y == 0)
        player->setSpeed(sf::Vector2f(player->getSpeed().x, 0.f));

    //  Inerzia
    player->setSpeed(player->getSpeed() + GameUtils::scalare(player->getAcceleration(), delta_time.asSeconds())); // v = v + (a * dt)

    //CM EMA si portebbe usare un nuovo utils come int magnitidine(sf::Vect2f a) usando il torema di pitagora
    //  Controllo velocità orizzontale massima
    // if (GameUtils::getSquareMagnitude(   &(player->getSpeed())         ) > PLAYER_MAX_VH * PLAYER_MAX_VH)
    //     player->setSpeed( GameUtils::setMagnitude(player->getSpeed(), PLAYER_MAX_VH) );
    if (player->getSpeed().x >= PLAYER_MAX_VH)
        player->setSpeed(sf::Vector2f(PLAYER_MAX_VH, player->getSpeed().y));
    else if (player->getSpeed().x <= -PLAYER_MAX_VH)
        player->setSpeed(sf::Vector2f(-PLAYER_MAX_VH, player->getSpeed().y));

    // Update Posizioni e controllo collisioni
    sf::Vector2f next_player_pos(player->getPosition() + GameUtils::scalare(player->getSpeed(), delta_time.asSeconds())); // p = p + (v * dt)
    
    // Controllo collisioni
    for (auto currSO : solidObjects)
    {
        //controllo asse x
        if (GameUtils::colliding(currSO.getPosition(), currSO.getSize(), sf::Vector2f(next_player_pos.x, player->getPosition().y), player->getSize()))
        {
            player->setSpeed(sf::Vector2f(0, player->getSpeed().y));
        }
        //controllo asse y
        if (GameUtils::colliding(currSO.getPosition(), currSO.getSize(), sf::Vector2f(player->getPosition().x, next_player_pos.y), player->getSize()))
        {
            player->setSpeed(sf::Vector2f(player->getSpeed().x, 0));
        }
    }

    //ricalcolo nuova posizione dopo controllo collisioni
    next_player_pos = sf::Vector2f(player->getPosition() + GameUtils::scalare(player->getSpeed(), delta_time.asSeconds())); // p = p + (v * dt)

    //posizione finale
    player->setCoordinates(next_player_pos);
    


    //  Movimento camera
    //view->setCenter(sf::Vector2f(player->getPosition().x + (player->getSize().x / 2), player->getPosition().y + (player->getSize().y / 2))); //la videocamera segue perfettamente il giocatore
    //view->setRotation(view->getRotation() + (delta_time.asMilliseconds() * 0.1f)); // :)

    if (player->getPosition().x < view->getCenter().x - CAMERA_TRIGGER_X) //player va a sinistra
        view->move((player->getPosition().x) - (view->getCenter().x - CAMERA_TRIGGER_X), 0); //spostamento camera
    if (player->getPosition().x + player->getSize().x > view->getCenter().x + CAMERA_TRIGGER_X) //player va a destra
        view->move((player->getPosition().x + player->getSize().x) - (view->getCenter().x + CAMERA_TRIGGER_X), 0); //spostamento camera
    if (player->getPosition().y < view->getCenter().y - CAMERA_TRIGGER_Y) //player va in alto
        view->move(0, (player->getPosition().y) - (view->getCenter().y - CAMERA_TRIGGER_Y)); //spostamento camera
    if (player->getPosition().y + player->getSize().y > view->getCenter().y + CAMERA_TRIGGER_Y) //player va in basso
        view->move(0, (player->getPosition().y + player->getSize().y) - (view->getCenter().y + CAMERA_TRIGGER_Y)); //spostamento camera

    window->setView(*view);
}

//Render

void Game::render()
{
    window->clear();

    //DRAW
    renderSolidObjects(); //render oggetti solidi
    renderPlayer(); //render player



    window->display();
}

void Game::renderSolidObjects()
{
    for (auto currSO : solidObjects)
    {
        window->draw(currSO.getShape());
    }
}

void Game::renderPlayer()
{
    player->render(window);
}

//Window functions

bool Game::isGameOpen()
{
    return window->isOpen();
}

void Game::pollEvents()
{
    while(window->pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed: //chiusura del gioco da Windows
                window->close();
                break;

            case sf::Event::KeyPressed: //chiusura del gioco dal tasto Esc
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
        }
    }
}

void Game::initVars()
{
    //iniz. oggetto finestra
    window = nullptr;
    view = new sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

    //All'avvio del gioco il player sarà posizionato alle coordinate 0, 0 con grandezza 0, 0
    player = new Player(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
}

void Game::initWindow()
{
    //grandezza della finestra impostata alla grandezza dello schermo
    videomode.height = WINDOW_HEIGHT;
    videomode.width = WINDOW_WIDTH;
    
    //apri finestra del gioco
    window = new sf::RenderWindow(videomode, "Gioco", sf::Style::Close | sf::Style::Titlebar);
    
    window->setView(*view);

    window->setFramerateLimit(120);
}

//Solid Objects

void Game::addSolidObject(SolidObject solidObject)
{
    solidObjects.push_back(solidObject);
}

void Game::removeSolidObject(SolidObject solidObject)
{
    int index = 0;
    for (auto currSO : solidObjects)
    {
        if (currSO == solidObject)
        {
            solidObjects.erase(solidObjects.begin() + index);
        }
        index++;
    }
}

// Player

Player *Game::getPlayer()
{
    return player;
}

//Costruttore e Distruttore

Game::Game()
{
    initVars();
    initWindow();
}

Game::~Game()
{
    delete window;
    delete player;
    delete view;
}
