#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n), b(n), ans(n);
        vector<int> aid(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        iota(aid.begin(), aid.end(), 0);

        // Sort aid according to values of a
        sort(aid.begin(), aid.end(), [&](int l, int r) {
            return a[l] < a[r];
        });

        sort(b.begin(), b.end());

        for (int i = 0; i < x; i++) {
            ans[aid[n - x + i]] = b[i];
        }

        for (int i = x; i < n; i++) {
            ans[aid[i - x]] = b[i];
        }

        int temp = x;
        for (int i = 0; i < n; i++) {
            if (a[i] > ans[i]) {
                temp--;
            }
        }

        if (temp == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
