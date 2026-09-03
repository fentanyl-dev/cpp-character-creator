#include "enemy.h"

void Enemy::takeDamage(int amount)
{
    hp -= amount;

    if (hp < 0)
    {
        hp = 0;
    }
    
}

void Enemy::attack(Player& player)
{
    player.takeDamage(strength);
}

bool Enemy::checkDeath()
{
    return hp <= 0;   
}