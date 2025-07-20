#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vector<int> weight(n), value(n);
    for(int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // Initialize DP table with 0
    vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(j >= weight[i-1]) {
                // We can either take or not take the current item
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]] + value[i-1]);
            } else {
                // Can't take current item
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][W];

    return 0;
}