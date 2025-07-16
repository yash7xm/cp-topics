#include <bits/stdc++.h>
using namespace std;

bool isEnough(vector<int>& arr, long long time, long long t) {
    long long items = 0;
    for (int machineTime : arr) {
        items += time / machineTime;
        if (items >= t) return true;  // early stop
    }
    return false;
}

void solve() {
    int n;
    long long t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long lo = 1;
    long long hi = *max_element(arr.begin(), arr.end()) * t;
    long long ans = hi;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (isEnough(arr, mid, t)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
