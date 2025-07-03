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
        vector<int>a(n),diff(n+2,0);
        map<int,int>freq;
        fori(n){
            cin>>a[i];
            freq[a[i]]++;
        }
        fori(n+1){
            diff[freq[i]]++;
            diff[n-i+1]--;
            if(freq[i]==0){break;}
        }
        fori(n+1){
            if(i!=0){
                diff[i]+=diff[i-1];
            }
            cout<<diff[i]<<" ";
        }
        cout<<"\n";
    }
}