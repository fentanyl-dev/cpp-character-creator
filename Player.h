#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player
{
    public:
        std::string characterName;
        std::string characterClass[3] = {
            "Archer",
            "Mage",
            "Warrior"
        };
        std::string characterRace[3] = {
            "Elf",
            "Human",
            "Dwarf"
        };

        int selectedClass = 0;
        int selectedRace = 0;

        class CharacterAttributes {
            public:
                int hp;
                int mana;
                int strength;
                int level = 1;
                int experience = 0;
                int experienceRequired = 100;
        };

        CharacterAttributes attributes;

        std::vector<std::string> inventory = {"Potion of Strength", "Potion of Healing", "Sword"};

};

// Attributes

void setClassAttributes (Player& characterInfo, int choiceOfClass);
void setRaceAttributes (Player& characterInfo, int choiceOfRace); 

// Choices

int chooseClass();
int chooseRace();

// SAVE / LOAD

void saveCharacter (Player& characterInfo, int choiceOfClass, int choiceOfRace);
void loadCharacter(Player& characterInfo);

// Display

void displayCharacter(Player& characterInfo, int choiceOfClass, int choiceOfRace);
void displayInventory(Player& characterInfo);

// Inventory

void addItem(Player& characterInfo);
void removeItem(Player& characterInfo);
int inventoryMenu();
void inventory(Player& characterInfo);

// Experience

void addExperience(Player& characterInfo, int amount);

// Character Creator

Player createCharacter();

// menus // gameLoop

int mainMenu();
int characterActionMenu();
void gameLoop(Player& activePlayer);


#endif