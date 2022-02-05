#include <bits/stdc++.h>
using namespace std;

int n;
int result = 0;

bool isSameAtCol[40];
bool isDiagonal1[40];
bool isDiagonal2[40];

bool canPutAt(int row, int col) {
    if (isSameAtCol[col] || isDiagonal1[row + col] || isDiagonal2[row - col + n - 1])
        return false;
    return true;
}

void putQueenAt(int row, int col, bool put) {
    isSameAtCol[col] = put;
    isDiagonal1[row + col] = put;
    isDiagonal2[row - col + n - 1] = put;
}

void putQueenOn(int row) {
    if (row == n) {
        result++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!canPutAt(row, col)) continue;
        putQueenAt(row, col, true);
        putQueenOn(row + 1);
        putQueenAt(row, col, false);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    putQueenOn(0);
    cout << result;

    return 0;
}
