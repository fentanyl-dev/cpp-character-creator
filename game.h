#ifndef GAME_H
#define GAME_H

#include "Player.h"

void gameLoop(Player& activePlayer);

int characterActionMenu();

void displayInventory(Player& characterInfo);
int inventoryMenu();
void inventory(Player& characterInfo);

#endif