#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: list of primes up to 70
    vector<int> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23,
        29, 31, 37, 41, 43, 47, 53, 59, 61, 67
    };
    int P = (int)primes.size(); // 19
    int MAXMASK = 1 << P;

    // Step 2: precompute mask for each v in [1..70]
    int valMask[71];
    for (int v = 1; v <= 70; v++) {
        int x = v;
        int mask = 0;
        for (int i = 0; i < P; i++) {
            int p = primes[i];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt ^= 1; // toggle parity
            }
            if (cnt & 1) {
                mask |= (1 << i);
            }
        }
        valMask[v] = mask;
    }

    // Step 3: count occurrences of each value
    int cnt[71] = {0};
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    // Step 4: DP over masks
    vector<long long> dp(MAXMASK, 0), next_dp(MAXMASK);
    dp[0] = 1; // empty subset

    // Process each value from 1 to 70
    for (int v = 1; v <= 70; v++) {
        int c = cnt[v];
        if (c == 0) continue;

        long long evenWays = modPow(2, c - 1); // number of even subsets from c
        long long oddWays  = evenWays;         // same as even

        int mv = valMask[v];

        fill(next_dp.begin(), next_dp.end(), 0);

        for (int mask = 0; mask < MAXMASK; mask++) {
            if (dp[mask] == 0) continue;

            long long cur = dp[mask];

            // pick even number of v's: XOR unchanged
            long long addEven = (cur * evenWays) % MOD;
            next_dp[mask] = (next_dp[mask] + addEven) % MOD;

            // pick odd number of v's: XOR flips by mv
            long long addOdd = (cur * oddWays) % MOD;
            int newMask = mask ^ mv;
            next_dp[newMask] = (next_dp[newMask] + addOdd) % MOD;
        }

        dp.swap(next_dp);
    }

    // dp[0] = number of subsets (including empty) whose product is a perfect square
    long long ans = dp[0] - 1; // exclude empty subset
    if (ans < 0) ans += MOD;
    cout << ans % MOD << "\n";

    return 0;
}
