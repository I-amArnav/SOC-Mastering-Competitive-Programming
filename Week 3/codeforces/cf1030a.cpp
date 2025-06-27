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
        int n,ones;
        cin>>n>>ones;
        int zeros=n-ones;
        for(int i=0;i<ones;i++){
            cout<<"1";
        }
        for(int i=0;i<zeros;i++){
            cout<<"0";
        }
        cout<<endl;
    }
}