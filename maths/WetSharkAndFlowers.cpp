#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long p;
    cin >> n >> p;

    vector<double> q(n);
    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;

        long long cnt = r / p - (l - 1) / p;
        long long len = r - l + 1;

        q[i] = (double)cnt / (double)len;
    }

    double expected = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        expected += q[i] + q[j] - q[i] * q[j];
    }

    expected *= 2000.0;
    cout << fixed << setprecision(10) << expected << "\n";

    return 0;
}

