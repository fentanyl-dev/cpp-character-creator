#include "characterCreator.h"

#include <iostream>
#include <fstream>

using namespace std;

// Choose Class

int chooseClass()
{
    int choiceOfClass;

    cout << "Choose a class: ";
    cin >> choiceOfClass;

    while (choiceOfClass < 1 || choiceOfClass > 3)
    {
        cout << "Invalid choice! Choose a number from 1 to 3: ";
        cin >> choiceOfClass;
    }

    return choiceOfClass;
}

// Choose Race

int chooseRace()
{
    int choiceOfRace;

    cout << "Choose a race: ";
    cin >> choiceOfRace;

    while (choiceOfRace < 1 || choiceOfRace > 3)
    {
        cout << "Invalid choice! Choose a number from 1 to 3: ";
        cin >> choiceOfRace;
    }

    return choiceOfRace;
}

// Class Attributes

void setClassAttributes(Player& characterInfo, int choiceOfClass)
{
    if (choiceOfClass == 1)
    {
        characterInfo.attributes.hp = 50;
        characterInfo.attributes.mana = 100;
        characterInfo.attributes.strength = 20;
    }
    else if (choiceOfClass == 2)
    {
        characterInfo.attributes.hp = 80;
        characterInfo.attributes.mana = 150;
        characterInfo.attributes.strength = 40;
    }
    else if (choiceOfClass == 3)
    {
        characterInfo.attributes.hp = 100;
        characterInfo.attributes.mana = 30;
        characterInfo.attributes.strength = 70;
    }
}

// Race Attributes

void setRaceAttributes(Player& characterInfo, int choiceOfRace)
{
    if (choiceOfRace == 1)
    {
        characterInfo.attributes.hp += 20;
        characterInfo.attributes.mana += 10;
        characterInfo.attributes.strength += 15;
    }
    else if (choiceOfRace == 2)
    {
        characterInfo.attributes.hp += 10;
        characterInfo.attributes.mana += 30;
        characterInfo.attributes.strength += 45;
    }
    else if (choiceOfRace == 3)
    {
        characterInfo.attributes.hp += 30;
        characterInfo.attributes.mana += 10;
        characterInfo.attributes.strength += 5;
    }
}

// Save

void saveCharacter(Player& characterInfo)
{
    ofstream file("Character.txt");

    if (file.is_open())
    {
        file << "=================" << endl;
        file << "YOUR CHARACTER:" << endl;

        file << "Name: "
             << characterInfo.characterName << endl;

        file << "Class: "
             << characterInfo.characterClass[characterInfo.selectedClass - 1]
             << endl;

        file << "Race: "
             << characterInfo.characterRace[characterInfo.selectedRace - 1]
             << endl;

        file << "HP: "
             << characterInfo.attributes.hp << endl;

        file << "MAX HP: "
             << characterInfo.attributes.maxHP << endl;

        file << "Mana: "
             << characterInfo.attributes.mana << endl;

        file << "MAX MANA: "
             << characterInfo.attributes.maxMANA << endl;

        file << "Strength: "
             << characterInfo.attributes.strength << endl;

        file << "Level: "
             << characterInfo.attributes.level << endl;

        file << "Experience: "
             << characterInfo.attributes.experience << endl;

        file << "Next Level: "
             << characterInfo.attributes.experienceRequired << endl;

        file << "Inventory" << endl;

        for (int i = 0; i < characterInfo.inventory.size(); i++)
        {
            file << characterInfo.inventory[i] << endl;
        }

        file << "=================";

        file.close();

        cout << "File was saved correctly!" << endl;
    }
    else
    {
        cout << "File wasn't saved!" << endl;
    }
}

// Load

void loadCharacter(Player& characterInfo)
{
    ifstream file("Character.txt");

    bool readingInventory = false;

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            if (line.rfind("Name: ", 0) == 0)
            {
                characterInfo.characterName = line.substr(6);
            }

            else if (line.rfind("Class: ", 0) == 0)
            {
                string classText = line.substr(7);

                for (int i = 0; i < 3; i++)
                {
                    if (classText == characterInfo.characterClass[i])
                    {
                        characterInfo.selectedClass = i + 1;
                        break;
                    }
                }
            }

            else if (line.rfind("Race: ", 0) == 0)
            {
                string raceText = line.substr(6);

                for (int i = 0; i < 3; i++)
                {
                    if (raceText == characterInfo.characterRace[i])
                    {
                        characterInfo.selectedRace = i + 1;
                        break;
                    }
                }
            }

            else if (line.rfind("HP: ", 0) == 0)
            {
                characterInfo.attributes.hp = stoi(line.substr(4));
            }

            else if (line.rfind("MAX HP: ", 0) == 0)
            {
                characterInfo.attributes.maxHP = stoi(line.substr(8));
            }

            else if (line.rfind("Mana: ", 0) == 0)
            {
                characterInfo.attributes.mana = stoi(line.substr(6));
            }

            else if (line.rfind("MAX MANA: ", 0) == 0)
            {
                characterInfo.attributes.maxMANA = stoi(line.substr(10));
            }

            else if (line.rfind("Strength: ", 0) == 0)
            {
                characterInfo.attributes.strength = stoi(line.substr(10));
            }

            else if (line.rfind("Level: ", 0) == 0)
            {
                characterInfo.attributes.level = stoi(line.substr(7));
            }

            else if (line.rfind("Experience: ", 0) == 0)
            {
                characterInfo.attributes.experience = stoi(line.substr(12));
            }

            else if (line.rfind("Next Level: ", 0) == 0)
            {
                characterInfo.attributes.experienceRequired = stoi(line.substr(12));
            }

            else if (line == "Inventory")
            {
                characterInfo.inventory.clear();
                readingInventory = true;
            }

            else if (line == "=================")
            {
                readingInventory = false;
            }

            else if (readingInventory && !line.empty())
            {
                characterInfo.inventory.push_back(line);
            }
        }

        file.close();

        cout << "Character loaded successfully!" << endl;
    }
    else
    {
        cout << "Failed to load the file!" << endl;
    }
}

// Display Character

void displayCharacter(Player& characterInfo)
{
    cout << "=================" << endl;
    cout << "YOUR CHARACTER:" << endl;

    cout << "NAME: "
         << characterInfo.characterName << endl;

    cout << "CLASS: "
         << characterInfo.characterClass[characterInfo.selectedClass - 1]
         << endl;

    cout << "RACE: "
         << characterInfo.characterRace[characterInfo.selectedRace - 1]
         << endl;

    cout << "HP: "
         << characterInfo.attributes.hp << endl;

    cout << "MAX HP: "
         << characterInfo.attributes.maxHP << endl;

    cout << "MANA: "
         << characterInfo.attributes.mana << endl;

    cout << "MAX MANA: "
         << characterInfo.attributes.maxMANA << endl;

    cout << "STRENGTH: "
         << characterInfo.attributes.strength << endl;

    cout << "LEVEL: "
         << characterInfo.attributes.level << endl;

    cout << "EXPERIENCE: "
         << characterInfo.attributes.experience << endl;

    cout << "NEXT LEVEL: "
         << characterInfo.attributes.experienceRequired << endl;

    cout << "=================" << endl;
}

// Character Create

Player createCharacter()
{
    cout << "========================" << endl;
    cout << "    CHARACTER CREATOR" << endl;
    cout << "========================" << endl;

    cout << "Please choose a name for your character: ";

    Player characterInfo;

    cin >> characterInfo.characterName;

    cout << endl;

    cout << "Your character name: "
         << characterInfo.characterName << endl;

    cout << endl;

    cout << "Choose one of the following classes:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". "
             << characterInfo.characterClass[i]
             << endl;
    }

    int choiceOfClass = chooseClass();

    characterInfo.selectedClass = choiceOfClass;

    setClassAttributes(characterInfo, choiceOfClass);

    cout << "Your class: "
         << characterInfo.characterClass[choiceOfClass - 1]
         << endl;

    cout << endl;

    // Race

    cout << "Now choose your character's race:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". "
             << characterInfo.characterRace[i]
             << endl;
    }

    int choiceOfRace = chooseRace();

    characterInfo.selectedRace = choiceOfRace;

    setRaceAttributes(characterInfo, choiceOfRace);

    // Max stats

    characterInfo.attributes.maxHP =
        characterInfo.attributes.hp;

    characterInfo.attributes.maxMANA =
        characterInfo.attributes.mana;

    cout << endl;

    // Display

    displayCharacter(characterInfo);

    // Save

    saveCharacter(characterInfo);

    return characterInfo;
}