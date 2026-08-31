#include "Player.h"

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Class

void setClassAttributes (Player& characterInfo, int choiceOfClass) 
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

// Race

void setRaceAttributes (Player& characterInfo, int choiceOfRace)
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

// chooseClass

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

// chooseRace

int chooseRace()
{
    int choiceOfRace;
    cout << "Choose a race: ";
    cin >> choiceOfRace;

    while (choiceOfRace < 1 || choiceOfRace > 3) 
    {
        cout << "Invalid choice! Choose a number from 1 to 3: " << endl;
        cin >> choiceOfRace;

    }
    return choiceOfRace;
}

// saveCharacter 

void saveCharacter (Player& characterInfo, int choiceOfClass, int choiceOfRace)
{
    ofstream file("Character.txt");  

    if (file.is_open())
    {
        file << "=================" << endl;
        file << "YOUR CHARACTER: " << endl;
        file << "Name: " << characterInfo.characterName << endl;
        file << "Class: " << characterInfo.characterClass[choiceOfClass - 1] << endl;
        file << "Race: " << characterInfo.characterRace[choiceOfRace - 1] << endl;
        file << "HP: " << characterInfo.attributes.hp << endl;
        file << "Mana: " << characterInfo.attributes.mana << endl;
        file << "Strength: " << characterInfo.attributes.strength << endl;
        file << "Level: " << characterInfo.attributes.level << endl;
        file << "Experience: " << characterInfo.attributes.experience << endl;
        file << "Next Level: " << characterInfo.attributes.experienceRequired << endl;
    
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
            
            if (line.rfind("Name: ", 0) == 0 || line.rfind("NAME: ", 0) == 0)
            {
                characterInfo.characterName = line.substr(6);
            }
            
            else if (line.rfind("Class: ", 0) == 0 || line.rfind("CLASS: ", 0) == 0)
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
            
            else if (line.rfind("Race: ", 0) == 0 || line.rfind("RACE: ", 0) == 0)
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
            else if (line.rfind("Mana: ", 0) == 0 || line.rfind("MANA: ", 0) == 0)
            {
                characterInfo.attributes.mana = stoi(line.substr(6));
            }
            else if (line.rfind("Strength: ", 0) == 0 || line.rfind("STRENGTH: ", 0) == 0)
            {
                characterInfo.attributes.strength = stoi(line.substr(10));
            }
            else if (line.rfind("Level: ", 0 ) == 0 || line.rfind("LEVEL: ", 0) == 0)
            {
                characterInfo.attributes.level = stoi(line.substr(7));
            }
            else if (line.rfind("Experience: ", 0) == 0 || line.rfind("EXPERIENCE: ", 0) == 0)
            {
                characterInfo.attributes.experience = stoi(line.substr(12));
            }
            else if (line.rfind("Next Level: ", 0) == 0 || line.rfind("NEXT LEVEL: ",0 ) == 0)
            {
                characterInfo.attributes.experienceRequired = stoi(line.substr(12));
            }

            else if (line == "Inventory" || line == "INVENTORY")
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
    }
    else 
    {
        cout << "Failed to load the file!" << endl;
    }
}

//Display

void displayCharacter(Player& characterInfo, int choiceOfClass, int choiceOfRace)
{
    cout << "=================" << endl;
    cout << "YOUR CHARACTER: " << endl;
    cout << "NAME: " << characterInfo.characterName << endl;

    string className = (choiceOfClass > 0 && choiceOfClass <= 3) 
                        ? characterInfo.characterClass[choiceOfClass - 1] 
                        : "Unknown";
    string raceName = (choiceOfRace > 0 && choiceOfRace <= 3) 
                      ? characterInfo.characterRace[choiceOfRace - 1] 
                      : "Unknown";

    cout << "CLASS: " << className << endl;
    cout << "RACE: " << raceName << endl;
    cout << "HP: " << characterInfo.attributes.hp << endl;
    cout << "MANA: " << characterInfo.attributes.mana << endl;
    cout << "STRENGTH: " << characterInfo.attributes.strength << endl;
    cout << "LEVEL: " << characterInfo.attributes.level << endl;
    cout << "EXPERIENCE: " << characterInfo.attributes.experience << endl;
    cout << "NEXT LEVEL: " << characterInfo.attributes.experienceRequired << endl;
    cout << "=================" << endl;
}

void displayInventory(Player& characterInfo)
{
    cout << "=================" << endl;
    for (int i = 0; i < characterInfo.inventory.size(); i++)
    {
        cout << i + 1 << ". " << characterInfo.inventory[i] << endl;
    }
    cout << "=================" << endl;
}

// addItems

void Player::addItem()
{
    string itemName;
    cout << "Enter the name of the item you want to add: " << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, itemName);

    inventory.push_back(itemName);
}

// removeItem

void Player::removeItem(int itemChoice)
{

    while (itemChoice < 1 || itemChoice > inventory.size())
    {
        cout << "Invalid choice!" << endl;
        cin >> itemChoice;
    }

    inventory.erase(inventory.begin() + itemChoice - 1);
    
}

// Inventory

int inventoryMenu()
{
    int inventoryChoice;

    cout << " ==================== " << endl;
    cout << "      INVENTORY " << endl;
    cout << " ==================== " << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Back" << endl;
    cout << "Choose: ";

    cin >> inventoryChoice;

    return inventoryChoice;
}

void inventory(Player& characterInfo) 
{
    int inventoryChoice = 0;

    while (inventoryChoice != 3)
    {
        displayInventory(characterInfo);

        inventoryChoice = inventoryMenu();

        switch (inventoryChoice)
        {
        case 1:
            characterInfo.addItem();
            saveCharacter(
                characterInfo, 
                characterInfo.selectedClass, 
                characterInfo.selectedRace
            );
            break;
        
        case 2:
            int itemChoice;
            cout << "Choose the item you want to remove: ";
            cin >> itemChoice;

            characterInfo.removeItem(itemChoice);
            
            saveCharacter(characterInfo, 
                characterInfo.selectedClass, 
                characterInfo.selectedRace);
            break;

        case 3:
            break;

        default:
            cout << "Invalid! Please enter a number from 1 to 3." << endl; 
            break;
        }
    }
    
}

// Experience

void Player::addExperience(int amount)
{
    attributes.experience += amount;

    while (attributes.experience >= attributes.experienceRequired)
    {
        cout << "+1 level!" << endl;
        attributes.level++;

        attributes.experience -= attributes.experienceRequired;
        attributes.experienceRequired += 50;

    }
}

// createCharacter

Player createCharacter()
{
    cout << "Welcome to the character creator!" << endl;
    cout << "Please choose a name for your character: ";

    Player characterInfo;

    cin >> characterInfo.characterName;
    cout << "Your character name: " << characterInfo.characterName << endl;

    cout << "Choose one of the following classes: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << characterInfo.characterClass[i] << endl;
    }

    int choiceOfClass = chooseClass();
    characterInfo.selectedClass = choiceOfClass;

    setClassAttributes(characterInfo, choiceOfClass);
    
    cout << "Your class: " << characterInfo.characterClass[choiceOfClass - 1] << endl;

     //RACE

    cout << "Now choose your character's race " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << characterInfo.characterRace[i] << endl;
    }

    int choiceOfRace = chooseRace();
    characterInfo.selectedRace = choiceOfRace;
    
    setRaceAttributes(characterInfo, choiceOfRace);

    //DISPLAY CHARACTER

    displayCharacter(characterInfo, choiceOfClass, choiceOfRace);

    //FILE
    
    saveCharacter(characterInfo, choiceOfClass, choiceOfRace);

    return characterInfo;
}

// menus

int mainMenu()
{
    int menuChoice;

    cout << " ==================== " << endl;
    cout << "  CHARACTER CREATOR " << endl;
    cout << " ==================== "<< endl;
    cout << "1. Create Character" << endl;
    cout << "2. Load Character" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose: ";

    cin >> menuChoice;

    return menuChoice;

}

int characterActionMenu()
{
    int choice;

     cout << " ==================== " << endl;
     cout << "    CHARACTER MENU " << endl;
     cout << " ==================== " << endl;
     cout << "1. Display Character" << endl;
     cout << "2. Inventory " << endl;
     cout << "3. Add Experience" << endl;
     cout << "4. Save and Quit" << endl;
     cout << "Choose: ";

     cin >> choice;

     return choice;
}

// gameloop

void gameLoop(Player& activePlayer)
{
    bool inGame = true;

    while (inGame)
    {
        int action = characterActionMenu();
        switch (action)
        {
        case 1:
            displayCharacter(
                activePlayer,
                activePlayer.selectedClass,
                activePlayer.selectedRace
            );
            break;
        case 2:
            inventory(activePlayer);
            break;

        case 3:
            int experienceAmount;
            cout << "How much experience you want to add: ";
            cin >> experienceAmount;
            activePlayer.addExperience(experienceAmount);
            break;
        case 4:
            saveCharacter(
                activePlayer,
                activePlayer.selectedClass,
                activePlayer.selectedRace
            );
            inGame = false;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    
}
