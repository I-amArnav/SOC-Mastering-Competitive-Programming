#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
 if (a.second != b.second) return a.second < b.second;
 return a.first < b.first;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,x,y,mina=INFINITY,d,alter;
        cin >> n;
        vector<pair<ll,ll>> v;
        for(ll i=0; i<n ; i++){
            cin >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(), v.end());
        auto r = v[0];
        v.erase(v.begin());
        sort(v.begin(), v.end());
        x = v[n-2].first - v[0].first +1;
        sort(v.begin(), v.end(), comp);
        y = v[n-2].second - v[0].second +1;
        if( x*y < mina){
            alter = mina;
            mina = x*y;
            d = min(x,y);
        }
        v.push_back(r);
        sort(v.begin(), v.end());
        r = v[n-1];
        v.erase(v.begin()+n-1);
        sort(v.begin(), v.end());
        x = v[n-2].first - v[0].first +1;
        sort(v.begin(), v.end(), comp);
        y = v[n-2].second - v[0].second +1;
        if( x*y < mina){
            alter = mina;
            mina = x*y;
            d = min(x,y);
        }
        v.push_back(r);
        sort(v.begin(), v.end(),comp);
        r = v[0];
        v.erase(v.begin());
        sort(v.begin(), v.end());
        x = v[n-2].first - v[0].first +1;
        sort(v.begin(), v.end(), comp);
        y = v[n-2].second - v[0].second +1;
        if( x*y < mina){
            alter = mina;
            mina = x*y;
            d = min(x,y);
        }
        v.push_back(r);
        sort(v.begin(), v.end(),comp);
        r = v[n-1];
        v.erase(v.begin()+n-1);
        sort(v.begin(), v.end());
        x = v[n-2].first - v[0].first +1;
        sort(v.begin(), v.end(), comp);
        y = v[n-2].second - v[0].second +1;
        if( x*y < mina){
            alter = mina;
            mina = x*y;
            d = min(x,y);
        }
        v.push_back(r);

        if(n>mina) mina += d;
        if(n == 1){
            cout << "1" << '\n';
        } else if(mina > alter) {
            cout << alter << '\n';
        } else cout << mina << '\n';
    }
}