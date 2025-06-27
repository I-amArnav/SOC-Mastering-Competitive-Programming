#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[100001],init(100001),goal(100001),nodes;
void search(int node,int parent,int depth,int flipeven,int flipodd){
    int curr=init[node];
    if(depth%2==0){curr^=flipeven;}
    else{curr^=flipodd;}
    if(curr!=goal[node]){
        nodes.push_back(node);
        if(depth%2){flipodd^=1;}
        else{flipeven^=1;}
    }
    for(int x : adj[node]){
        if(x==parent){continue;}
        search(x,node,depth+1,flipeven,flipodd);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,u,v,count=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        cin>>init[i+1];
    }
    for(int i=0;i<n;i++){
        cin>>goal[i+1];
    }
    search(1,0,0,0,0);
    cout<<nodes.size()<<"\n";
    for(int node : nodes){
        cout<<node<<"\n";
    }
}