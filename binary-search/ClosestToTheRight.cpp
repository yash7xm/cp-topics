#include <bits/stdc++.h>
using namespace std;

bool check(int m, int x) {
    return m >= x;
}

int lb(vector<int>& arr, int x) {
    int n = arr.size();
    int lo = 0, hi = n - 1;
    int ans = n;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(arr[mid], x)) {
            ans = mid;      
            hi = mid - 1; 
        } else {
            lo = mid + 1;
        }
    }

    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    while (k--) {
        int x;
        cin >> x;
        cout << lb(arr, x) << '\n';
    }

    return 0;
}
