#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m,max=-1;
        cin>>n>>m;
        int arr[n][m];
        fori(n){
            forj(m){
                int temp;
                cin>>temp;
                arr[i][j]=temp;
                if(temp>max){
                    max=temp;
                }
            }
        }
        vector<pair<int,int>>pos;
        fori(n){
            forj(m){
                if(arr[i][j]==max){
                    pos.push_back({i,j});
                }
            }
        }
        bool possible=false;
        int r1 = pos[0].first;
        int c1 = -1;
        bool ok = true;
        for(auto &[r, c] : pos) {
            if(r != r1) {
                if(c1 == -1) c1 = c;
                else if(c1 != -1 && c1 != c) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) possible = true;
        int c2 = pos[0].second;
        int r2 = -1;
        ok = true;
        for(auto &[r, c] : pos) {
            if(c != c2) {
                if(r2 == -1) r2 = r;
                else if(r2 != -1 && r2 != r) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) possible = true;
        if(!possible) {
            cout << max <<"\n";
        }
        else {
            cout << max-1<<"\n";
        }
    }
}