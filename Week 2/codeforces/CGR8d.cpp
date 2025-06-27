#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll count=0,total=0;
    int n;
    cin>>n;
    ll a;
    map<ll,ll>m;
    fori(n){
        cin>>a;
        ll pow=1;
        while(a>0){
            if(a%2){
                m[pow]++;
                count++;
            }
            a/=2;
            pow*=2;
        }
    }
    while(count!=0){
        ll num=0;
        for(auto& [f,s] : m){
            if(s==0){continue;}
            num+=f;
            s--;
            count--;
        }
        total+=num*num;
    }
    cout<<total;
}