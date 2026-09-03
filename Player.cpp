#include "Player.h"
#include "enemy.h"

#include <iostream>
#include <limits>

using namespace std;

// Experience

void Player::addExperience(int amount)
{
    if (amount < 0)
    {
        return;
    }

    attributes.experience += amount;

    while (attributes.experience >= attributes.experienceRequired)
    {
        cout << "+1 level!" << endl;

        attributes.level++;

        attributes.experience -= attributes.experienceRequired;

        attributes.experienceRequired += 50;
    }
}

// Inventory

void Player::addItem()
{
    string itemName;

    cout << "Enter the name of the item you want to add: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, itemName);

    inventory.push_back(itemName);
}

void Player::removeItem(int itemChoice)
{
    while (itemChoice < 1 || itemChoice > inventory.size())
    {
        cout << "Invalid choice!" << endl;
        cin >> itemChoice;
    }

    inventory.erase(inventory.begin() + itemChoice - 1);
}

// Combat

void Player::takeDamage(int amount)
{
    if (amount < 0)
    {
        return;
    }

    attributes.hp -= amount;

    if (attributes.hp < 0)
    {
        attributes.hp = 0;
    }
}

void Player::heal(int amount)
{
    if (amount < 0)
    {
        return;
    }

    attributes.hp += amount;

    if (attributes.hp > attributes.maxHP)
    {
        attributes.hp = attributes.maxHP;
    }
}

void Player::restoreMana(int amount)
{
    if (amount < 0)
    {
        return;
    }

    attributes.mana += amount;

    if (attributes.mana > attributes.maxMANA)
    {
        attributes.mana = attributes.maxMANA;
    }
}

void Player::useMana(int amount)
{
    if (amount < 0)
    {
        return;
    }

    attributes.mana -= amount;

    if (attributes.mana < 0)
    {
        attributes.mana = 0;
    }
}

bool Player::checkDeath()
{
    return attributes.hp <= 0;
}

void Player::attack(Enemy& enemy)
{
    enemy.takeDamage(attributes.strength);
}