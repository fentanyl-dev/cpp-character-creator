#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
using namespace std;

class Enemy 
{
    public:
        int hp = 0;
        int maxHP = 0;
        int strength = 0;

        void takeDamage(int amount);
        void attack(Player& player);
        bool checkDeath();
};


#endif