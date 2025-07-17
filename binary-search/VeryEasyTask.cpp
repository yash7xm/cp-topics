#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int n, int x, int y, ll k) {
    return (k / x) + (k / y) >= n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    if (n == 1) {
        cout << min(x, y) << endl;
        return 0;
    }

    ll lo = 1;
    ll hi = (ll)max(x, y) * n;
    ll ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(n, x, y, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans + min(x, y) << endl;

    return 0;
}