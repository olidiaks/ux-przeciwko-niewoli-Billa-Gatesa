//
// Created by olidiaks on 28.04.23.
//

#ifndef PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_ENEMY_H
#define PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_ENEMY_H


#include <string>

class Enemy {
private:

//private variables
    std::string name;
    double hp;
    double damage;
    const double regeneration;
    std::string nameMalfunction;
    int x;
    int y;


public:
    //Constructor
    Enemy(const double regeneration, double damage, double hp, int x, int y);

    //Accesors
    int getX() const;
    int getY() const;

    //public functions
    double attack();
    void gotAttacked(double receivedDamage);
    void move(int x, int y);
    bool isDead();

};


#endif //PROJEKT_PODBIJANIE_KAMPUSU_MICROSOFTU_ENEMY_H
