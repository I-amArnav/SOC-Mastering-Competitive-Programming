#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
vector<int> adj[N];
int subordinates[N];
 
int dfs(int u) {
    int cnt = 0;
    for (int v : adj[u]) {
        cnt += 1 + dfs(v);
    }
    subordinates[u] = cnt;
    return cnt;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << ' ';
    }
    cout << '\n';
}