#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> factors;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                ++cnt;
            }
            factors.emplace_back(p, cnt);
        }
    }
    if (n > 1) {
        factors.emplace_back(n, 1);
    }
    return factors;
}

int max_operations(ll N) {
    if (N == 1) {
        return 0;
    }
    auto factors = factorize(N);
    int total = 0;
    for (auto &[p, e] : factors) {
        int k = 1;
        while (k * (k + 1) / 2 <= e) {
            ++k;
        }
        total += k - 1;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    cout << max_operations(N) << '\n';

    return 0;
}