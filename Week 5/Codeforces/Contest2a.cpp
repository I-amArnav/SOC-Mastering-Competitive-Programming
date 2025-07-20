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
        int n;
        ll sum=0;
        cin>>n;
        vector<int>a(n);
        fori(n){
            cin>>a[i];
            sum+=a[i];
        }
        ll root=sqrtl(sum);
        if(root*root==sum){
            cout<<"YES";
        }
        else{cout<<"NO";}
        cout<<"\n";
    }
}