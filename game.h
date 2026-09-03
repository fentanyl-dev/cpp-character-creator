#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "enemy.h"

void gameLoop(Player& activePlayer);

int characterActionMenu();

void displayInventory(Player& characterInfo);
int inventoryMenu();
void inventory(Player& characterInfo);

void combat(Player& player, Enemy& enemy);

#endif