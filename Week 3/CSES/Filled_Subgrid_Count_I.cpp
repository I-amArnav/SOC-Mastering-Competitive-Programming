#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            arr[i][j]=c-'A'+1;
        }
    }
    vector<ll>ans(k+1,0);
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int target=1;target<=k;target++){
        for(int i=0;i<n;i++){
            fill(dp[i].begin(),dp[i].end(),0);
            for(int j=0;j<n;j++){
                if(arr[i][j]==target){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                        ans[target]++;
                        continue;
                    }
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    ans[target]+=dp[i][j];
                }
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<"\n";
    }
}