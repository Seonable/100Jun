#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10000005], b[10000005], c[20000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < m; i++) { cin >> b[i]; }

    int aIndex = 0, bIndex = 0;
    for (int i = 0; i < m + n; i++) {
        if (aIndex == n) { c[i] = b[bIndex++]; }
        else if (bIndex == m) { c[i] = a[aIndex++]; }
        else if (a[aIndex] <= b[bIndex]) { c[i] = a[aIndex++]; }
        else if (a[aIndex] > b[bIndex]){ c[i] = b[bIndex++]; }
        else { cerr << "ERROR" << endl; }
    }

    for (int i = 0; i < n + m; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';

    return 0;
}