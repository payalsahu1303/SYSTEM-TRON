#include <iostream>
using namespace std;

const int rows = 6;
const int columns = 7;

char board[rows][columns];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << " 1 2 3 4 5 6 7" << endl;
}

bool isColumnFull(int column) {
    return board[0][column] != ' ';
}

bool isValidMove(int column) {
    return column >= 0 && column < columns && !isColumnFull(column);
}

void makeMove(int column) {
    for (int i = rows - 1; i >= 0; i--) {
        if (board[i][column] == ' ') {
            board[i][column] = currentPlayer;
            break;
        }
    }
}

bool checkWin() {
    // Check horizontal
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 3; j++) {
            if (board[i][j] == currentPlayer && board[i][j + 1] == currentPlayer && board[i][j + 2] == currentPlayer && board[i][j + 3] == currentPlayer) {
                return true;
            }
        }
    }

    // Check vertical
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j] == currentPlayer && board[i + 1][j] == currentPlayer && board[i + 2][j] == currentPlayer && board[i + 3][j] == currentPlayer) {
                return true;
            }
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < columns - 3; j++) {
            if (board[i][j] == currentPlayer && board[i + 1][j + 1] == currentPlayer && board[i + 2][j + 2] == currentPlayer && board[i + 3][j + 3] == currentPlayer) {
                return true;
            }
        }
    }

    // Check diagonals (bottom-left to top-right)
    for (int i = 3; i < rows; i++) {
        for (int j = 0; j < columns - 3; j++) {
            if (board[i][j] == currentPlayer && board[i - 1][j + 1] == currentPlayer && board[i - 2][j + 2] == currentPlayer && board[i - 3][j + 3] == currentPlayer) {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    initializeBoard();
    bool gameover = false;

    while (!gameover) {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter a column (1-7): ";
        int column;
        cin >> column;
        column--;

        if (isValidMove(column)) {
            makeMove(column);
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameover = true;
            } else if (isBoardFull()) {
                displayBoard();
                cout << "It's a tie! The game is over." << endl;
                gameover = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Please choose a valid column." << endl;
        }
    }

    return 0;
}
