#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        vector<pair<int,int>>v;
        fori(n){cin>>a[i];}
        fori(n){
            cin>>b[i];
            if(a[i]>b[i]){
                swap(a[i],b[i]);
                v.push_back({3,i+1});
            }
        }
        fori(n){
            forj(n-1){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    v.push_back({1,j+1});
                }
                if(b[j]>b[j+1]){
                    swap(b[j],b[j+1]);
                    v.push_back({2,j+1});
                }
            }
        }
        cout<<v.size()<<"\n";
        for(auto p:v){
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
}