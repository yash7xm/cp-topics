#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<pair<ll, ll>>& arr, ll h, ll x) {
    ll prev_l = 0;
    ll prev_r = h;

    for(auto [u, d] : arr) {
        ll curr_l = max(h - d, 0LL);
        ll curr_r = min(u, h);

        // Intersect with previous tooth's range considering X
        ll new_l = max(curr_l, prev_l - x);
        ll new_r = min(curr_r, prev_r + x);

        if(new_l > new_r) {
            return false;
        }

        prev_l = new_l;
        prev_r = new_r;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> arr(n);
    ll sum = 0;
    ll max_sum = 0;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        sum += arr[i].first + arr[i].second;
        max_sum = max(max_sum, arr[i].first + arr[i].second);
    }

    ll lo = 0;
    ll hi = max_sum;
    ll ans = 0;

    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if(check(arr, mid, x)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << sum - n * ans << endl;

    return 0;
}