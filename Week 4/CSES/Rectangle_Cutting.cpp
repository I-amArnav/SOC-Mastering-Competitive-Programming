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
    int a,b,count=0;
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,mod));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){dp[i][j]=0;continue;}
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
            }
        }
    }
    cout<<dp[a][b];
}