#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dp[MAXN][2];
void dfs(int node, int parent){
    int sum=0;
    for(int v:adj[node]){
        if(v==parent){continue;}
        dfs(v,node);
        sum+=max(dp[v][0],dp[v][1]);
    }
    dp[node][0]=sum;
    for(int v:adj[node]){
        if(v==parent){continue;}
        int temp=1+dp[v][0]+sum-max(dp[v][0],dp[v][1]);
        dp[node][1]=max(dp[node][1],temp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;cin>>n;
    fori(n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout<<max(dp[1][1],dp[1][0]);
}