#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
const int MAX=1e6+1;
vector<int> divf(MAX,0);
void precompute(){
    for(int i=1;i<MAX;i++){
        for(int j=i;j<MAX;j+=i){
            divf[j]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    precompute();
    while(t--){
        int n;
        cin>>n;
        cout<<divf[n]<<"\n";
    }
}