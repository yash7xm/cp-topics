#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, double x, int k) {
    int pieces = 0;
    for(int len : arr) {
        pieces += (int)(len / x);
        if(pieces >= k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    double lo = 0.0;
    double hi = *max_element(arr.begin(), arr.end()) * 1.0;

    while(hi - lo > 1e-6) {
        double mid = lo + (hi - lo) / 2;
        if(check(arr, mid, k)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << fixed << setprecision(6) << lo << endl;

    return 0;
}