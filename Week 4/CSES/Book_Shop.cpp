#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> price(n),pages(n),dp(x+1,0);
    fori(n){cin>>price[i];}
    fori(n){cin>>pages[i];}
    fori(n){
        for(int j=x;j>=price[i];j--){
            dp[j]=max(dp[j],dp[j-price[i]]+pages[i]);
        }
    }
    cout<<dp[x];
}