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
        int n,m;
        cin>>n>>m;
        vector<int>a(m);
        for(int i=0;i<m;i++){
            cin>>a[m];
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            int l=(i%2==0 ? i/2:m-1-i/2);
            int r=m-1-l;
            cout<<a[l]<<" "<<a[r]<<" "<<a[l]<<" "<<a[r]<<" "<<a[l]<<" "<<a[r]<<"\n";
        }
    }
}