#include <bits/stdc++.h>
using namespace std;

long long dp[1 << 19][19];
bool G[19][19];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a][b] = G[b][a] = true;
    }

    long long ans = 0;

    // Iterate starting points
    for (int start = 0; start < n; start++) {

        // Clear dp
        int LIMIT = 1 << n;
        for (int mask = 0; mask < LIMIT; mask++)
            for (int i = 0; i < n; i++)
                dp[mask][i] = 0;

        dp[1 << start][start] = 1;

        // Iterate all masks that include 'start'
        for (int mask = 1 << start; mask < LIMIT; mask++) {
            if (!(mask & (1 << start))) continue;

            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;       // u must be in mask
                long long ways = dp[mask][u];
                if (!ways) continue;

                // Try extending to a new vertex v
                for (int v = start + 1; v < n; v++) {   // ensure v > start
                    if (mask & (1 << v)) continue;      // already visited
                    if (!G[u][v]) continue;             // must be adjacent

                    int newMask = mask | (1 << v);
                    dp[newMask][v] += ways;
                }

                // Try closing a cycle (only if size >= 3)
                if (__builtin_popcount(mask) >= 3 && G[u][start]) {
                    ans += ways;
                }
            }
        }
    }

    // Each cycle counted twice (once per direction)
    cout << ans / 2 << "\n";
}
