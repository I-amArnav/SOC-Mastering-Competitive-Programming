#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,total_dead=0;
    cin>>n;
    ll dur[n],dead;
    for(ll i=0;i<n;i++){
        cin>>dur[i]>>dead;
        total_dead+=dead;
    }
    sort(dur,dur+n);
    for(ll i=0;i<n;i++){
        total_dead-=dur[i]*(n-i);
    }
    cout<<total_dead;
}