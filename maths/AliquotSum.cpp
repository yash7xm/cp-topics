#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> s(MAXN + 1, 0);

    // Build aliquot sum using harmonic divisor contribution
    for (int d = 1; d <= MAXN / 2; d++) {
        for (int m = 2 * d; m <= MAXN; m += d)
            s[m] += d;
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (s[n] == n) cout << "perfect\n";
        else if (s[n] > n) cout << "abundant\n";
        else cout << "deficient\n";
    }

    return 0;
}

