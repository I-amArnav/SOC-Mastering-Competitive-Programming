#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int breaks = 0;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) breaks++;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        int u = a[x], v = a[y];

        set<int> affected = {u, v};
        for (int i : {u - 1, v - 1}) {
            if (i >= 1) affected.insert(i);
        }

        for (int i : affected) {
            if (i >= 1 && pos[i] > pos[i + 1]) breaks--;
        }

        swap(a[x], a[y]);
        swap(pos[u], pos[v]);

        for (int i : affected) {
            if (i >= 1 && pos[i] > pos[i + 1]) breaks++;
        }

        cout << breaks + 1 << "\n";
    }
}
