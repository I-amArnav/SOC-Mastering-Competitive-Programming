#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
ll mod = 1e9+7;
int n;
vector<ll> tree; // changed to ll for large values

void add(int nod, ll val) {
	for(; nod <= n; nod += (nod & -nod))
		tree[nod] = (tree[nod] + val) % mod;
}

ll compute(int nod) {
	ll ans = 0;
	for(; nod > 0; nod -= (nod & -nod))
		ans = (ans + tree[nod]) % mod;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<int> x(n + 1);
	vector<int> sorted(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		sorted[i] = x[i];
	}

	// Coordinate compression
	sort(sorted.begin() + 1, sorted.end());
	sorted.erase(unique(sorted.begin() + 1, sorted.end()), sorted.end());
	unordered_map<int, int> compress;
	for(int i = 1; i < sorted.size(); i++) {
		compress[sorted[i]] = i;
	}
	
	tree.assign(n + 2, 0); // +2 to be safe

	ll total = 0;
	for(int i = 1; i <= n; i++) {
		int idx = compress[x[i]];
		ll cnt = (compute(idx - 1) + 1) % mod; // increasing subsequences ending at x[i]
		add(idx, cnt);
		total = (total + cnt) % mod;
	}

	cout << total << '\n';
	return 0;
}
