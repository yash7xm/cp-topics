#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

// Computes sum of integers from L to R modulo MOD
// sum = (R-L+1)*(L+R)/2
long long range_sum(long long L, long long R) {
    long long cnt = (R - L + 1) % MOD;
    long long sumLR = ( (L % MOD) + (R % MOD) ) % MOD;

    // multiply safely, handle /2 under mod
    long long res = (cnt * sumLR) % MOD;

    // divide by 2 modulo MOD
    if (res % 2 == 0) res /= 2;
    else res = (res + MOD) / 2;

    return res % MOD;
}

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    long long d = 1;

    while (d <= n) {
        long long q = n / d;          // floor(n/d)
        long long r = n / q;          // last d giving same q

        long long sumD = range_sum(d, r);
        ans = (ans + (sumD * (q % MOD)) % MOD) % MOD;

        d = r + 1;
    }

    cout << ans % MOD;
}

