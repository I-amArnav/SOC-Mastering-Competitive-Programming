#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<ll,3>> R(n);
    for(int i = 0; i < n; i++){
        cin >> R[i][0] >> R[i][1];
        R[i][2] = i;
    }

    vector<ll> contains(n, 0), contained_by(n, 0);
    indexed_set S;
    sort(R.begin(), R.end(),
         [](auto &A, auto &B){
           if(A[0] != B[0]) return A[0] < B[0];
           return A[1] > B[1];
         });

    S.clear();
    for(auto &t : R){
        ll a = t[0], b = t[1], idx = t[2];
        ll less_than_b = S.order_of_key({(int)b, -1000000000});
        contained_by[idx] = (ll)S.size() - less_than_b;
        S.insert({(int)b, (int)idx});
    }
    sort(R.begin(), R.end(),
        [](auto &A, auto &B){
            if(A[0] != B[0]) return A[0] > B[0];
            return A[1] < B[1];
        });
    S.clear();
    for(auto &t : R){
        ll a = t[0], b = t[1], idx = t[2];
        contains[idx] = S.order_of_key({(int)b + 1, -1000000000});
        S.insert({(int)b, (int)idx});
    }
    for(int i = 0; i < n; i++){
        cout << contains[i] << (i+1 < n ? ' ' : '\n');
    }
    for(int i = 0; i < n; i++){
        cout << contained_by[i] << (i+1 < n ? ' ' : '\n');
    }
}