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
        int n,k;
        cin>>n>>k;
        if(n<2*k-1){cout<<"-1\n";continue;}
        fori(n){
            forj(n){
                if(i==j && i%2==0 && k){
                    cout<<'R';
                    k--;
                }else{
                    cout<<'.';
                }
            }
            cout<<'\n';
        }
    }
}