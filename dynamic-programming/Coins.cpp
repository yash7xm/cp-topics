#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> p(n+1);
    for(int i=1; i<=n; ++i) {
    	cin >> p[i];
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0));
    dp[0][0] = 1.0;

    for(int i=1; i <= n; ++i) {
    	for(int j=0; j <= i; ++j) {
    		if(j == 0) {
    			dp[i][j] = dp[i-1][j] * (1 - p[i]);
    		} else {
    			dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
    		}
    	}
    }

    double res = 0.0;

    for(int j = (n+1) / 2; j <= n; ++j) {
    	res += dp[n][j];
    }

    cout << fixed << setprecision(10) << res << endl;

    return 0;
}


// Space optimized
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> p(n+1);
    for(int i=1; i<=n; ++i) {
    	cin >> p[i];
    }

    vector<double> dp(n+1, 0.0);
    dp[0] = 1.0;

    for(int i=1; i<=n; ++i) {
    	for(int j=i; j>=0; j--) {
    		if(j == 0) {
    			dp[j] = dp[j] * (1-p[i]);
    		} else {
    			dp[j] = dp[j-1] * p[i] + dp[j] * (1 - p[i]);
    		}
    	}
    }

    double res = 0.0;
    for(int j=(n+1)/2; j <= n; ++j) {
    	res += dp[j];
    }

    cout << fixed << setprecision(10) << res << endl;

    return 0;
}
