#include <bits/stdc++.h>
using namespace std;

long long sqr(long long x) { return x * x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long xs, ys;
    int n;
    if (!(cin >> xs >> ys)) return 0;
    cin >> n;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Precompute distances
    vector<long long> d0(n);                 // distance^2 from bag (0) to i
    vector<vector<long long>> dist(n, vector<long long>(n)); // between objects

    for (int i = 0; i < n; i++) {
        d0[i] = sqr(x[i] - xs) + sqr(y[i] - ys);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            dist[i][j] = dx * dx + dy * dy;
        }
    }

    int N = 1 << n;
    const long long INF = (long long)4e18;

    vector<long long> dp(N, INF);
    vector<int> preMask(N, -1);
    vector<short> takeI(N, -1), takeJ(N, -1);

    dp[0] = 0;

    for (int mask = 0; mask < N; mask++) {
        if (dp[mask] == INF) continue;

        // find first not-taken object
        int i = -1;
        for (int t = 0; t < n; t++) {
            if (!(mask & (1 << t))) {
                i = t;
                break;
            }
        }
        if (i == -1) continue; // all taken

        // Option A: take only i
        int mask1 = mask | (1 << i);
        long long cost1 = dp[mask] + 2 * d0[i];
        if (cost1 < dp[mask1]) {
            dp[mask1] = cost1;
            preMask[mask1] = mask;
            takeI[mask1] = i;
            takeJ[mask1] = -1;
        }

        // Option B: take i and some j > i
        for (int j = i + 1; j < n; j++) {
            if (mask & (1 << j)) continue;
            int mask2 = mask1 | (1 << j);
            long long cost2 = dp[mask] + d0[i] + dist[i][j] + d0[j];
            if (cost2 < dp[mask2]) {
                dp[mask2] = cost2;
                preMask[mask2] = mask;
                takeI[mask2] = i;
                takeJ[mask2] = j;
            }
        }
    }

    int fullMask = (1 << n) - 1;
    cout << dp[fullMask] << "\n";

    // Reconstruct path
    vector<vector<int>> trips;
    int cur = fullMask;
    while (cur != 0) {
        int pm = preMask[cur];
        int i = takeI[cur];
        int j = takeJ[cur];

        vector<int> trip;
        trip.push_back(0);
        trip.push_back(i + 1); // convert to 1-based for output
        if (j != -1) trip.push_back(j + 1);

        trips.push_back(trip);
        cur = pm;
    }

    reverse(trips.begin(), trips.end());

    for (auto &trip : trips) {
        for (int v : trip) {
            cout << v << " ";
        }
    }
    cout << "0\n";

    return 0;
}
