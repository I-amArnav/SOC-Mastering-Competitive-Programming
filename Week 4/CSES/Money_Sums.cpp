#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
set<int>sums;
vector<int>num;
int n;
void append(int i, int sum){
    if(i>=n){return;}
    sums.insert(sum);
    append(i+1,sum);
    append(i+1,sum+num[i+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    num.resize(n);
    fori(n){cin>>num[i];}
    sums.insert(0);
    //append(-1,0);
    for(int i=0;i<n;i++){
        set<int> newSums;
        for (int sum : sums) {
            newSums.insert(sum + num[i]);
        }
        for (int sum : newSums) {
            sums.insert(sum);
        }
    }
    sums.erase(0);
    cout<<sums.size()<<endl;
    for(auto sum : sums){
        cout<<sum<<" ";
    }
}