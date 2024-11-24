//tic ai
#include <iostream>
#include <vector>
#include <climits> 


using namespace std;


const char EMPTY = ' ';
const char HUMAN = 'X';
const char COMPUTER = 'O';
vector<char> board(9, EMPTY);


void initializeBoard() {
    fill(board.begin(), board.end(), EMPTY);
}


void printBoard() {
    cout << endl;
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i];
        if (i % 3 != 2) cout << " |";
        if (i % 3 == 2 && i != 8) cout << "\n---|---|---\n";
    }
    cout << endl << endl;
}


bool checkWinner(char player) {
    return (board[0] == player && board[1] == player && board[2] == player) ||
           (board[3] == player && board[4] == player && board[5] == player) ||
           (board[6] == player && board[7] == player && board[8] == player) ||
           (board[0] == player && board[3] == player && board[6] == player) ||           (board[1] == player && board[4] == player && board[7] == player) ||
           (board[2] == player && board[5] == player && board[8] == player) ||
           (board[0] == player && board[4] == player && board[8] == player) ||
           (board[2] == player && board[4] == player && board[6] == player);
}


bool checkDraw() {
    for (char c : board) {
        if (c == EMPTY) {
            return false;
        }
    }
    return true;
}


int minimax(bool isMaximizing);


void computerMove() {
    int bestMove = -1;
    int bestValue = INT_MIN;
    for (int i = 0; i < 9; i++) {
        if (board[i] == EMPTY) {
            board[i] = COMPUTER;
            int moveValue = minimax(false);
            board[i] = EMPTY;
            if (moveValue > bestValue) {
                bestMove = i;
                bestValue = moveValue;
            }
        }
    }
    board[bestMove] = COMPUTER;
}


int minimax(bool isMaximizing) {
    if (checkWinner(COMPUTER)) {
        return 1;
    }
    if (checkWinner(HUMAN)) {
        return -1;
    }
    if (checkDraw()) {
        return 0;
    }


    if (isMaximizing) {
        int bestValue = INT_MIN;
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {                board[i] = COMPUTER;
                bestValue = max(bestValue, minimax(false));
                board[i] = EMPTY;
            }
        }
        return bestValue;
    } else {
        int bestValue = INT_MAX;
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = HUMAN;
                bestValue = min(bestValue, minimax(true));
                board[i] = EMPTY;
            }
        }
        return bestValue;
    }
}


void humanMove() {
    int move;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--;
        if (move >= 0 && move < 9 && board[move] == EMPTY) {
            board[move] = HUMAN;
            break;
        } else {
            cout << "This move is not valid." << endl;
        }
    }
}


int main() {
    initializeBoard();
    printBoard();


    while (true) {
        humanMove();
        printBoard();
        if (checkWinner(HUMAN)) {
            cout << "Human wins!" << endl;
            break;
        }
        if (checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }


        computerMove();
        printBoard();
        if (checkWinner(COMPUTER)) {
            cout << "Computer wins!" << endl;
            break;
        }
        if (checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }
    }


    cout << "Thanks for playing!" << endl;
    return 0;
}
