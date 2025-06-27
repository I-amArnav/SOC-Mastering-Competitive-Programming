#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<2*n-1<<endl;
        cout<<n<<" 1 "<<n<<endl;
        for(int i=1;i<n;i++){
            cout<<i<<" 1 "<<i<<endl;
            cout<<i<<" "<<i+1<<" "<<n<<endl;
        }
    }
}