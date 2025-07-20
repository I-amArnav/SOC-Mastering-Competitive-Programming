#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        string a,b;
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0,counta=0,countb=0;
        string ans;
        while(i<n && j<m){
            if((a[i]<b[j] && counta<k)|| countb==k){
                ans+=a[i];
                i++;
                counta++;
                countb=0;
            }else{
                ans+=b[j];
                j++;
                countb++;
                counta=0;
            }
        }
        ans+='\n';
        cout<<ans;
    }
}