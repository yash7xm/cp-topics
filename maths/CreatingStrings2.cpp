#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

// Fast exponentiation: computes (base^exp) % MOD
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    // Count frequency of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Precompute factorials
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Compute denominator = product of factorials of frequencies
    long long denominator = 1;
    for (int i = 0; i < 26; i++) {
        denominator = (denominator * fact[freq[i]]) % MOD;
    }

    // Compute answer
    long long numerator = fact[n];
    long long inverse_denominator = modpow(denominator, MOD - 2);
    long long answer = (numerator * inverse_denominator) % MOD;

    cout << answer << "\n";

    return 0;
}

