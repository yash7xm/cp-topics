#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> grid(n + 1, vector<char>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Initialize the starting point
    if (grid[1][1] != '*') {
        dp[1][1] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue; // Skip the starting point

            if (grid[i][j] == '*') {
                dp[i][j] = 0; // Trap, no paths here
                continue;
            }

            // Paths from above (i-1, j) and from the left (i, j-1)
            if (i > 1 && grid[i-1][j] != '*') {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            }
            if (j > 1 && grid[i][j-1] != '*') {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}