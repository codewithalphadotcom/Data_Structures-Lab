#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessNumber(int target, int player)
{
    int guess;
    cout << "Player-0" << player << endl;
    cout << "Enter Your Guess: ";
    cin >> guess;

    if (guess == target)
    {
        cout << "Congratulations Player-0" << player << "! You Guessed the Correct Number!" << endl;
    }
    else
    {
        if (guess < target)
        {
            cout << "low!" << endl
                 << endl;
        }
        else
        {
            cout << "high!" << endl
                 << endl;
        }
        guessNumber(target, player == 1 ? 2 : 1);
    }
}

int main()
{
    srand(time(0));
    int num = ((rand() % 100) + 1);

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Players take turns to guess a number between 1 and 100." << endl
         << endl;

    guessNumber(num, 1);

    return 0;
}
