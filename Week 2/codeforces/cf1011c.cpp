#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll x,y,k=1;
        cin>>x>>y;
        if(x==y){
            cout<<"-1\n";
            continue;
        }
        ll max=(x>y ? x:y);
        while(k<=max){
            k*=2;
        }
        cout<<k-max<<"\n";
    }
}