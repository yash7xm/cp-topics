#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;
static const int MAXN = 200000; // enough for 2*n

long long fact[MAXN + 1], invfact[MAXN + 1];

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;

    long long non_decreasing = nCr(2 * n - 1, n - 1);
    long long ans = (2 * non_decreasing % MOD - n + MOD) % MOD;

    cout << ans << "\n";
    return 0;
}

