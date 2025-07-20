#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const ll INF=1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    dist[1][0]=0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto [cost,node,used]=pq.top();pq.pop();
        if(cost>dist[node][used]){continue;}
        for(auto [v,w]:adj[node]){
            if(dist[v][used]>cost+w){
                dist[v][used]=cost+w;
                pq.push({dist[v][used],v,used});
            }
            if(!used && dist[v][1]>cost+w/2){
                dist[v][1]=cost+w/2;
                pq.push({dist[v][1],v,1});
            }
        }
    }
    cout<<dist[n][1];
}