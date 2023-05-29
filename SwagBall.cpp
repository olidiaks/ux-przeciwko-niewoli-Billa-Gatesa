//
// Created by olidiaks on 03.05.23.
//

#include "SwagBall.h"


void SwagBall::initShape(const sf::RenderWindow &window) {
    this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setFillColor(color);

    sf::Color borderColor(this->hp >= 0 ? sf::Color::Green : sf::Color::Red);
    this->shape.setOutlineColor(borderColor);

    this->shape.setOutlineThickness(5.0f);

    float x = rand() % window.getSize().x - this->shape.getGlobalBounds().width;
    float y = rand() % window.getSize().y - this->shape.getGlobalBounds().height;
    x = x < 0 ? 0 : x;
    y = y < 0 ? 0 : y;
    y = y < 70 && x < 150 ? 70 : y;
    this->shape.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

void SwagBall::render(sf::RenderTarget &target) {
    target.draw(this->shape);
}

const sf::CircleShape SwagBall::getShape() const {
    return this->shape;
}

SwagBall::SwagBall(const sf::RenderWindow &window, const double hp, const int points) : hp(hp), points(points) {
    this->initShape(window);
    this->render((sf::RenderTarget &) window);
}

const int SwagBall::getPoints() const {
    return this->points;
}

SwagBall::SwagBall(const int points) : points(points), hp(0) {}

const double SwagBall::getHp() const {
    return this->hp;
}
