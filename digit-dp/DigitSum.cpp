#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string K;
    int D;
    cin >> K >> D;

    int n = K.size();

    // dp[pos][tight][sumMod]
    static long long dp[10005][2][105];
    memset(dp, 0, sizeof(dp));

    dp[0][1][0] = 1;

    for (int pos = 0; pos < n; pos++) {
        int digitLimit = K[pos] - '0';
        for (int tight = 0; tight <= 1; tight++) {
            for (int sumMod = 0; sumMod < D; sumMod++) {

                long long val = dp[pos][tight][sumMod];
                if (val == 0) continue;

                int limit = (tight ? digitLimit : 9);

                for (int d = 0; d <= limit; d++) {
                    int nextTight = (tight && (d == limit));
                    int nextSum = (sumMod + d) % D;

                    dp[pos + 1][nextTight][nextSum] =
                        (dp[pos + 1][nextTight][nextSum] + val) % MOD;
                }
            }
        }
    }

    long long ans = (dp[n][0][0] + dp[n][1][0]) % MOD;

    // subtract the zero number (0..0 all digits)
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << "\n";

    return 0;
}

