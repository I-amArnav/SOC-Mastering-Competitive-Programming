#include<bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
typedef long long ll;
const ll mod=1e9+7;

int main(){
    int n;
    cin >> n;
    vector<long long> x(n);
    fori(n){cin >> x[i];}
    sort(x.begin(), x.end());
    cout<<x[(n-1)/2];
}