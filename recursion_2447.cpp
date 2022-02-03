#include <bits/stdc++.h>
using namespace std;

void fillBasicRectangle(char** board, int x, int y) {
    board[x][y]     = '*'; board[x][y + 1]     = '*';   board[x][y + 2]     = '*';
    board[x + 1][y] = '*';                              board[x + 1][y + 2] = '*';
    board[x + 2][y] = '*'; board[x + 2][y + 1] = '*';   board[x + 2][y + 2] = '*';
}


void printBoard(char **board, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void fillStars(char** board, int num, int x, int y) {
    if (num == 3) {
        fillBasicRectangle(board, x, y);
        return;
    }

    fillStars(board, num / 3, x + ((num / 3) * 0), y); fillStars(board, num / 3, x + ((num / 3) * 0), y + ((num / 3) * 1)); fillStars(board, num / 3, x + ((num / 3) * 0), y + + ((num / 3) * 2));
    fillStars(board, num / 3, x + ((num / 3) * 1), y);                                                                                 fillStars(board, num / 3, x + ((num / 3) * 1), y + + ((num / 3) * 2));
    fillStars(board, num / 3, x + ((num / 3) * 2), y); fillStars(board, num / 3, x + ((num / 3) * 2), y + ((num / 3) * 1)); fillStars(board, num / 3, x + ((num / 3) * 2), y + + ((num / 3) * 2));
}

void fillStars(char** board, int num) {
    fillStars(board, num, 0, 0);
}

char** makeBoard(int num) {
    char** board = new char*[num];
    for (int i = 0; i < num; i++) {
        board[i] = new char[num];
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
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
    fillStars(board, num);
    printBoard(board, num);

    for(int i = 0; i < num; ++i) { delete [] board[i]; }
    delete [] board;

    return 0;
}