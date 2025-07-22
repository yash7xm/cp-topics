#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=n; ++i) {
    	int num = i;
    	while(num > 0) {
    		int digit = num % 10;
    		if(digit != 0 && i-digit >= 0) {
    			dp[i] = min(dp[i], dp[i-digit] + 1);
    		}
    		num /= 10;
    	}
    }

    cout << dp[n] << endl;

    return 0;
}