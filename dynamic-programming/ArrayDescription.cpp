#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); // m+2 to avoid out-of-bounds

    // Initialize the first element
    if(arr[0] == 0) {
        for(int j = 1; j <= m; ++j) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    // Fill the DP table
    for(int i = 1; i < n; ++i) {
        if(arr[i] == 0) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                if(j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
            }
        } else {
            int j = arr[i];
            dp[i][j] = dp[i-1][j];
            if(j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            if(j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
        }
    }

    // Calculate the result
    int res = 0;
    for(int j = 1; j <= m; ++j) {
        res = (res + dp[n-1][j]) % mod;
    }

    cout << res << endl;

    return 0;
}