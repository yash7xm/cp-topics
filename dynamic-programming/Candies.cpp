#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        vector<int> prefix(K + 2, 0);
        for (int j = 0; j <= K; ++j) {
            prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % MOD;
        }

        for (int j = 0; j <= K; ++j) {
            int max_k = min(a[i], j);
            int l = max(0, j - max_k);
            dp[i][j] = (prefix[j + 1] - prefix[l] + MOD) % MOD;
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}