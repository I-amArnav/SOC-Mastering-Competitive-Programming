#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;
int n,m,ans;
vector<string>grid;
vector<int>dx(256),dy(256);
vector<vector<bool>>visited;

//INCOMPLETE!!!!!!!!!!!!!!!!!

int dfsq(int i, int j, int pi, int pj, bool called){
    if(i<0 || i>=n || j<0 || j>=m){return 0;}
    if(grid[i][j]!='?'){return 0;}
    if(visited[i][j]){return 0;}
    visited[i][j]=true;
    set<pair<int,int>>children;
    children.insert({i+1,j});
    children.insert({i-1,j});
    children.insert({i,j-1});
    children.insert({i,j+1});
    if(children.count({pi,pj})){children.erase({pi,pj});}
    int sz=1;
    for(auto [ci,cj]:children){
        sz+=dfsq(ci,cj,i,j,false);
    }
    if(called && sz==1){
        visited[i][j]=false;
        return 0;
    }
    return sz;
}

bool out(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return true;
    }
    if(visited[i][j]){
        return false;
    }
    visited[i][j]=true;
    if(grid[i][j]!='?'){
        bool isout=out(i+dx[grid[i][j]],j+dy[grid[i][j]]);
        if(!isout){ans++;}
        return isout;
    }
    if(grid[i][j]=='?'){
        ans++;
        return false;
    }
    cout<<"Shouldn't reach here\n";
    return true;
}
bool finalout(int i,int j){
    bool temp=true;
    if(i>0){
        temp&=!visited[i-1][j];
    }
    if(i<n-1){
        temp&=!visited[i+1][j];
    }
    if(j>0){
        temp&=!visited[i][j-1];
    }
    if(j<m-1){
        temp&=!visited[i][j+1];
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    dx['U'] = -1; dy['U'] = 0;
    dx['D'] = 1;  dy['D'] = 0;
    dx['L'] = 0;  dy['L'] = -1;
    dx['R'] = 0;  dy['R'] = 1;
    while(t--){
        cin>>n>>m;
        visited.assign(n, vector<bool>(m, false));
        ans=0;
        grid.clear();
        grid.resize(n);
        fori(n){
            cin>>grid[i];
        }
        fori(n){
            forj(m){
                if(grid[i][j]=='?' && !visited[i][j]){
                    ans+=dfsq(i,j,-1,-1,true);
                }
            }
        }
        fori(n){
            forj(m){
                if(grid[i][j]!='?' && !visited[i][j]){
                    bool temp=out(i,j);
                }
            }
        }
        fori(n){
            forj(m){
                if(grid[i][j]=='?' && !visited[i][j]){
                    if(!finalout(i,j)){ans++;}
                }
            }
        }
        cout<<ans<<'\n';
    }
}