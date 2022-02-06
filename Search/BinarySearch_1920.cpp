#include <bits/stdc++.h>
using namespace std;

int N;
int A[100005];

int binarySearch(int target) {
    int start = 0;
    int end = N - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (target < A[mid]) {
            end = mid - 1;
        } else if (target > A[mid]) {
            start = mid + 1;
        } else {
            return 1;
        }
    }
    return 0;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);

    int M; cin >> M;
    while (M--) {
        int t; cin >> t;
        cout << binarySearch(t) << '\n';
    }

    return 0;
}