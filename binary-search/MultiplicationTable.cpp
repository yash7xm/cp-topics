#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Returns true if mid is greater than or equal to the median
bool check(ll mid, ll n) {
    ll count = 0;
    for (ll i = 1; i <= n; ++i) {
        count += min(n, mid / i);
    }
    return count >= (n * n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll lo = 1, hi = n * n, ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid, n)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
