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



class Game{
private:
    //Variables
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

    //Variables
    bool isTuxSurvive;

    //functions
    const bool isRunning() const;

    void update();
    void render();
};


#endif //PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_GAME_H
