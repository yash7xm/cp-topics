#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1e5;
const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<int> weight(n), value(n);
    for(int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // vector<vector<long long>> dp(n + 1, vector<long long>(MAX_VAL + 1, INF));
    // dp[0][0] = 0;

    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 0; j <= MAX_VAL; ++j) {
    //         dp[i][j] = dp[i-1][j];
    //         if(j >= value[i-1] && dp[i-1][j - value[i-1]] != INF) {
    //             if(dp[i-1][j - value[i-1]] + weight[i-1] <= w) {
    //                 dp[i][j] = min(dp[i][j], dp[i-1][j - value[i-1]] + weight[i-1]);
    //             }
    //         }
    //     }
    // }

    // int res = 0;
    // for(int j = MAX_VAL; j >= 0; --j) {
    //     if(dp[n][j] <= w && dp[n][j] != INF) {
    //         res = j;
    //         break;
    //     }
    // }

    // cout << res << endl;

    vector<long long> dp(MAX_VAL + 1, INF);
    dp[0] = 0;

    for(int i=0; i<n; ++i) {
    	for(int j=MAX_VAL; j>=value[i]; --j) {
    		if(dp[j - value[i]] != INF) {
    			if(dp[j-value[i]] + weight[i] <= w) {
    				dp[j] = min(dp[j], dp[j-value[i]] + weight[i]);
    			}
    		}
    	}
    }

    int res = 0;
    for(int j=MAX_VAL; j>=0; --j) {
    	if(dp[j] <= w && dp[j] != INF) {
    		res = j;
    		break;
    	}
    }

    cout << res << endl;

    return 0;
}