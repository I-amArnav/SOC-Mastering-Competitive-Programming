#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int total=n*(n+1)/2;
    if (total % 2 != 0) {
        cout<<"0";
        return 0;
    }
    total/=2;
    vector<ll> dp(total + 1, 0);
    dp[0] = 1;
    for (int num = 1; num <= n; ++num) {
        for (int j = total; j >= num; --j) {
            dp[j] = (dp[j] + dp[j - num]) % mod;
        }
    }
    ll inv2=(mod+1)/2;
    cout<<(dp[total] * inv2)%mod;
}
