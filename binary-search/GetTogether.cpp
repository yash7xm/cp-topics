#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

bool canMeet(const vector<pair<ld, ld>>& arr, ld T) {
    ld left = -1e18, right = 1e18;

    for(auto [x, v] : arr) {
        left = max(left, x - v * T);
        right = min(right, x + v * T);
    }

    return left <= right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ld, ld>> arr(n);  // Initialize with size n
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    ld lo = 0, hi = 2e14;

    for(int iter = 0; iter < 100; ++iter) {
        ld mid = (lo + hi) / 2;
        if(canMeet(arr, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(10) << hi << '\n';

    return 0;
}