#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int guess;

    cout << "-: Welcome to the Number Guessing Game :-\n\n";
    cout << "Guess the number between 1 to 100" << endl;

    do
    {
        cout << "Enter your Guess : ";
        cin >> guess;

        if (guess > numberToGuess)
        {
            cout << "Number is too high, try again" << endl;
        }
        else if (guess < numberToGuess)
        {
            cout << "Number is too low, try again" << endl;
        }
        else
        {
            cout << "Congratulation! you guess the right number" << endl;
        }
    } while (guess != numberToGuess);

    return 0;
}