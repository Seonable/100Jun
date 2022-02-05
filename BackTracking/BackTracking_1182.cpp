#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[30];
int result = 0;

void sum(int index, int acc) {
    if (index == n) {
        if (acc == s) {
            result++;
        }
        return;
    }
    sum(index + 1, acc);
    sum(index + 1, acc + arr[index]);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sum(0, 0);
    if (s == 0) result -= 1;

    cout << result;

    return 0;
}