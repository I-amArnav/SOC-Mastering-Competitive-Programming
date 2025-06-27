#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const ll mod=1e9+7;
int n,m;
vector<int>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    v.resize(n);
    fori(n){cin>>v[i];}
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if(v[0]==0){
        for(int x=1;x<=m;x++){
            dp[0][x]=1;
        }
    }else{
        dp[0][v[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(v[i]==0){
            for(int x=1;x<=m;x++){
                dp[i][x]=((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
            }
        }else{
            int x=v[i];
            dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
        }
    }
    int result=0;
    for (int x=1; x<=m;++x)
        result = (result+dp[n-1][x])%mod;
    cout << result;
}