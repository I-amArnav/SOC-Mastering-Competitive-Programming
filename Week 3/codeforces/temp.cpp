#include <bits/stdc++.h>
using namespace std;

int getSum(vector<vector<int>> &pref, int r1, int c1, int r2, int c2, int n, int m) {
    r1 = max(r1, 0);
    c1 = max(c1, 0);
    r2 = min(r2, n - 1);
    c2 = min(c2, m - 1);
    if (r1 > r2 || c1 > c2) return 0;
    return pref[r2 + 1][c2 + 1] - pref[r2 + 1][c1] - pref[r1][c2 + 1] + pref[r1][c1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> arr(n);
        int total_gold = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            for (char c : arr[i]) if (c == 'g') total_gold++;
        }
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1]=pref[i][j + 1]+pref[i + 1][j]-pref[i][j]+(arr[i][j] == 'g' ? 1 : 0);
            }
        }
        int best_loss = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != '.') continue;
                int r1 = i - k;
                int r2 = i + k;
                int c1 = j - k;
                int c2 = j + k;
                int total_in_square = getSum(pref, r1, c1, r2, c2, n, m);
                int boundary_gold = 0;
                boundary_gold += getSum(pref, r1, c1, r1, c2, n, m);
                boundary_gold += getSum(pref, r2, c1, r2, c2, n, m);
                boundary_gold += getSum(pref, r1 + 1, c1, r2 - 1, c1, n, m);
                boundary_gold += getSum(pref, r1 + 1, c2, r2 - 1, c2, n, m);
                int inside = total_in_square - boundary_gold;
                best_loss = min(best_loss, inside);
            }
        }
        cout<<total_gold-best_loss<<"\n";
    }
}