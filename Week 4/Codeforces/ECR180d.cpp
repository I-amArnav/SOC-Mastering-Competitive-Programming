#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
vector<int> adj[200005];
vector<bool>dealt(200005);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        if(n<=2){cout<<"NO\n";continue;}
        vector<int> deg1,deg2,degmore;
        fori(n){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()>=3){
                degmore.push_back(i);
            }else if(adj[i].size()==2){
                deg2.push_back(i);
            }else{
                deg1.push_back(i);
            }
        }
        if(degmore.size()>1 || (deg2.size()==0)){cout<<"NO\n";continue;}
        cout<<"YES\n";
        int node=degmore[0];
        queue<pair<int,int>>q;
        q.push({node,0});
        bool one=false;
        while(!q.empty()){
            auto p=q.front();q.pop();
            int node=p.first,dir=p.second;
            dealt[node]=true;
            for(auto x : adj[node]){
                if(dealt[x]){continue;}
                if(dir){
                    if(adj[x].size()==1 && adj[node].size()==2 && !one){
                        cout<<node<<" "<<x<<"\n";
                        one=true;
                    }else{
                        cout<<x<<" "<<node<<"\n";
                    }     
                }else{
                    cout<<node<<" "<<x<<"\n";
                }
                q.push({x,1-dir});
            }
        }
    }
}