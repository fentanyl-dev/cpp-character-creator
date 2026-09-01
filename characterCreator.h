#ifndef CHARACTER_CREATOR_H
#define CHARACTER_CREATOR_H

#include "Player.h"

// Class / Race

void setClassAttributes(Player& characterInfo, int choiceOfClass);
void setRaceAttributes(Player& characterInfo, int choiceOfRace);

// Choices

int chooseClass();
int chooseRace();

// Save / Load

void saveCharacter(Player& characterInfo);
void loadCharacter(Player& characterInfo);

// Display

void displayCharacter(Player& characterInfo);

// Character Creator

Player createCharacter();

#endif