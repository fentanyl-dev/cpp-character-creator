#include "game.h"
#include "characterCreator.h"

#include <iostream>
#include <limits>

using namespace std;


// ====================
// CHARACTER MENU
// ====================

int characterActionMenu()
{
    int choice;

    cout << "====================" << endl;
    cout << "    CHARACTER MENU" << endl;
    cout << "====================" << endl;
    cout << "1. Display Character" << endl;
    cout << "2. Inventory" << endl;
    cout << "3. Add Experience" << endl;
    cout << "4. Take Damage" << endl;
    cout << "5. Heal" << endl;
    cout << "6. Restore Mana" << endl;
    cout << "7. Save and Quit" << endl;
    cout << "Choose: ";

    cin >> choice;

    return choice;
}


// ====================
// INVENTORY
// ====================

void displayInventory(Player& characterInfo)
{
    cout << "=================" << endl;
    cout << "    INVENTORY" << endl;
    cout << "=================" << endl;

    if (characterInfo.inventory.empty())
    {
        cout << "Inventory is empty!" << endl;
    }
    else
    {
        for (int i = 0; i < characterInfo.inventory.size(); i++)
        {
            cout << i + 1 << ". "
                 << characterInfo.inventory[i]
                 << endl;
        }
    }

    cout << "=================" << endl;
}


int inventoryMenu()
{
    int inventoryChoice;

    cout << "====================" << endl;
    cout << "      INVENTORY" << endl;
    cout << "====================" << endl;
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

                saveCharacter(characterInfo);

                break;


            case 2:
            {
                if (characterInfo.inventory.empty())
                {
                    cout << "Inventory is empty!" << endl;
                    break;
                }

                int itemChoice;

                cout << "Choose the item you want to remove: ";
                cin >> itemChoice;

                characterInfo.removeItem(itemChoice);

                saveCharacter(characterInfo);

                break;
            }


            case 3:

                break;


            default:

                cout << "Invalid! Please enter a number from 1 to 3."
                     << endl;

                break;
        }
    }
}


// ====================
// GAME LOOP
// ====================

void gameLoop(Player& activePlayer)
{
    bool inGame = true;

    cout << endl;
    cout << "====================" << endl;
    cout << "     GAME START" << endl;
    cout << "====================" << endl;
    cout << "Welcome, "
         << activePlayer.characterName
         << "!" << endl;
    cout << endl;

    while (inGame)
    {
        int action = characterActionMenu();

        cout << endl;

        switch (action)
        {
            // DISPLAY CHARACTER
            case 1:

                displayCharacter(activePlayer);

                break;


            // INVENTORY
            case 2:

                inventory(activePlayer);

                break;


            // EXPERIENCE
            case 3:
            {
                int experienceAmount;

                cout << "How much experience do you want to add: ";
                cin >> experienceAmount;

                activePlayer.addExperience(experienceAmount);

                saveCharacter(activePlayer);

                break;
            }


            // DAMAGE
            case 4:
            {
                int amount;

                cout << "How much damage do you want to deal: ";
                cin >> amount;

                activePlayer.takeDamage(amount);

                cout << "HP: "
                     << activePlayer.attributes.hp
                     << "/"
                     << activePlayer.attributes.maxHP
                     << endl;

                if (activePlayer.checkDeath())
                {
                    cout << endl;
                    cout << "You're dead!" << endl;

                    inGame = false;
                }

                saveCharacter(activePlayer);

                break;
            }


            // HEAL
            case 5:
            {
                int amount;

                cout << "How much do you want to heal yourself: ";
                cin >> amount;

                activePlayer.heal(amount);

                cout << "HP: "
                     << activePlayer.attributes.hp
                     << "/"
                     << activePlayer.attributes.maxHP
                     << endl;

                saveCharacter(activePlayer);

                break;
            }


            // MANA
            case 6:
            {
                int amount;

                cout << "How much mana do you want to restore: ";
                cin >> amount;

                activePlayer.restoreMana(amount);

                cout << "Mana: "
                     << activePlayer.attributes.mana
                     << "/"
                     << activePlayer.attributes.maxMANA
                     << endl;

                saveCharacter(activePlayer);

                break;
            }


            // SAVE AND QUIT
            case 7:

                saveCharacter(activePlayer);

                cout << "Game saved!" << endl;
                cout << "Goodbye!" << endl;

                inGame = false;

                break;


            default:

                cout << "Invalid choice!" << endl;

                break;
        }

        cout << endl;
    }
}