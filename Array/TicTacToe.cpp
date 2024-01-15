#include <iostream>
const int SIZE = 3;
void displayBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true; 
}
int main() {
    char board[SIZE][SIZE] = {{' ', ' ', ' '},
                              {' ', ' ', ' '},
                              {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;
    do {
        std::cout << "\nCurrent Board:\n";
        displayBoard(board);
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                std::cout << "\nPlayer " << currentPlayer << " wins!\n";
                displayBoard(board);
                break;
            }
            if (checkDraw(board)) {
                std::cout << "\nThe game is a draw!\n";
                displayBoard(board);
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }

    } while (true);
    return 0;
}
