#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int N = 1 << n; // total number of subsets

    // dp[mask] = {minimum number of rides, weight of last ride}
    const long long INF = (long long)1e18;
    vector<pair<long long, long long>> dp(N, {INF, INF});

    // base case: no one taken yet, we are "on" the first ride with weight 0
    dp[0] = {1, 0};

    for (int mask = 0; mask < N; mask++) {
        auto [rides, last_w] = dp[mask];
        if (rides == INF) continue; // unreachable state, skip

        // try to add each person i who is not in 'mask'
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue; // person i already included

            int newMask = mask | (1 << i);
            pair<long long, long long> candidate;

            if (last_w + w[i] <= x) {
                // put this person in the current (last) ride
                candidate = {rides, last_w + w[i]};
            } else {
                // start a new ride with this person
                candidate = {rides + 1, w[i]};
            }

            // keep the better (min) option for dp[newMask]
            dp[newMask] = min(dp[newMask], candidate);
        }
    }

    int fullMask = N - 1;
    cout << dp[fullMask].first << "\n";

    return 0;
}

