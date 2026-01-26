#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double p = 1.0 * a / b;
    double q = 1.0 * c / d;

    double ans = p / (p + q - p * q);
    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}

