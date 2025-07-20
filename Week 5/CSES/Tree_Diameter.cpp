#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int n;
pair<int,int> search(int root){
    queue<pair<int,int>>q;
    vector<bool>visited(n+1,false);
    q.push({root,0});
    visited[root]=true;
    pair<int,int>farthest={root,0};
    while(!q.empty()){
        auto[node,depth]=q.front();q.pop();
        if(depth>farthest.second){farthest={node,depth};}
        for(int v:adj[node]){
            if(visited[v]){continue;}
            visited[v]=true;
            q.push({v,depth+1});
        }
    }
    return farthest;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    fori(n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<search(search(1).first).second;
}