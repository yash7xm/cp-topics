#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int& c : coins) cin >> c;

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=x; ++i) {
        for(int c : coins) {
            if(i-c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;

    return 0;
}