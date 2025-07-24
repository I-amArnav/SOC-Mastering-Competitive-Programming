#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>>mat(n,vector<int>(n));
        int lo=1,hi=n*n;
        bool uselo=true;
        fori(n){
            if(i%2){
                forj(n){
                    mat[i][j]= uselo?lo++:hi--;
                    uselo=!uselo;
                }
            }else{
                forj(n){
                    mat[i][n-1-j]= uselo?lo++:hi--;
                    uselo=!uselo;
                }
            }
        }
        for (auto row : mat) {
            for (int v : row){cout<<v<<' ';};
            cout<<'\n';
        }
    }
}