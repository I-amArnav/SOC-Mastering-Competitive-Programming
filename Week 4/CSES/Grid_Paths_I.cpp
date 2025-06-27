#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const ll mod=1e9+7;

vector<vector<int>> trap(1,vector<int>(1)),dealt(1,vector<int>(1)),val(1,vector<int>(1));
int n;
ll dp(int i,int j){
    if(i<0 || i>=n || j<0 || j>=n){return 0;}
    if(i==n-1 && j==n-1){
        return 1LL;
    }
    if(trap[i][j]==1){return 0LL;}
    if(dealt[i][j]){return val[i][j];}
    dealt[i][j]=true;
    val[i][j]=(dp(i,j+1)+dp(i+1,j))%mod;
    return val[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    trap.resize(n);
    dealt.resize(n);
    val.resize(n);
    for(auto &row : trap){
        row.resize(n);
    }
    for(auto &row : dealt){
        row.resize(n);
    }
    for(auto &row : val){
        row.resize(n);
    }
    fori(n){
        forj(n){
            char c;cin>>c;
            if(c=='.'){trap[i][j]=0;}
            else{trap[i][j]=1;}
            dealt[i][j]=false;
            val[i][j]=0;
        }
    }
    if(trap[0][0]==1 || trap[n-1][n-1]==1){
        cout<<"0";
        return 0;
    }
    cout<<dp(0,0);
}