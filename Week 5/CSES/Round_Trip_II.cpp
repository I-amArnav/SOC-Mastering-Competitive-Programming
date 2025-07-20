#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const int MAXN=1e5+5;
vector<int>adj[MAXN],parent(MAXN),visited(MAXN);
int n,m,start=-1,ending=-1;

bool dfs(int node){
    visited[node]=1;
    for(auto u:adj[node]){
        if(visited[u]==0){
            parent[u]=node;
            if(dfs(u)){return true;}
        }else if(visited[u]==1){
            start=u;
            ending=node;
            return true;
        }
    }
    visited[node]=2;
    return false;
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
    for(int i=1;i<=n;i++){
        if(!visited[i] && dfs(i)){break;}
    }
    if(start==-1){
        cout<<"IMPOSSIBLE\n";
    }else{
        vector<int>cycle;
        cycle.push_back(start);
        for(int curr=ending;curr!=start;curr=parent[curr]){
            cycle.push_back(curr);
        }
        cycle.push_back(start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<"\n";
        for(auto node : cycle){
            cout<<node<<" ";
        }
    }
}