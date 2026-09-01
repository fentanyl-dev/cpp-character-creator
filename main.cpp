#include "characterCreator.h"
#include "game.h"

#include <iostream>

using namespace std;

int main()
{
    int menuChoice = 0;

    while (menuChoice != 3)
    {
        cout << "====================" << endl;
        cout << "        GAME" << endl;
        cout << "====================" << endl;
        cout << "1. Create Character" << endl;
        cout << "2. Load Character" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";

        cin >> menuChoice;

        switch (menuChoice)
        {
            case 1:
            {
                Player newPlayer = createCharacter();

                gameLoop(newPlayer);

                break;
            }


            case 2:
            {
                Player loadedCharacter;

                loadCharacter(loadedCharacter);

                gameLoop(loadedCharacter);

                break;
            }


            case 3:

                cout << "Goodbye!" << endl;

                break;


            default:

                cout << "Invalid choice!" << endl;

                break;
        }
    }

    return 0;
}