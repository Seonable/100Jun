#include <bits/stdc++.h>
using namespace std;

int N;
int U[1005];

vector<int> sumOfTwo;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> U[i];
    sort(U, U + N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sumOfTwo.push_back(U[i] + U[j]);
        }
    }
    sort(sumOfTwo.begin(), sumOfTwo.end());
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(sumOfTwo.begin(), sumOfTwo.end(), U[i] - U[j])) {
                cout << U[i];
                return 0;
            }
        }
    }

    return 0;
}