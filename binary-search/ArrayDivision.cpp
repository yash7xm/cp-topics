#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(const vector<int>& a, ll maxSum, int k) {
    int cnt = 1;
    ll curr = 0;
    for (int x : a) {
        if (curr + x > maxSum) {
            cnt++;
            curr = x;
        } else {
            curr += x;
        }
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    ll lo = *max_element(a.begin(), a.end());
    ll hi = accumulate(a.begin(), a.end(), 0LL);
    ll ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(a, mid, k)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
