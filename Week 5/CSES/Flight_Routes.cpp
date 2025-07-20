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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> dist(n + 1);
    priority_queue<tuple<ll, int>, vector<tuple<ll, int>>, greater<>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [cost,node]=pq.top();pq.pop();
        if(dist[node].size()>=k){continue;}
        dist[node].push_back(cost);
        for(auto [v,w]:adj[node]){
            pq.push({cost+w,v});
        }
    }
    for(auto cost : dist[n]){
        cout<<cost<<" ";
    }
}