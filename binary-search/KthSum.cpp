#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a, b;

bool check(ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        // Find the first element in b that is > x - a[i]
        auto it = upper_bound(b.begin(), b.end(), x - a[i]);
        cnt += (it - b.begin());
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll lo = a[0] + b[0];
    ll hi = a.back() + b.back();
    ll ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}