#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int& coin : coins) {
    	cin >> coin;
    }

    vector<long long> dp(x + 1, 0);

    dp[0] = 1;

    for(int coin : coins) {
    	for(int i=coin; i <= x; ++i) {
    		dp[i] = (dp[i] + dp[i-coin]) % mod;
    	}
    }

    cout << dp[x] << endl;

    return 0;
}