#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cout << fixed << setprecision(6);

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // Find last index where a[i] != i
        int last = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) last = i;
        }

        double fail_prob = 1.0;

        for (int i = 0; i < m; i++) {
            int r;
            double p;
            cin >> r >> p;
            if (r >= last) {
                fail_prob *= (1.0 - p);
            }
        }

        if (last == 0) {
            cout << 1.0 << "\n";
        } else {
            cout << (1.0 - fail_prob) << "\n";
        }
    }
}

