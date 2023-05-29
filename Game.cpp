//
// Created by olidiaks on 02.05.23.
//

#include <bits/sockaddr.h>
#include "Game.h"
#include <iostream>
#include <sstream>
#include <math.h>


//Constructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initFonts();
    this->initText();
}

//Deconstructions
Game::~Game() {
    delete this->window;
}

void Game::initVariables() {
    this->isWin = false;
    this->points = 0;
    this->pointsMax = rand() % 8000 + 2000;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxSwagBalls = rand() % 50 + 5;
}

void Game::initWindow() {
    this->videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

const bool Game::running() const {
    bool isPlayerLive = this->player.getHp() > 0;
    return this->window->isOpen() && isPlayerLive && !this->isWin;
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->sfEvent)) {
        switch (this->sfEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                switch (sfEvent.key.code) {
                    case sf::Keyboard::Escape:
                        this->window->close();
                        break;
                }
                break;
        }
    }
}

void Game::render() {
    this->window->clear();

    //Render stuff
    this->renderSwagBalls();
    this->player.render(this->window);
    this->renderGui(this->window);

    this->window->display();
}

void Game::update() {
    this->pollEvents();
    this->spawnSwagBalls();
    this->player.update(this->window);
    this->updateCollision();
    this->updateGui();
    this->updateWin();
}

void Game::spawnSwagBalls() {
    if (this->swagBalls.size() < this->maxSwagBalls) {
        //Timer
        if (this->spawnTimer >= this->spawnTimerMax) {
            int points = rand() % (this->pointsMax / 60);
            double hp = (double)(rand() % (int)(round(this->player.getHpMax() * 1.5) * 1000)) / 1000 - (double)this->player.getHpMax();
            this->swagBalls.push_back(SwagBall(*this->window, hp, points));
            this->spawnTimer = 0.f;
        } else {
            this->spawnTimer += 1.f;
        }
    }
}

void Game::renderSwagBalls() {
    for (auto item: this->swagBalls) {
        item.render(*this->window);
    }
}

void Game::updateCollision() {
    //Check the collision
    int j = 0;
    for (auto i: this->swagBalls) {
        if (this->player.getShape().getGlobalBounds().intersects(i.getShape().getGlobalBounds())) {
            this->player.addHp(i.getHp());
            this->points += i.getPoints();
            this->swagBalls.erase(this->swagBalls.begin() + j);
        }
        j++;
    }
}

void Game::initFonts() {
    if (!this->font.loadFromFile("./fonts/PixellettersFull.ttf")) {
        std::cerr << "ERROR::GAME::INITFONT::Could not load PixellettersFull.ttf\n";
    }
}

void Game::initText() {
    this->guiText.setFont(this->font);
    this->guiText.setString("Test działania czy tekst się nam wyświetla.\n Oczywiście wszystko działa jak mógł by nie działać.");
}

void Game::renderGui(sf::RenderTarget *target) {
    target->draw(this->guiText);
}

void Game::updateGui() {
    std::stringstream stringStream;
    stringStream << "Punkty: " << this->points << "/" << this->pointsMax << "\nHp: " << this->player.getHp() << "/"
                 << this->player.getHpMax();
    this->guiText.setString(stringStream.str());
}

void Game::initPlayer() {
    const float x = rand() % this->window->getSize().x + 100;
    const float y = rand() % this->window->getSize().y + 100;
    this->player = Player(x, y);
}

void Game::updateWin() {
    this->isWin = this->points >= this->pointsMax;
}

const bool Game::getIsWin() const {
    return this->isWin;
}
