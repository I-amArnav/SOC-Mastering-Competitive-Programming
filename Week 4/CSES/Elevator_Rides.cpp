#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
typedef pair<int,int> pii;
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<ll>w(n);
    fori(n){cin>>w[i];}
    vector<pii>dp(1<<n,{n+1,0});
    dp[0]={1,0};
    for(int mask=0;mask<(1<<n);mask++){
        fori(n){
            if(mask & (1<<i)){continue;}
            int nextmask=mask|(1<<i);
            auto [rides,lastw]=dp[mask];
            if(lastw+w[i]<=x){
                dp[nextmask]=min(dp[nextmask],{rides,lastw+w[i]});
            }else{
                dp[nextmask]=min(dp[nextmask],{rides+1,w[i]});
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}