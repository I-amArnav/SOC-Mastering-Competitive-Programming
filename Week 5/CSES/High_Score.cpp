#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const ll INF=1e18;
vector<bool>affected,visited;
vector<vector<int>> adj,radj;
void dfs(int node){
    visited[node]=true;
    for(auto v:adj[node]){
        if(!visited[v]){dfs(v);}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    affected.resize(n+1,false);
    visited.resize(n+1,false);
    vector<int>a(m),b(m);
    vector<ll>w(m),dist(n+1,INF);
    dist[1]=0;
    adj.resize(n+1);
    radj.resize(n+1);
    fori(m){
        cin>>a[i]>>b[i]>>w[i];
        w[i]=-w[i];
        adj[a[i]].push_back(b[i]);
        radj[b[i]].push_back(a[i]);
    }
    forj(n-1){
        fori(m){
            if(dist[a[i]]<INF && dist[a[i]]+w[i]<dist[b[i]]){
                dist[b[i]]=w[i]+dist[a[i]];
            }
        }
    }
    fori(m){
        if(dist[a[i]]<INF && dist[a[i]]+w[i]<dist[b[i]]){
            affected[b[i]]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(affected[i]){dfs(i);}
    }
    if(visited[n]){
        cout<<"-1\n";
    }else{
        cout<<-dist[n]<<"\n";
    }
}