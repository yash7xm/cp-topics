#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, S, P;
    cin >> R >> S >> P;

    static double dp[101][101][101] = {};
    dp[R][S][P] = 1.0;

    for (int r = R; r >= 0; r--) {
        for (int s = S; s >= 0; s--) {
            for (int p = P; p >= 0; p--) {
                if (r == 0 && s == 0) continue;
                if (s == 0 && p == 0) continue;
                if (p == 0 && r == 0) continue;

                double cur = dp[r][s][p];
                if (cur == 0.0) continue;

                double T = (double)r*s + (double)s*p + (double)p*r;
                if (T == 0) continue;

                if (r > 0 && s > 0)
                    dp[r][s-1][p] += cur * (r * s) / T;
                if (s > 0 && p > 0)
                    dp[r][s][p-1] += cur * (s * p) / T;
                if (p > 0 && r > 0)
                    dp[r-1][s][p] += cur * (p * r) / T;
            }
        }
    }

    double pr = 0, ps = 0, pp = 0;
    for (int i = 1; i <= R; i++) pr += dp[i][0][0];
    for (int i = 1; i <= S; i++) ps += dp[0][i][0];
    for (int i = 1; i <= P; i++) pp += dp[0][0][i];

    cout << fixed << setprecision(12)
         << pr << " " << ps << " " << pp << "\n";
}

