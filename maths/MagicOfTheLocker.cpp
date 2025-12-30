#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long res = 1 % MOD;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n <= 3) {
            cout << n % MOD << '\n';
            continue;
        }

        long long k = n / 3;
        long long r = n % 3;

        long long ans = 0;
        if (r == 0) {
            ans = modpow(3, k);
        } else if (r == 1) {
            ans = (modpow(3, k - 1) * 4) % MOD;
        } else { // r == 2
            ans = (modpow(3, k) * 2) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}

