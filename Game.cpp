//
// Created by olidiaks on 28.04.23.
//

#include "Game.h"

void Game::update() {
    this->updateMousePosition();
}

void Game::render() {
    /**
        @return void

        - clear old frame
        - render objects
        - display frame in window

        Renders the game objects.
    */

    this->pWindow->clear();

    //Draw game objects

    this->pWindow->display();
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

bool Game::getIsTuxSurvive() {
    return this->isTuxSurvive;
}

void Game::updateMousePosition() {
    /**
		@ return void

		Updates the mouse positions:
		- Mouse position relative to window (Vector2i)
	*/



    this->mousePositionWindow = sf::Mouse::getPosition(*this->pWindow);
}
