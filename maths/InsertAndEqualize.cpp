#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // n = 1 case
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        sort(a.begin(), a.end());

        // Compute gcd of adjacent differences
        long long x = 0;
        for (int i = 1; i < n; i++) {
            x = gcd(x, a[i] - a[i - 1]);
        }
        if (x == 0) x = 1;

        long long mx = a.back();
        long long sum = accumulate(a.begin(), a.end(), 0LL);

        // Find best res = mx - k*x not in array
        long long res = mx;
        int j = n - 1;

        while (true) {
            // Move j to the last element <= res
            while (j >= 0 && a[j] > res) {
                j--;
            }

            // If res is missing, stop
            if (j < 0 || a[j] != res) {
                break;
            }

            // Otherwise try next smaller value
            res -= x;
        }

        long long answer = (mx * (n + 1) - (sum + res)) / x;
        cout << answer << "\n";
    }

    return 0;
}

