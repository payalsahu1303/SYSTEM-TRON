#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int playerChoice, computerChoice;

    // Seed the random number generator with the current time
    srand(time(0));

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors): ";
    cin >> playerChoice;

    if (playerChoice < 0 || playerChoice > 2) {
        cout << "Invalid choice. Please choose 0, 1, or 2." << endl;
        return 1;
    }

    // Generate a random choice for the computer
    computerChoice = rand() % 3;

    cout << "Computer chose: " << computerChoice << endl;

    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
