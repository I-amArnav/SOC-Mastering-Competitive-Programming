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
        int n,count=0;
        cin>>n;
        vector<int> a(n);
        set<int>curr,seen;
        for(int i=0;i<n;i++){
            cin>>a[i];
            curr.insert(a[i]);
            seen.insert(a[i]);
            if(seen.size()==curr.size()){
                seen.clear();
                count++;
            }
        }
        cout<<count<<"\n";
    }
}