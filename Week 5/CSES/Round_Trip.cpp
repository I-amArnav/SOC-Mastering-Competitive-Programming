#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
const int MAXN=1e5+5;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
int parent[MAXN];

void print(int start, int end){
    vector<int>path;
    for(int curr=start;curr!=end;curr=parent[curr]){
        path.push_back(curr);
    }
    path.push_back(end);
    path.push_back(start);
    cout<<path.size()<<"\n";
    for(auto node:path){
        cout<<node<<" ";
    }
}

void dfs(int node, int p){
    visited[node]=true;
    for(int v:adj[node]){
        if(v==p){continue;}
        if(visited[v]){
            print(node,v);
            exit(0);
        }else{
            parent[v]=node;
            dfs(v,node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,-1);
        }
    }
    cout<<"IMPOSSIBLE";
}