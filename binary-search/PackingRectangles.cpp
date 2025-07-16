#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canFit(ll x, ll w, ll h, ll n) {
    // Calculate the maximum number of rectangles that can fit along the width and height
    ll max_w = x / w;
    ll max_h = x / h;
    // To avoid overflow, check if max_w * max_h >= n
    // If max_w or max_h is zero, it's impossible to fit any rectangles
    if (max_w == 0 || max_h == 0) return false;
    // Check if max_w >= ceil(n / max_h)
    return max_w >= (n + max_h - 1) / max_h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll w, h, n;
    cin >> w >> h >> n;

    ll lo = 1;
    ll hi = max(w, h) * n;
    ll ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canFit(mid, w, h, n)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;	
        }
    }

    cout << ans << "\n";
    return 0;
}
