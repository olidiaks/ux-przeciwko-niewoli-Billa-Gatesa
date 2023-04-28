//
// Created by olidiaks on 28.04.23.
//

#include "Game.h"

void Game::update() {

}

void Game::render() {

}

void Game::initVariables() {

}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->pWindow = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

    this->pWindow->setFramerateLimit(60);
}

Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->pWindow;
}

const bool Game::isRunning() const {
    return this->pWindow->isOpen();
}
