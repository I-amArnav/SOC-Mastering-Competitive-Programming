#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,k,total=0;
        cin>>n>>k;
        int a;
        vector<ll>freq(65,0);
        for(ll i=0;i<n;i++){
            cin>>a;
            ll pos=1;
            while(a>0){
                if(a%2==1){freq[pos]++;total++;}
                a/=2;
                pos++;
            }
        }
        ll pos=1,pow=1;
        while(k>0){
            if((n-freq[pos])*pow>k){
                total+=k/pow;
                break;
            }
            k-=pow*(n-freq[pos]);
            total+=n-freq[pos];
            if(pow>k/2){break;}
            pow*=2;
            pos++;
        }
        cout<<total<<endl;
    }
}