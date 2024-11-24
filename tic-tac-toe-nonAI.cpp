//tic-nonai

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;


void printBoard(vector<string> &board) {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}


void takeYourTurn(vector<string> &board, string currPlayer) {
    cout << currPlayer << "'s Turn" << endl;
    cout << "Enter the position between 1 to 9" << endl;
    int position;
    cin >> position;
    position -= 1;
    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "You have entered an INVALID position. Please enter the position again" << endl;
        cin >> position;
        position -= 1;
    }
    board[position] = currPlayer;
}


void takeComputerTurn(vector<string> &board, string currPlayer) {
    cout << currPlayer << "'s Turn (Computer)" << endl;
    srand(time(0)); 
    int position = rand() % 9;
    while (board[position] != "-") {
        position = rand() % 9;
    }
    board[position] = currPlayer;
}


int countEmpty(vector<string> &board) {
    int c = 0;
        for (auto a : board) {
        if (a == "-") {
            c++;
        }
    }
    return c;
}


string check(vector<string> &board) {
    if (
        (board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != "-") ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != "-") ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != "-") ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != "-") ||
        (board[0] == board[4] && board[4] == board[8] && board[0] != "-") ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")
    ) {
        return "win";
    } else if (countEmpty(board) == 0) {
        return "draw";
    } else {
        return "play";
    }
}


int main() {
    vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};
    
    string currPlayer = "X";
    bool gameOver = false;


    while (!gameOver) {
        printBoard(board);
        if (currPlayer == "X") {
            takeYourTurn(board, currPlayer);
        } else {
            takeComputerTurn(board, currPlayer);
        }
        
        string result = check(board);
        if (result == "win") {
            printBoard(board);
            cout << currPlayer << " Won!" << endl;
            gameOver = true;
        } else if (result == "draw") {
            printBoard(board);
            cout << "Draw!" << endl;
            gameOver = true;
        } else {
            currPlayer = (currPlayer == "X") ? "O" : "X";
                    }
    }


    return 0;
}
