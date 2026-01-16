#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;
static const int MAXN = 200000; // enough for N + max exponent

long long fact[MAXN + 1], invfact[MAXN + 1];

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    long long N, M;
    cin >> N >> M;

    long long ans = 1;

    for (long long p = 2; p * p <= M; p++) {
        if (M % p == 0) {
            int cnt = 0;
            while (M % p == 0) {
                M /= p;
                cnt++;
            }
            ans = ans * nCr(cnt + N - 1, N - 1) % MOD;
        }
    }

    // If M is still > 1, it's a prime
    if (M > 1) {
        ans = ans * nCr(1 + N - 1, N - 1) % MOD;
    }

    cout << ans << "\n";
    return 0;
}

