#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long a = -1, b = -1, c = -1;

        // 1) Find first divisor a
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                a = i;
                break;
            }
        }

        if (a == -1) {
            // n is prime -> cannot split into 3 >=2 factors
            cout << "NO\n";
            continue;
        }

        long long m = n / a;

        // 2) Find second divisor b of m, different from a
        for (long long i = 2; i * i <= m; ++i) {
            if (m % i == 0 && i != a) {
                b = i;
                break;
            }
        }

        if (b == -1) {
            // Could not find a suitable second factor
            cout << "NO\n";
            continue;
        }

        // 3) Compute c
        c = n / (a * b);

        // 4) Check distinctness and >= 2
        if (c > 1 && c != a && c != b) {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
