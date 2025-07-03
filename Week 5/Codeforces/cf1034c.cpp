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
        int n;cin>>n;
        vector<int>a(n),mini(n),maxi(n);
        fori(n){
            cin>>a[i];
            if(i==0){mini[0]=a[0];}
            else{
                mini[i]=(mini[i-1]>a[i]?a[i]:mini[i-1]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){maxi[n-1]=a[n-1];}
            else{
                maxi[i]=(maxi[i+1]<a[i]?a[i]:maxi[i+1]);
            }
        }
        fori(n){
            if(i==0 || i==n-1){
                cout<<"1";
            }else{
                if(maxi[i]>a[i] && mini[i]<a[i]){
                    cout<<"0";
                }else{
                    cout<<"1";
                }
            }
        }
        cout<<"\n";
    }
}