#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int x=i;
        while(x>0){
            int d=x%10;
            x/=10;
            if(d!=0){
                dp[i]=min(dp[i],dp[i-d]+1);
            }
        }
    }
    cout<<dp[n];
}