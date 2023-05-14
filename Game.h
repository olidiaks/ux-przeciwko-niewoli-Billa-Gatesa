//
// Created by olidiaks on 02.05.23.
//


#ifndef C_____SFML___GRAD_2_GAME_H
#define C_____SFML___GRAD_2_GAME_H


#include "Player.h"
#include "SwagBall.h"
#include <vector>

class Game {
private:
    //Win
    bool isWin;

    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event sfEvent;

    //player
    Player player;

    int points;
    int pointsMax;

    sf::Font font;
    sf::Text guiText;

    //SwagBalls
    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;

    //Init
    void initVariables();
    void initWindow();
    void initPlayer();
    void initFonts();
    void initText();

public:

//Constructors
    Game();
//Deconstructions
    ~Game();


    //Accessors
    const bool running() const;
    const bool getIsWin() const;

    //Modifiers

    //Functions
    void pollEvents();

    void spawnSwagBalls();

    //update
    void updateGui();
    void updateCollision();
    void updateWin();
    void update();

    //render
    void renderSwagBalls();
    void renderGui(sf::RenderTarget* target);
    void render();

};


#endif //C_____SFML___GRAD_2_GAME_H
