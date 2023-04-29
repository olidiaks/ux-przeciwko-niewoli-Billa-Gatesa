//
// Created by olidiaks on 28.04.23.
//

#ifndef PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_GAME_H
#define PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "Enemy.h"


class Game{
private:
    //Variables
    std::vector<Enemy> microsoftCrap;
    bool isTuxSurvive;

    //Mouse position
    sf::Vector2i mousePositionWindow;

    //Window
    sf::RenderWindow* pWindow;
    sf::VideoMode videoMode;
    sf::Event event;

    //functions
    void initVariables();
    void initWindow();

public:
    Game();
    virtual ~Game();


    //functions
    const bool isRunning() const;

    void updateMousePosition();
    void update();
    void render();

    bool getIsTuxSurvive();

};


#endif //PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_GAME_H
