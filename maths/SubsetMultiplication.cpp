#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long g = 0;
        long long ans = 1;

        for (int i = n - 1; i >= 0; i--) {
            g = gcd(g, b[i]);
            ans = lcm(ans, b[i] / g);
        }

        cout << ans << "\n";
    }

    return 0;
}

