#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int count = 0;
        int prev = -2;

        for (int i = 0; i < n; ++i) {
            if (a[i] > prev + 1) {
                ++count;
                prev = a[i];
            }
        }
        cout << count << "\n";
    }

    return 0;
}
