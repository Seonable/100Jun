#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void printNumber(int position) {
    if (position == m) {
        for (int _position = 0; _position < m; _position++) { cout << arr[_position] << ' '; }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            arr[position] = i;
            isUsed[i] = true;
            printNumber(position + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    printNumber(0);

    return 0;
}
