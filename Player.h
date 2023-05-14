//
// Created by olidiaks on 02.05.23.
//

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#ifndef C_____SFML___GRAD_2_PLAYER_H
#define C_____SFML___GRAD_2_PLAYER_H


class Player {
private:
    sf::RectangleShape shape;

    float x, y;
    float movementSpeed;
    int hp, hpMax;

    void initPosition();

    void initVariables();

    void initShape();

public:
    Player(float x = 0.f, float y = 0.f);

    //accesors
    const sf::RectangleShape getShape() const;
    const int getHp() const;
    const int getHpMax();

    void addHp(const double hp);

    //update functions
    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget *target);

    //render functions
    void render(sf::RenderTarget *target);

};


#endif //C_____SFML___GRAD_2_PLAYER_H
