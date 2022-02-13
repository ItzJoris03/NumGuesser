#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

int assignNum(int prev);

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main() {
    bool loop = true;
    int num = assignNum(0);;
    int guess;
    int tries = 0;
    cout << "Welcome to NumGuesser" << endl;
    cout << "If you want to stop the game, type -1.\n\n";
    while(loop) {

        cout << "Choose a number between 1-6:" << endl;
        cin >> guess;

        if(!cin.fail()) {
            if(guess > 0 && guess <= 6) {
                if (guess == num) {
                    cout << "You guessed the right number in " << tries << " amount of times" << endl;
                    sleep_for(seconds(1));
                    system("cls");
                    num = assignNum(num);
                    tries = 0;
                    cout << "Choose a number between 1-6:" << endl;
                } else if (guess < num) {
                    cout << "The number is higher than your guess. Please try again." << endl;
                    tries++;
                } else if (guess > num) {
                    cout << "The number is lower than your guess. Please try again." << endl;
                    tries++;
                }
            } else if (guess == -1) {
                loop = false;
            } else {
                    cout << guess << " is out of range. Choose between 1 - 6.";
            }
        } else {
            cout << guess << " is not a number. Please try again.";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    cout << "\nHave a nice day!";
    return 0;
}

int assignNum(int prev) {
    srand((unsigned)time(0));
    int i = (rand()%6)+1;
    if(i == prev) {
        i = assignNum(prev);
    }
    return i;
}