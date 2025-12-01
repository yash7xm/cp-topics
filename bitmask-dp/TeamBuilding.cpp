#include <bits/stdc++.h>
using namespace std;

static const long long NEG_INF = -(1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, k;
    cin >> n >> p >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<long long>> s(n, vector<long long>(p));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> s[i][j];

    // Sort people by decreasing audience strength
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y) {
        return a[x] > a[y];
    });

    int MAX_MASK = 1 << p;
    vector<long long> dp(MAX_MASK, NEG_INF);
    dp[0] = 0;

    // Process each person
    for (int idx = 0; idx < n; idx++) {
        int i = order[idx];
        vector<long long> new_dp = dp;

        for (int mask = 0; mask < MAX_MASK; mask++) {
            if (dp[mask] == NEG_INF) continue;

            int players_used = __builtin_popcount(mask);
            int audience_used = idx - players_used;

            // Option 1: use as audience
            if (audience_used < k) {
                new_dp[mask] = max(new_dp[mask], dp[mask] + a[i]);
            }

            // Option 2: use as player
            for (int j = 0; j < p; j++) {
                if (!(mask & (1 << j))) {
                    int newMask = mask | (1 << j);
                    new_dp[newMask] = max(
                        new_dp[newMask],
                        dp[mask] + s[i][j]
                    );
                }
            }
        }
        dp.swap(new_dp);
    }

    int fullMask = (1 << p) - 1;
    cout << dp[fullMask] << "\n";

    return 0;
}

