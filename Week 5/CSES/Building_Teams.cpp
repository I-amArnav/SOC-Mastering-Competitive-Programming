#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n,m;
vector<int> adj[100001];
vector<bool> teama(100001),teamb(100001);
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool valid=true;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
        if(teama[i] || teamb[i]){continue;}
        teama[i]=true;
        while(!q.empty()){
            int curr=q.front();q.pop();
            if(teama[curr] && teamb[curr]){valid=false; break; }
            if(teama[curr]){
                for(int x : adj[curr]){
                    if(teamb[x]){continue;}
                    teamb[x]=true;
                    q.push(x);
                }
            }else if(teamb[curr]){
                for(int x : adj[curr]){
                    if(teama[x]){continue;}
                    teama[x]=true;
                    q.push(x);
                }
            }
        }
    }
    if(!valid){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(teama[i]){
            cout<<"1 ";
        }else{
            cout<<"2 ";
        }
    }
}
