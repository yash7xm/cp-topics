#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int a, b, n;
vector<long long> fact, invfact;

// Fast exponentiation
long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

// Compute nCk modulo MOD
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// Check if number contains only digits a and b
bool isGood(int x) {
    while (x > 0) {
        int d = x % 10;
        if (d != a && d != b)
            return false;
        x /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> n;

    // Precompute factorials and inverse factorials
    fact.resize(n + 1);
    invfact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[n] = modpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    long long answer = 0;

    // Try all possible k
    for (int k = 0; k <= n; k++) {
        int sum = k * b + (n - k) * a;
        if (isGood(sum)) {
            answer = (answer + nCr(n, k)) % MOD;
        }
    }

    cout << answer << "\n";
    return 0;
}

