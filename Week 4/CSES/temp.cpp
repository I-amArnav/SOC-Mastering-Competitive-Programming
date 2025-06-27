#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
char grid[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    vector<vector<string>> dp(n, vector<string>(n));
    dp[0][0] = string(1, grid[0][0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) {
                string cand = dp[i - 1][j] + grid[i][j];
                if (dp[i][j].empty() || cand < dp[i][j]) {
                    dp[i][j] = cand;
                    parent[i][j] = {i - 1, j};
                }
            }
            if (j > 0) {
                string cand = dp[i][j - 1] + grid[i][j];
                if (dp[i][j].empty() || cand < dp[i][j]) {
                    dp[i][j] = cand;
                    parent[i][j] = {i, j - 1};
                }
            }
        }
    }
    string path;
    int x = n - 1, y = n - 1;
    while (true) {
        path += grid[x][y];
        if (x == 0 && y == 0) break;
        tie(x, y) = parent[x][y];
    }
    reverse(path.begin(), path.end());
    cout << path;
}