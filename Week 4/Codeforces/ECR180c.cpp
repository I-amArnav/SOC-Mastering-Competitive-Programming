#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        fori(n)(cin>>a[i]);
        ll count=0;
        for (int k=2; k<n;++k) {
            int threshold=max(a[k], a[n-1]-a[k]);
            for (int j=k-1;j>=1;--j) {
                int l=0,r=j-1,pos=j;
                while(l<=r) {
                    int m=(l+r)/2;
                    if(a[m]+a[j]>threshold){
                        pos=m;
                        r=m-1;
                    }else{
                        l=m+1;
                    }
                }
                count+=(j - pos);
            }
        }
        cout<<count<<"\n";
    }
}
