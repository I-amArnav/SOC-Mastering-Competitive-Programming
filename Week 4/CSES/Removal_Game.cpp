#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;cin>>n;
    ll total=0,diff=0;
    vector<ll>num(n);
    vector<vector<ll>>dp(n,vector<ll>(n));
    fori(n){
        cin>>num[i];
        dp[i][i]=num[i];
        total+=num[i];
    }
    for (int len=2;len<=n;++len) {
        for (int l=0; l+len-1<n;++l) {
            int r=l+len-1;
            dp[l][r]= max(num[l]-dp[l+1][r],num[r]-dp[l][r-1]);
        }
    }
    cout<<(total+dp[0][n-1])/2;
}