#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
const int MAXN=1e5+5;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int func(int n,int k){
    if(n==1){return 0;}
    if(n<=k){return 1;}
    vector<int>divs;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            divs.push_back(i);
            if(i!=n/i){divs.push_back(n/i);}
        }
    }
    sort(divs.begin(),divs.end());
    int sz=divs.size();
    vector<int>dp(sz,MAXN);
    dp[0]=0;
    for(int i=1;i<sz;i++){
        for(int j=i-1;j>=0;j--){
            if(divs[i]/divs[j]>k){break;}
            if(divs[i]%divs[j]==0){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    if(dp[sz-1]==MAXN){return -1;}
    return dp[sz-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        int g=gcd(x,y);
        x=x/g;y=y/g;
        int c1=func(x,k),c2=func(y,k);
        if(c1==-1||c2==-1){cout<<"-1\n";}
        else{cout<<c1+c2<<"\n";}
    }
}