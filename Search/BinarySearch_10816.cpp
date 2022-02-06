#include <bits/stdc++.h>
using namespace std;

int N;
int card[500001];

int upperBound(int target) {
    int start = 0;
    int end = N;

    while (start < end) {
        int mid = (start + end) / 2;
        if (target < card[mid]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int lowerBound(int target) {
    int start = 0;
    int end = N;

    while (start < end) {
        int mid = (start + end) / 2;

        if (target <= card[mid]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> card[i];
    sort(card, card + N);

    int M; cin >> M;
    while (M--) {
        int t; cin >> t;
        cout << upperBound(t) - lowerBound(t) << ' ';
    }
    cout << '\n';

    return 0;
}