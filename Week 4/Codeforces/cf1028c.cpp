#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,gcdall,freqgcd=0;cin>>n;
        vector<int>a(n);
        set<int>distinct;
        fori(n){
            cin>>a[i];
            if(i==0){
                gcdall=a[0];
            }else{
                gcdall=gcd(gcdall,a[i]);
            }
            distinct.insert(a[i]);
        }
        fori(n){if(a[i]==gcdall){freqgcd++;}}
        if(freqgcd!=0){cout<<n-freqgcd<<"\n";continue;}
        queue<int>q;
        vector<int>dp(5001,-1);
        for(auto val:distinct){dp[val]=0;q.push(val);}
        while(!q.empty()){
            int curr=q.front();q.pop();
            if(curr==gcdall){break;}
            for(int v:distinct){
                int g=gcd(v,curr);
                if(dp[g]==-1){
                    dp[g]=dp[curr]+1;
                    q.push(g);
                }
            }
        }
        cout<<(n-1)+dp[gcdall]<<"\n";
    }
}