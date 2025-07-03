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
        int l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        if(l1<b1){
            swap(l1,b1);
            swap(l2,b2);
            swap(l3,b3);
        }
        if((b2==b3 && b2+b1==l1 && l2+l3==l1)||(l1==l2 && l2==l3 && l1==b1+b2+b3)){
            cout<<"YES\n";
        }else{cout<<"NO\n";}
    }
}