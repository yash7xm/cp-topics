#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

struct Mat {
    ll a[2][2];
};

Mat mul(Mat A, Mat B) {
    Mat C{};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
    return C;
}

Mat mpow(Mat base, ll exp) {
    Mat res{{{1,0},{0,1}}};
    while (exp) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll ans = 1;
        for (ll p = 2; p * p <= k; p++) {
            if (k % p == 0) {
                ll e = 0;
                while (k % p == 0) {
                    k /= p;
                    e++;
                }

                Mat T{{{0,1},{1,1}}};
                Mat R = mpow(T, n - 1);

                ll ways = (R.a[0][0] * e + R.a[0][1] * 1
                          + R.a[1][0] * e + R.a[1][1] * 1) % MOD;
                ans = ans * ways % MOD;
            }
        }

        if (k > 1) {
            Mat T{{{0,1},{1,1}}};
            Mat R = mpow(T, n - 1);
            ll ways = (R.a[0][0] + R.a[0][1]
                      + R.a[1][0] + R.a[1][1]) % MOD;
            ans = ans * ways % MOD;
        }

        cout << ans << "\n";
    }
}

