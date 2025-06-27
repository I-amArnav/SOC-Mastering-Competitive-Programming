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
        int n,diff,tim=0,pow2=1,tdiff=0,best=0;
        bool consec=false;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0){continue;}
            diff=arr[i]-arr[i-1];
            tdiff+=diff;
            if(tdiff>0){
                tdiff=0;
            }
            if(tdiff<best){
                best=tdiff;
            }
        }
        while(pow2-1+best<0){
            pow2*=2;
            tim+=1;
        }
        cout<<tim<<"\n";
    }
}
