#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;
typedef bitset<51> bset;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<bset>all(n);
        bset allunique;
        fori(n){
            int k;cin>>k;
            bset currset;
            forj(k){
                int x;cin>>x;
                currset.set(x);
            }
            all[i]=currset;
            allunique|=currset;
        }
        if(n==1){cout<<"0\n";continue;}
        int opt=0,full=allunique.count();
        fori(51){
            if(!allunique[i]){continue;}
            bset temp;
            for(auto currset:all){
                if(currset[i]){continue;}
                temp|=currset;
            }
            int sz=temp.count();
            if(sz<full && sz>opt){opt=sz;}
        }
        cout<<opt<<endl;
    }
}