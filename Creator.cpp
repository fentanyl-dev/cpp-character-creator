#include "Player.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;


int main() {
    
    int menuChoice = 0;

    while (menuChoice != 3)
    {
        menuChoice = mainMenu();
    
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
            cout << "Goodbye!";
            break;
    
        default:
            cout << "Invalid choice! Please try again.";
            break;
        }
    }
    
    return 0;
}