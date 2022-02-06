#include <bits/stdc++.h>
using namespace std;

int K;
int N;
int lineLength[10001];

bool solve(int length) {
    int cur = 0;
    for (int i = 0; i < K; i++) {
        cur += lineLength[i] / length;
    }
    return cur >= N;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++) cin >> lineLength[i];

    long long start = 0, end = 0x7fffffff;

    while (start < end) {
        long long mid = (start + end + 1) / 2;

        if (solve(mid)) start = mid;
        else end = mid - 1;
    }
    cout << start;
    return 0;
}