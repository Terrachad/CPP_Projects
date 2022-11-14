#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;

int main()
{
    int secretNum = 7;
    int guessLimit = 5;
    int guessCounter = 0;
    int guess;
    bool outOfGuesses = false;

    while (secretNum != guess && !outOfGuesses){
        if(guessCounter < guessLimit){
        cout << "Enter guess:";
        cin >> guess;
        guessCounter++;

        } else {
            outOfGuesses = true;
        }
    }
    
    
    if(outOfGuesses) {
        cout << "You lose!";
    } else {
        cout << "You win ";
    }


    return 0;
}











