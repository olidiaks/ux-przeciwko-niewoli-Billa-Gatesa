//
// Created by olidiaks on 02.05.23.
//

#include "Player.h"

void Player::initShape() {
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->shape);

}

void Player::initVariables() {
    this->movementSpeed = 5.f;
    this->hpMax = rand() % 100 + 50;
    this->hp = hpMax;
}

Player::Player(float x, float y) : x(x), y(y) {
    this->initPosition();
    this->initVariables();
    this->initShape();

}

void Player::initPosition() {
    shape.setPosition(x, y);
}

void Player::updateInput() {
    //Keyboard input
    //Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->shape.move(-this->movementSpeed, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->shape.move(this->movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->shape.move(0.f, -this->movementSpeed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->shape.move(0.f, this->movementSpeed);
    }

}

void Player::updateWindowBoundsCollision(const sf::RenderTarget *target) {
    //Left
    if (this->shape.getGlobalBounds().left <= 0.f) {
        this->shape.setPosition(0.f, this->shape.getPosition().y);
    }
        //Right
    else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
        this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
    }
    //top
    if (this->shape.getGlobalBounds().top <= 0.f) {
        this->shape.setPosition(this->shape.getPosition().x, 0.f);
    }
        //Bottom
    else if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
        this->shape.setPosition(this->shape.getPosition().x, target->getSize().y - this->shape.getGlobalBounds().width);
    }
}

void Player::update(const sf::RenderTarget *target) {

    this->updateInput();

    //Window bounds collision
    this->updateWindowBoundsCollision(target);
}

const sf::RectangleShape Player::getShape() const {
    return this->shape;
}

const int Player::getHp() const {
    return this->hp;
}

const int Player::getHpMax() {
    return this->hpMax;
}

void Player::addHp(const double hp) {
    this->hp += hp;
    if (this->hp > this->hpMax){
        this->hp = this->hpMax;
    }
}
