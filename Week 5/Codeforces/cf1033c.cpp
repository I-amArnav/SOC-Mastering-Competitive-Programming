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
        ll n,m;
        cin>>n>>m;
        if(m<n || m>n*(n+1)/2){cout<<"-1\n";continue;}
        ll r=m-n,curr=0;
        vector<int>nodes;
        vector<bool>seen(n+1,false);
        for(int i=n-1;i>=0;i--){
            if(curr==r){break;}
            if(curr+i<=r){
                curr+=i;
                nodes.push_back(i+1);
                seen[i+1]=true;
            }
        }
        if(nodes.empty() || nodes.back() != 1){
            nodes.push_back(1);
            seen[1] = true;
        }
        int num=nodes.size();
        ll root=nodes[0];
        cout<<root<<"\n";
        for(int i=0;i<num-1;i++){
            cout<<nodes[i]<<" "<<nodes[i+1]<<"\n";
        }
        for(int i=1;i<=n;i++){
            if(!seen[i]){
                cout<<"1 "<<i<<"\n";
            }
        }
    }
}