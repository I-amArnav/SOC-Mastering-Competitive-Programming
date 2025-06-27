#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
struct p{
    int start,end;
    ll r;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;cin>>n;
    vector<p>proj(n);
    fori(n){
        cin>>proj[i].start>>proj[i].end>>proj[i].r;
    }
    sort(proj.begin(),proj.end(),[](const auto &a,const auto &b){
        return a.end<b.end;
    });
    vector<int>endays;
    for(auto p:proj){
        endays.push_back(p.end);
    }
    vector<ll>dp(n);
    dp[0]=proj[0].r;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1];
        int l=0,r=i-1,best=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(endays[mid]<proj[i].start){
                best=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ll temp=proj[i].r;
        if(best!=-1){temp+=dp[best];}
        dp[i]=max(dp[i],temp);
    }
    cout<<dp[n-1];
}