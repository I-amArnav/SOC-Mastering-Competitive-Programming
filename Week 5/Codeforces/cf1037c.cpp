#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T; 
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> h(n);
        ll maxh = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            maxh = max(maxh, h[i]);
        }
        set<pair<ll,int>> alive;
        for (int i = 0; i < n; i++)
            alive.emplace(h[i], i);

        queue<pair<int,ll>> q;
        q.push({k-1, 0});
        alive.erase({h[k-1], k-1});

        bool success = (h[k-1] == maxh);
        while (!q.empty() && !success) {
            auto [tower, time] = q.front();
            q.pop();

            ll delta = h[tower] - time;
            if (delta < 0) continue;            
            ll lo = time;                       
            ll hi = 2*h[tower] - time;          
            auto it = alive.lower_bound({lo, -1});
            while (it != alive.end() && it->first <= hi) {
                auto [hj, j] = *it;
                ll travel = llabs(hj - h[tower]);
                ll arrive = time + travel;
                if (arrive < hj) {
                    if (hj == maxh) {
                        success = true;
                        break;
                    }
                    q.push({j, arrive});
                }
                it = alive.erase(it);
            }
        }
        cout << (success ? "YES\n" : "NO\n");
    }
}
