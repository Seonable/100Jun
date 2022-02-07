#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[1005];
bool vis[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (M--) {
        int v; cin >> v;
        int u; cin >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        result++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }

    cout << result;
    return 0;
}