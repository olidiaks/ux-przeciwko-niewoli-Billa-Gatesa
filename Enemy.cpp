//
// Created by olidiaks on 28.04.23.
//

#include "Enemy.h"

Enemy::Enemy(float regeneration) : regeneration(regeneration) {

}

double Enemy::attack() {
    this->damage * 1.1;
    return this->damage;
}

void Enemy::gotAttacked(double receivedDamage) {
    this->hp = receivedDamage;
}
