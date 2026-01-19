#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
        if (a[i] == 0) {
            // Single element subsequence works
            cout << "YES\n";
            return 0;
        }
    }

    // Pigeonhole principle shortcut
    if (n >= m) {
        cout << "YES\n";
        return 0;
    }

    // DP over remainders
    vector<bool> dp(m, false), next_dp(m, false);

    for (int i = 0; i < n; i++) {
        next_dp = dp;

        for (int r = 0; r < m; r++) {
            if (dp[r]) {
                next_dp[(r + a[i]) % m] = true;
            }
        }

        next_dp[a[i]] = true; // subsequence consisting only of a[i]

        dp = next_dp;

        if (dp[0]) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

