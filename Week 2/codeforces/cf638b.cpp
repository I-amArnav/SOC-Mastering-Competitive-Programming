#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int count=k;
        bool valid=true;
        vector<int>v(n);
        set<int>s;
        for(int i=0;i<n;i++){
            cin>>v[i];
            s.insert(v[i]);
            if(v[i]>n){
                valid=false;
            }
        }
        if(s.size()>k || !valid){
            cout<<"-1\n";
            continue;
        }
        cout<<k*n<<"\n";
        for(int i=0;i<n;i++){
            count=k;
            while(count){
                for(auto x : s){
                    cout<<x<<" ";
                    count--;
                    if(count==0){
                        break;
                    }
                }
            }
        }
        cout<<"\n";
    }
}