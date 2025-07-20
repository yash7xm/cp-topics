#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, 6); ++j) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    cout << dp[n] << endl;

    return 0;
}