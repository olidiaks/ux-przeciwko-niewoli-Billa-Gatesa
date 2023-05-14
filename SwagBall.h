//
// Created by olidiaks on 03.05.23.
//

#ifndef C_____SFML___GRAD_2_SWAGBALL_H
#define C_____SFML___GRAD_2_SWAGBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SwagBall {
private:
    //Variables
    sf::CircleShape shape;
    double hp;
    int points;



    //Functions
    void initShape(const sf::RenderWindow& window);

public:
    SwagBall(const sf::RenderWindow &window, const double hp, const int points);

    explicit SwagBall(const int points);

    explicit SwagBall(const double hp);

    //Accessors
    const sf::CircleShape getShape() const;
    const int getPoints() const;
    const double getHp() const;


    //Functions
    //Update
    void update();

    //Render
    void render(sf::RenderTarget& target);
};


#endif //C_____SFML___GRAD_2_SWAGBALL_Hi