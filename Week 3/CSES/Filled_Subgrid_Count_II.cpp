#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//INCOMPLETE!!!!!!!!!!!!!!!!!!!

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<vector<int>>arr(n,vector<int>(n));
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++){
            char c; cin >> c;
            arr[i][j]=c-'A'+1;
        }
    }
    vector<ll>ans(k+1,0);
    vector<vector<int>> h(n, vector<int>(n, 0));
    for (int target = 1; target <= k; target++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == target) {
                    h[i][j] = (i == 0 ? 1 : h[i - 1][j] + 1);
                } else {
                    h[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (h[i][j] == 0) continue;
                int min_h = h[i][j];
                for (int col = j; col >= 0 && h[i][col] > 0; --col) {
                    min_h=min(min_h,h[i][col]);
                    ans[target]+=1LL*min_h;
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << ans[i] << "\n";
    }
}
