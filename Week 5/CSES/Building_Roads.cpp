#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n,m;
vector<int> adj[100001];
bool seen[100001];
 
void search(int x){
    seen[x]=true;
    for(int neighbour : adj[x]){
        if(!seen[neighbour]){
            search(neighbour);
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    int count=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> diffnodes;
    for(int i=1;i<=n;i++){
        if(!seen[i]){
            count+=1;
            diffnodes.push_back(i);
            search(i);
        }
    }
    cout<<count-1<<"\n";
    for(int i=1;i<count;i++){
        cout<<diffnodes[i-1]<<" "<<diffnodes[i]<<"\n";
    }
}
