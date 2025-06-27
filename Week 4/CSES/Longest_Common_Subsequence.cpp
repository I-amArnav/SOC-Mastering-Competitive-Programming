#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
int n,m;
vector<int>a,b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    a.resize(n);b.resize(m);
    fori(n){cin>>a[i];dp[i][0]=0;}
    fori(m){cin>>b[i];dp[0][i]=0;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){dp[i][j]=dp[i-1][j-1]+1;}
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<int>seq;
    while(n>0 && m>0){
        if(a[n-1]==b[m-1]){
            seq.push_back(a[n-1]);
            m--;n--;
        }else if(dp[n][m-1]>dp[n-1][m]){
            m--;
        }else{n--;}
    }
    cout<<seq.size()<<"\n";
    for(int i=seq.size()-1;i>=0;i--){
        cout<<seq[i]<<" ";
    }
}