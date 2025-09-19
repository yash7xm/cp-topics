#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> b(n), g(m);
    long long sum_b = 0, sum_g = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> g[j];
        sum_g += g[j];
    }

    long long max_b = *max_element(b.begin(), b.end());
    long long min_g = *min_element(g.begin(), g.end());

    if (max_b > min_g) {
        cout << -1 << "\n";
        return 0;
    }

    // Find second maximum in b
    long long max1 = -1, max2 = -1;
    for (long long x : b) {
        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }
    }

    long long ans = 0;
    if (max_b == min_g) {
        ans = sum_b * m + sum_g - max_b * m;
    } else {
        ans = sum_b * m + sum_g - max_b * (m - 1) - max2;
    }

    cout << ans << "\n";
    return 0;
}
