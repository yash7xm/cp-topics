#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

bool check(ld c, ld x) {
    return x * x + sqrt(x) >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ld c;
    cin >> c;

    ld lo = 0.0, hi = sqrt(c);
    while (hi - lo > 1e-6) {
        ld mid = lo + (hi - lo) / 2;
        if (check(c, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(6) << lo << '\n';
    return 0;
}
