#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; ++i) {
    	for(int j=1; j<=m; ++j) {
    		if(s[i-1] == t[j-1]) {
    			dp[i][j] = 1 + dp[i-1][j-1];
    		} else {
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }

    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            lcs += s[i-1];
            --i;
            --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << lcs << "\n";

    return 0;
}