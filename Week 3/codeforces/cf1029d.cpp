#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,diff;
        bool valid=true;
        cin>>n;
        vector<ll>v(n);
        fori(n){
            cin>>v[i];
        }
        diff=v[1]-v[0];
        for(int i=2;i<n;i++){
            if(v[i]-v[i-1]!=diff){
                valid=false;
                break;
            }
        }
        if(!valid){
            cout<<"NO\n";
            continue;
        }
        for(int i = 0; i < n; i++){
            v[i] = v[i] + (diff < 0 ? diff * (n - i) : -diff * (i + 1));
        }
        cout << (v[0] >= 0 && v[0] % (n + 1) == 0 ? "YES" : "NO") << endl;
    }
}