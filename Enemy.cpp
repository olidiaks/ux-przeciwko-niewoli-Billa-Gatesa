//
// Created by olidiaks on 28.04.23.
//

#include "Enemy.h"

double Enemy::attack() {
    this->damage * 1.1;
    return this->damage;
}

void Enemy::gotAttacked(double receivedDamage) {
    this->hp -= receivedDamage;
    this->hp *= this->regeneration;
}

Enemy::Enemy(const double regeneration, double damage, double hp, int x, int y)
        : regeneration(regeneration), damage(damage), hp(hp), x(x), y(y) {

}

int Enemy::getX() const {
    return this->x;
}

int Enemy::getY() const {
    return this->y;
}

void Enemy::move(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Enemy::isDead() {
    return this->hp <= 0;
}
