#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total += coins[i];
    }

    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        for (int j = total; j >= coin; --j) {
            if (dp[j - coin]) {
                dp[j] = true;
            }
        }
    }

    vector<int> sums;
    for (int j = 1; j <= total; ++j) {
        if (dp[j]) {
            sums.push_back(j);
        }
    }

    cout << sums.size() << '\n';
    for (int sum : sums) {
        cout << sum << ' ';
    }
    cout << '\n';

    return 0;
}