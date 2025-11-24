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

        int m = n + 1; // total cities including Bangalore (0..n)

        // Read cost matrix
        vector<vector<long long>> cost(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) {
                    cost[i][j] = 0; // not given in input
                } else {
                    long long x;
                    cin >> x;
                    cost[i][j] = x;
                }
            }
        }

        // Bitmask DP over cities 1..n
        // mask: bits 0..n-1 represent cities 1..n
        int FULL = (1 << n) - 1;

        const long long INF = (long long)1e18;
        // dp[mask][u] = min cost to start at 0, visit exactly 'mask', end at city u (1..n)
        vector<vector<long long>> dp(1 << n, vector<long long>(m, INF));

        // Base cases: directly go from Bangalore (0) to each city u
        for (int u = 1; u <= n; u++) {
            int mask = 1 << (u - 1);
            dp[mask][u] = cost[0][u];
        }

        // Transitions
        for (int mask = 0; mask <= FULL; mask++) {
            for (int u = 1; u <= n; u++) {
                // u must be included in mask as the last visited city
                if (!(mask & (1 << (u - 1)))) continue;

                long long cur = dp[mask][u];
                if (cur == INF) continue; // unreachable state

                // Try to go to a new city v not yet visited
                for (int v = 1; v <= n; v++) {
                    if (mask & (1 << (v - 1))) continue; // v is already in mask

                    int newMask = mask | (1 << (v - 1));
                    long long newCost = cur + cost[u][v];

                    if (newCost < dp[newMask][v]) {
                        dp[newMask][v] = newCost;
                    }
                }
            }
        }

        // Now we have visited all cities 1..n (mask = FULL).
        // Return from each possible last city u back to Bangalore (0)
        long long ans = INF;
        for (int u = 1; u <= n; u++) {
            long long tourCost = dp[FULL][u] + cost[u][0];
            if (tourCost < ans) {
                ans = tourCost;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

