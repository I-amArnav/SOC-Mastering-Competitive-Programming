#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string x;cin>>x;
        int n=x.size();
        char min='9';
        fori(n){
            if(x[i]<min){
                min=x[i];
            }
        }
        cout<<min<<endl;
    }
}