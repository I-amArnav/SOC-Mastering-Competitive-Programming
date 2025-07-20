#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define pi pair<int, int>
#define f first
#define s second
#define mp make_pair
int n,m;
char c[1000][1000];
bool seen[1000][1000];
int previous[1000][1000];
int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};
string step={'U','R','D','L'};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    queue<pi>q;
    int ax=0,ay=0,bx=0,by=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c[i][j];
            if(c[i][j]=='A'){
                ax=i;ay=j;
            }
            if(c[i][j]=='B'){
                bx=i;by=j;
            }
        }
    }
    q.push({ax,ay});
    seen[ax][ay]=true;
    while(!q.empty()){
        pi curr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=curr.f+dirx[i],y=curr.s+diry[i];
            if(x>=n || x<0 || y>=m || y<0){
                continue;
            }
            if(c[x][y]=='#'){continue;}
            if(seen[x][y]){continue;}
            seen[x][y]=true;
            previous[x][y]=i;
            q.push({x,y});
        }
    }
    if(seen[bx][by]){
        cout<<"YES\n";
        vector<int>steps;
        while(bx!=ax || by!=ay){
            int s = previous[bx][by];
            steps.push_back(s);
            bx-=dirx[s];
            by-=diry[s];
        }
        reverse(steps.begin(),steps.end());
        cout<<steps.size()<<"\n";
        for(auto ch : steps){
            cout<<step[ch];
        }
        cout<<"\n";
    }else{cout<<"NO\n";}
}