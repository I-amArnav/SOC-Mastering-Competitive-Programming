#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,y,m,ans;
    cin >> n >>m;
    set<ll> a;
    ll arr[n];
    cin >> arr[0];
    a.insert(arr[0]);
    for(ll i=1; i<n; i++){
        cin>>x;
        arr[i] = x;
        if(a.count(x-1)){
            a.erase(x-1);
            a.insert(x);
        } else{
            a.insert(x);
        }
    }
    ans = a.size();
    while(m--){
        cin >> x >> y;
        if(x>y){
            int temp=x;
            x=y;
            y=temp;
        }
        ll t1 = arr[x-1], t2 = arr[y-1];
        swap(arr[x-1],arr[y-1]);
        for(ll i = x; i<y-1; i++){
            if(arr[i] == t1+1) ans++;
            else if(arr[i] == t1-1) ans--;
            if(arr[i] == t2-1) ans++;
            else if(arr[i] == t2+1) ans--;
        }
        if(t1 == t2-1) ans++;
        else if(t1 == t2+1) ans--;
        cout << ans << '\n';
    }
}