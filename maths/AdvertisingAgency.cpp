#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

long long modpow(long long base, long long exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials up to 1000
    const int MAXN = 1000;
    vector<long long> fact(MAXN + 1), invfact(MAXN + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    auto nCr = [&](int n, int r) {
        if (r < 0 || r > n) return 0LL;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    };

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end(), greater<int>());

        int x = a[k - 1];
        int cntNeed = 0, cntTotal = 0;

        for (int i = 0; i < k; i++)
            if (a[i] == x) cntNeed++;

        for (int i = 0; i < n; i++)
            if (a[i] == x) cntTotal++;

        cout << nCr(cntTotal, cntNeed) << "\n";
    }

    return 0;
}

