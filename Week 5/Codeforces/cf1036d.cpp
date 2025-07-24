#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define all(v) v.begin(),v.end()
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n),arr;
        fori(n){cin>>a[i];}
        if (k==1) {
            cout << "YES\n";
            continue;
        }
        vector<int>b=a;
        sort(all(b));
        int comp=b[k-2];
        fori(n){
            if(a[i]<=comp){arr.push_back(a[i]);}
        }
        int sz=arr.size();
        int l=0,r=sz-1,spare=sz-k+1;
        bool palin=true;
        while(l<r){
            if(arr[l]!=arr[r]){
                if(spare==0){
                    palin=false;
                    break;
                }
                if(arr[l]==comp){
                    l++;
                    spare--;
                }else if(arr[r]==comp){
                    r--;
                    spare--;
                }else{
                    palin=false;
                    break;
                }
            }else{
                l++;r--;
            }
        }
        if(palin){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}