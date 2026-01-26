#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // If someone has probability 1, answer is 1
    for (double x : p) {
        if (fabs(x - 1.0) < 1e-12) {
            cout << fixed << setprecision(12) << 1.0 << "\n";
            return 0;
        }
    }

    sort(p.begin(), p.end());

    double P = 1.0; // product of (1 - p)
    double S = 0.0; // sum of p/(1-p)
    double ans = 0.0;

    // iterate suffix from largest probabilities
    for (int i = n - 1; i >= 0; i--) {
        double x = p[i] / (1.0 - p[i]);
        if (S >= 1.0) break;

        S += x;
        P *= (1.0 - p[i]);

        ans = max(ans, P * S);
    }

    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}


