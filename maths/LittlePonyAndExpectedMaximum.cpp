#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    double ans = 0.0;
    for (int k = 1; k <= m; k++) {
        double p = (double)(k - 1) / m;
        ans += 1.0 - pow(p, n);
    }

    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}

