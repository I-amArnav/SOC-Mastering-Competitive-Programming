#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,x;
    cin>>x>>n;
    multiset<int> p;
    p.insert(0);
    p.insert(x);
    multiset<int>l;
    l.insert(x);
    fori(n){
        int pos;
        cin>>pos;
        auto it = p.lower_bound(pos);
        l.erase(l.find(*it-*prev(it)));
        l.insert(*it-pos);
        l.insert(pos-*prev(it));
        p.insert(pos);
        cout<<*l.rbegin()<<" ";
    }
}