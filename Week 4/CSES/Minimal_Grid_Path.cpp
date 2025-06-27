#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
string dp[MAXN][MAXN];
char grid[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    dp[0][0] = string(1, grid[0][0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) {
                string cand = dp[i - 1][j] + grid[i][j];
                if (dp[i][j].empty() || cand < dp[i][j])
                    dp[i][j] = cand;
            }
            if (j > 0) {
                string cand = dp[i][j - 1] + grid[i][j];
                if (dp[i][j].empty() || cand < dp[i][j])
                    dp[i][j] = cand;
            }
        }
    }
    string path;
    int i = 0, j = 0;
    path += grid[0][0];
    while (i != n - 1 || j != n - 1) {
        if (i == n - 1) {
            j++;
        } else if (j == n - 1) {
            i++;
        } else {
            if (dp[i + 1][j] < dp[i][j + 1])
                i++;
            else
                j++;
        }
        path += grid[i][j];
    }
    cout << path;
}