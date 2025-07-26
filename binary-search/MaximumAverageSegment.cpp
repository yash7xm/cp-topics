#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, d;
double a[N];

// Function to check if a subarray of length at least d exists
// such that the average is >= x
bool check(double x, int& L, int& R) {
    vector<double> pref(n + 1, 0.0), min_pref(n + 1, 0.0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (a[i] - x);
        min_pref[i + 1] = min(min_pref[i], pref[i + 1]);
    }

    for (int r = d; r <= n; ++r) {
        if (pref[r] - min_pref[r - d] >= 0) {
            // Find actual indices (1-based)
            for (int l = 0; l <= r - d; ++l) {
                if (pref[r] - pref[l] >= 0) {
                    L = l + 1;
                    R = r;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];

    double low = 0.0, high = 100.0, ans = 0.0;
    int resL = 1, resR = d;

    for (int iter = 0; iter < 60; ++iter) {
        double mid = (low + high) / 2.0;
        int L = -1, R = -1;
        if (check(mid, L, R)) {
            low = mid;
            resL = L;
            resR = R;
            ans = mid;
        } else {
            high = mid;
        }
    }

    cout << resL << " " << resR << "\n";
    return 0;
}
