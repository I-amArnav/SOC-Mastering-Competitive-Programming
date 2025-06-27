#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
int n;
vector<ll>tree;

void add(int nod,ll val){
	for(; nod <= n; nod += (nod & (-nod)))
		tree[nod]=(tree[nod]+val)&mod;
}
int compute(int nod){
	int ans = 0;
	for(;nod>0; nod -= (nod & (-nod)))
		ans=(ans+tree[nod])%mod;
	return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    vector<int>x(n+1),sortedx(n+1);
    tree.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>x[i];
        sortedx[i]=x[i];
    }
    sort(sortedx.begin()+1,sortedx.end());
    sortedx.erase(unique(sortedx.begin()+1,sortedx.end()),sortedx.end());
    map<int,int>compress;
    for(int i=1;i<sortedx.size();i++){
        compress[sortedx[i]]=i;
    }

}