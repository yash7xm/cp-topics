#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    vector<vector<long long>> dp(H, vector<long long>(W, 0));
    dp[0][0] = 1;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                dp[i][j] = dp[i][j-1];
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout << dp[H-1][W-1] << endl;

    return 0;
}