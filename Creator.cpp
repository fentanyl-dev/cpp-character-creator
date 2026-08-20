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

        class CharacterAtributes {
            public:
                int hp;
                int mana;
                int strenght;
        };

        CharacterAtributes atributes;
};

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

    int choiceOfClass;
    cout << "Wpisz numer odpowiadajacej klasy: ";
    cin >> choiceOfClass;

    if (choiceOfClass == 1)
    {
        characterInfo.atributes.hp = 50;
        characterInfo.atributes.mana = 100;
        characterInfo.atributes.strenght = 20;
    }
    else if (choiceOfClass == 2) 
    {
        characterInfo.atributes.hp = 80;
        characterInfo.atributes.mana = 150;
        characterInfo.atributes.strenght = 40;
    }
    else if (choiceOfClass == 3)
    {
        characterInfo.atributes.hp = 100;
        characterInfo.atributes.mana = 30;
        characterInfo.atributes.strenght = 70;
    }

    cout << "Wybrana Klasa: " << characterInfo.characterClass[choiceOfClass - 1] << endl;

    ofstream file("Character.txt");  

    if (file.is_open())
    {
        file << "=================" << endl;
        file << "TWOJA POSTAC: " << endl;
        file << "Imie: " << characterInfo.characterName << endl;
        file << "Klasa: " << characterInfo.characterClass[choiceOfClass - 1] << endl;
        file << "HP: " << characterInfo.atributes.hp << endl;
        file << "Mana: " << characterInfo.atributes.mana << endl;
        file << "Strenght: " << characterInfo.atributes.strenght << endl;
        file << "=================";

        file.close();

        cout << "Plik zostal zapisany poprawnie!" << endl;
    }
    else 
    {
        cout << "Plik nie zostal zapisany ;/" << endl;
    }
    
    return 0;
}