#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    vector<int> f(11);
    f[0]=0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 10; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    while(t--){
        int n,m;
        cin>>n>>m;
        while(m--){
            int l,b,h;
            cin>>b>>l>>h;
            int side=l;
            if(b>side){
                side=b;
            }
            if(h>side){
                side=h;
            }
            if(l>=f[n]&&b>=f[n]&&h>=f[n] && side>=f[n]+f[n-1]){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        cout<<"\n";
    }
}