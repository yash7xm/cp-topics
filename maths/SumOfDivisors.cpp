#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

// sum from l to r = (l + r) * (r - l + 1) / 2
long long sum_range(long long l, long long r) {
    long long cnt = (r - l + 1) % MOD;
    long long s = (l + r) % MOD;
    // multiply then divide by 2 using modular inverse
    return (s * cnt % MOD) * ((MOD + 1) / 2) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long ans = 0;

    for (long long d = 1; d <= n; ) {
        long long q = n / d;
        long long r = n / q;
        long long contrib = q % MOD * sum_range(d, r) % MOD;
        ans = (ans + contrib) % MOD;
        d = r + 1;
    }

    cout << ans << "\n";
    return 0;
}

