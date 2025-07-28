// 3d solution

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    // dp[i][j][k] = can we form sum `j` from first `i` coins, with a subset sum `k`?
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(k + 1, vector<bool>(k + 1, false)));
    dp[0][0][0] = true;  // Base case: 0 coins, sum 0, subset sum 0.

    for (int i = 1; i <= n; ++i) {
        int c = coins[i - 1];
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x <= k; ++x) {
                // Case 1: Exclude the i-th coin.
                if (dp[i - 1][j][x]) {
                    dp[i][j][x] = true;
                }
                // Case 2: Include in subset (j) but not in sub-subset (x).
                if (j >= c && dp[i - 1][j - c][x]) {
                    dp[i][j][x] = true;
                }
                // Case 3: Include in both subset (j) and sub-subset (x).
                if (j >= c && x >= c && dp[i - 1][j - c][x - c]) {
                    dp[i][j][x] = true;
                }
            }
        }
    }

    // Collect all possible `x` where dp[n][k][x] is true.
    vector<int> result;
    for (int x = 0; x <= k; ++x) {
        if (dp[n][k][x]) {
            result.push_back(x);
        }
    }

    // Output the result.
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}



























// 2d optimized solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<vector<bool>> dp(k + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;

    for (int coin : coins) {
        for (int s = k; s >= coin; --s) {
            for (int x = k; x >= 0; --x) {
                if (dp[s - coin][x]) {
                    dp[s][x] = true;
                    if (x + coin <= k) {
                        dp[s][x + coin] = true;
                    }
                }
            }
        }
    }

    vector<int> result;
    for (int x = 0; x <= k; ++x) {
        if (dp[k][x]) {
            result.push_back(x);
        }
    }

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}