#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//INCOMPLETE!!!!!!!!!!!!!!!!!!!!!!!!!

const int MAXN = 3000;
int n, k;
char grid[MAXN][MAXN+1];
int psum[26][MAXN][MAXN];

// Checks in O(k) whether the sz×sz square at (i,j) contains all k letters
inline bool hasAll(int i, int j, int sz) {
    int x2 = i + sz - 1;
    int y2 = j + sz - 1;
    if (x2 >= n || y2 >= n) return false;
    for (int ch = 0; ch < k; ++ch) {
        int cnt = psum[ch][x2][y2];
        if (i > 0) cnt -= psum[ch][i-1][y2];
        if (j > 0) cnt -= psum[ch][x2][j-1];
        if (i > 0 && j > 0) cnt += psum[ch][i-1][j-1];
        if (cnt == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // Build 2D prefix sums for each letter 0..k-1
    for (int ch = 0; ch < k; ++ch) {
        char L = 'A' + ch;
        for (int i = 0; i < n; ++i) {
            int row_sum = 0;
            for (int j = 0; j < n; ++j) {
                row_sum += (grid[i][j] == L);
                psum[ch][i][j] = row_sum
                                + (i>0 ? psum[ch][i-1][j] : 0);
            }
        }
    }

    ll total = 0;
    // For each top‑left (i,j), binary‑search the smallest valid square
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int lo = 1, hi = n - max(i, j), first = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (hasAll(i, j, mid)) {
                    first = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (first != -1) {
                total += (n - max(i, j)) - first + 1;
            }
        }
    }

    cout << total << "\n";
    return 0;
}
