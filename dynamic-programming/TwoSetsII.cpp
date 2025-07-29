#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total_sum = n * (n + 1) / 2;

    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target_sum = total_sum / 2;

    vector<long long> dp(target_sum + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = target_sum; j >= i; --j) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    // Since each partition is counted twice, we divide by 2.
    // To handle division under modulo, we multiply by the modular inverse of 2.
    long long inverse_2 = 500000004; // Modular inverse of 2 under mod 1e9+7
    cout << (dp[target_sum] * inverse_2) % mod << endl;

    return 0;
}