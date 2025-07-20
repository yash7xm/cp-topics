#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int &x : h) cin >> x;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }

    cout << dp[n - 1] << '\n';
    return 0;
}
