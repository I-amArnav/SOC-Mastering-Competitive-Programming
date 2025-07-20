#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

struct cas{
    ll l,r,real;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<cas>all(n);
        fori(n){cin>>all[i].l>>all[i].r>>all[i].real;}
        sort(all.begin(),all.end(),[](const cas&a,const cas&b){return a.l<b.l;});
        ll curr=k;
        int index=0;
        priority_queue<pair<ll,int>>pq;
        while(true){
            while(index<n && all[index].l<=curr){
                if(all[index].r>=curr){pq.push({all[index].real,index});}
                index++;
            }
            if(pq.empty()){break;}
            auto [real_val, i] = pq.top();pq.pop();
            if(real_val <= curr){continue;}
            curr = real_val;
        }
        cout<<curr<<"\n";
    }
}