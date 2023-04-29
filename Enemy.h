//
// Created by olidiaks on 28.04.23.
//

#ifndef PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_ENEMY_H
#define PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_ENEMY_H


#include <string>

class Enemy {
private:

//variables
    std::string name;
    double hp;
    double damage;
    const float regeneration;
    std::string nameMalfunction;


public:
    Enemy(float regeneration);

    double attack();
    void gotAttacked(double receivedDamage);
};


#endif //PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_ENEMY_H
