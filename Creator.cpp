#include <iostream>
#include <fstream>
using namespace std;

class Player
{
    public:
        string characterName;
        string characterClass[3] = {
            "Archer",
            "Mag",
            "Warrior"
        };
        string characterRace[3] = {
            "Elf",
            "Human",
            "Dwarf"
        };

        class CharacterAttributes {
            public:
                int hp;
                int mana;
                int strength;
        };

        CharacterAttributes attributes;

};

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

int chooseClass()
{
    int choiceOfClass;
    cout << "Wpisz numer odpowiadajacej klasy: ";
    cin >> choiceOfClass;

    while (choiceOfClass < 1 || choiceOfClass > 3)
    {
        cout << "Nieprawidlowy wybor! Wybierz klase od 1 do 3: ";
        cin >> choiceOfClass;
    }

    return choiceOfClass;
}

int chooseRace()
{
    int choiceOfRace;
    cout << "Wpisz numer odpowiedniej rasy: ";
    cin >> choiceOfRace;

    while (choiceOfRace < 1 || choiceOfRace > 3) 
    {
        cout << "Nieprawidlowy wybor rasy! Wybierz rase od 1 do 3!: " << endl;
        cin >> choiceOfRace;

    }
    return choiceOfRace;
}

void saveCharacter (Player& characterInfo, int choiceOfClass, int choiceOfRace)
{
    ofstream file("Character.txt");  

    if (file.is_open())
    {
        file << "=================" << endl;
        file << "TWOJA POSTAC: " << endl;
        file << "Imie: " << characterInfo.characterName << endl;
        file << "Klasa: " << characterInfo.characterClass[choiceOfClass - 1] << endl;
        file << "Rasa: " << characterInfo.characterRace[choiceOfRace - 1] << endl;
        file << "HP: " << characterInfo.attributes.hp << endl;
        file << "Mana: " << characterInfo.attributes.mana << endl;
        file << "Strength: " << characterInfo.attributes.strength << endl;
        file << "=================";

        file.close();

        cout << "Plik zostal zapisany poprawnie!" << endl;
    }
    else 
    {
        cout << "Plik nie zostal zapisany ;/" << endl;
    }
}

void displayCharacter(Player& characterInfo, int choiceOfClass, int choiceOfRace)
{
    cout << "=================" << endl;
    cout << "TWOJA POSTAC: " << endl;
    cout << "IMIE: " << characterInfo.characterName << endl;
    cout << "KLASA: " << characterInfo.characterClass[choiceOfClass - 1] << endl;
    cout << "RASA: " << characterInfo.characterRace[choiceOfRace - 1] << endl;
    cout << "HP: " << characterInfo.attributes.hp << endl;
    cout << "MANA: " << characterInfo.attributes.mana << endl;
    cout << "STRENGTH: " << characterInfo.attributes.strength << endl;
    cout << "=================" << endl;
}

int main() {
    cout << "Witaj w Kreatorze postaci" << endl;
    cout << "Prosze o wybranie imienia postaci: ";

    Player characterInfo;

    cin >> characterInfo.characterName;
    cout << "Wybrane imie postaci: " << characterInfo.characterName << endl;

    cout << "Nastepnie przedstawie ci kilka klas postaci do wyboru! Prosze wybrac klase ktora cie interesuje" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << characterInfo.characterClass[i] << endl;
    }

    int choiceOfClass = chooseClass();

    setClassAttributes(characterInfo, choiceOfClass);
    
    cout << "Wybrana Klasa: " << characterInfo.characterClass[choiceOfClass - 1] << endl;

    //RACE

    cout << "Teraz wybierz rase swojej postaci: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << characterInfo.characterRace[i] << endl;
    }

    int choiceOfRace = chooseRace();
    
    setRaceAttributes(characterInfo, choiceOfRace);

    //DISPLAY CHARACTER

    displayCharacter(characterInfo, choiceOfClass, choiceOfRace);

    //FILE
    
    saveCharacter(characterInfo, choiceOfClass, choiceOfRace);
    
    return 0;
}