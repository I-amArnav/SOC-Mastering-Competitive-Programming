#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n,m;
vector<int> adj[100001],previous(100001);
bool seen[100001]={false};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    seen[1]=true;
    while(!q.empty()){
        int curr=q.front();q.pop();
        for(int x : adj[curr]){
            if(seen[x]){continue;}
            previous[x]=curr;
            seen[x]=true;
            q.push(x);
        }
    }
    previous[1]=1;
    if(seen[n]){
        int final=n;
        vector<int>path;
        while(previous[final]!=final){
            path.push_back(final);
            final=previous[final];
        }
        cout<<path.size()+1<<"\n";
        reverse(path.begin(),path.end());
        cout<<"1 ";
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }else{cout<<"IMPOSSIBLE";}
}