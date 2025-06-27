#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        ll l,r,count=0;
        cin >> l >> r;
        vector <ll> ld,rd;
        while(l != 0){
            ld.push_back(l%10);
            l/=10;
            rd.push_back(r%10);
            r/=10;
        }
        reverse(ld.begin(),ld.end());
        reverse(rd.begin(),rd.end());
        for(int i = 0; i <ld.size(); i++){
            if(ld[i]==rd[i]){
                count+=2;
            }
            else if(rd[i]-ld[i]>=2){
                break;
            }
            else if(rd[i]-ld[i] == 1){
                ll in=++i;
                count++;
                while(ld[in]==9 && rd[in]==0 && in<(ll)ld.size()){
                  count++;
                  in++;
                }
                break;
            }
        }
        cout<<count<<endl;
    }
}