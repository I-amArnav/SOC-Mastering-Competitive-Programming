#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
const ll mod=1e9+7;
int n,x;
vector<ll> coin, ways;
vector<bool> dealt;
ll func(int sum){
    if(dealt[sum]){return ways[sum];}
    for(int i=0;i<n;i++){
        if (sum >= coin[i])
            ways[sum] = (ways[sum] + func(sum - coin[i])) % mod;
    }
    dealt[sum]=true;
    return ways[sum];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x;
    coin.resize(n,0);
    ways.resize(x + 1, 0);
    dealt.resize(x + 1, false);
    fori(n){cin>>coin[i];}
    ways[0]=1;
    cout<<func(x);
}