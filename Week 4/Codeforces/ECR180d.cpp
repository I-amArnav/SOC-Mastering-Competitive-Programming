#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
vector<int> adj[200005];
vector<bool>dealt(200005);

void reset(int n) {
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dealt[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        reset(n);
        vector<int> deg1,deg2,degmore;
        fori(n-1){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n<=2){cout<<"NO\n";continue;}
        for(int i=1;i<=n;i++){
            if(adj[i].size()>=3){
                degmore.push_back(i);
            }else if(adj[i].size()==2){
                deg2.push_back(i);
            }else{
                deg1.push_back(i);
            }
        }
        if((deg2.size()==0)){cout<<"NO\n";continue;}
        cout<<"YES\n";
        int root = deg2[0];
        queue<pair<int,int>>q;
        q.push({adj[root][0],0});
        cout<<adj[root][0]<<" "<<root<<"\n";
        q.push({adj[root][1],1});
        cout<<root<<" "<<adj[root][1]<<"\n";
        dealt[root]=true;
        while(!q.empty()){
            auto p=q.front();q.pop();
            int node=p.first,dir=p.second;
            if (dealt[node]) continue;
            dealt[node] = true;
            for(auto x : adj[node]){
                if(dealt[x]){continue;}
                if(dir){
                    cout<<x<<" "<<node<<"\n";
                    q.push({x,1-dir});  
                }else{
                    cout<<node<<" "<<x<<"\n";
                    q.push({x,1-dir});
                }
            }
        }
    }
}