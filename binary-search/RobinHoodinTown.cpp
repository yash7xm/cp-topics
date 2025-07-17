#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<int>& arr, ll x, ll sum) {
    int n = arr.size();
    double avg = static_cast<double>(sum + x) / n;
    double half_avg = avg / 2.0;

    int count = 0;
    for (int val : arr) {
        if (val < half_avg) {
            count++;
        }
    }
    return count > n / 2;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }

    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    
    // Check if x=0 already works
    if (check(arr, 0, sum)) {
        cout << 0 << endl;
        return;
    }

    ll lo = 0;
    ll hi = 2 * 1e14;
    ll ans = -1;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(arr, mid, sum)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}