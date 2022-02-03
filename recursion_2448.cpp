#include <bits/stdc++.h>
using namespace std;

void printFirstLine(char** board, int x, int y) {
    board[x][y + 2] = '*';
}

void printSecondLine(char** board, int x, int y) {
    board[x + 1][y + 1] = '*';
    board[x + 1][y + 3] = '*';
}

void printThirdLine(char** board, int x, int y) {
    board[x + 2][y + 0] = '*';
    board[x + 2][y + 1] = '*';
    board[x + 2][y + 2] = '*';
    board[x + 2][y + 3] = '*';
    board[x + 2][y + 4] = '*';
}

void fillBasicTriangle(char** board, int x, int y) {
    printFirstLine(board, x, y);
    printSecondLine(board, x, y);
    printThirdLine(board, x, y);
}

void fillStars(int num, char** board, int x, int y) {
    if (num == 3) {
        return fillBasicTriangle(board, x, y);
    }

    fillStars(num / 2, board, x, y + (num / 2) );
    fillStars(num / 2, board, x + (num / 2), y);
    fillStars(num / 2, board, x + (num / 2), y + num);
}


void fillStars(int num, char** board) {
    fillStars(num, board, 0, 0);
}

void printBoard(int num, char **board) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num * 2; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

char** makeBoard(int num) {
    char** board = new char*[num];
    for (int i = 0; i < num; i++) {
        board[i] = new char[num * 2];
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num * 2; j++) {
            board[i][j] = ' ';
        }
    }

    return board;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    char** board = makeBoard(num);
    fillStars(num, board);
    printBoard(num, board);

    for(int i = 0; i < num; ++i) { delete [] board[i]; }
    delete [] board;

    cout << "Test";

    return 0;
}

