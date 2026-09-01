#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player
{
public:

    std::string characterName;

    std::string characterClass[3] =
    {
        "Archer",
        "Mage",
        "Warrior"
    };

    std::string characterRace[3] =
    {
        "Elf",
        "Human",
        "Dwarf"
    };

    int selectedClass = 0;
    int selectedRace = 0;

    class CharacterAttributes
    {
    public:

        int hp = 0;
        int maxHP = 0;

        int mana = 0;
        int maxMANA = 0;

        int strength = 0;

        int level = 1;
        int experience = 0;
        int experienceRequired = 100;
    };

    CharacterAttributes attributes;

    std::vector<std::string> inventory =
    {
        "Potion of Strength",
        "Potion of Healing",
        "Sword"
    };

    // Experience
    void addExperience(int amount);

    // Inventory
    void addItem();
    void removeItem(int itemChoice);

    // Combat
    void takeDamage(int amount);
    void heal(int amount);
    void restoreMana(int amount);
    void useMana(int amount);

    bool checkDeath();
};

#endif