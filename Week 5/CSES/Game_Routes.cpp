#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
const int MAXN=1e5+5;
int n,m;
ll dp[MAXN];
vector<bool> visited(MAXN);
vector<int>adj[MAXN];

ll dfs(int node){
    if(node==n){return 1;}
    if(visited[node]){return dp[node];}
    visited[node]=true;
    ll ways=0;
    for(auto v:adj[node]){
        ways=(ways+dfs(v))%mod;
    }
    dp[node]=ways;
    return ways;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<dfs(1);
}