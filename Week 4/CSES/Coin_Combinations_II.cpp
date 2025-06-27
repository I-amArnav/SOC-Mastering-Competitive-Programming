#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<ll> coin(n);
    for(int i = 0; i < n; ++i) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int s = coin[i]; s <= x; ++s){
            dp[s] = (dp[s] + dp[s - coin[i]]) % mod;
        }
    }
    cout << dp[x];
}