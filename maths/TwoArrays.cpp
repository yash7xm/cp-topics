#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int N = n + 2 * m - 1;
    int K = 2 * m;

    vector<long long> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    long long ans = fact[N];
    ans = ans * invfact[K] % MOD;
    ans = ans * invfact[N - K] % MOD;

    cout << ans << "\n";
    return 0;
}

