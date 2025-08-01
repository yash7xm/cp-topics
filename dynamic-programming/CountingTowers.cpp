#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute results for all n up to MAX_N
    vector<ll> totalWays(MAX_N + 1);

    ll separate = 1;  // Represents the state where the last layer is two separate blocks
    ll joined = 1;     // Represents the state where the last layer is a single 2x1 block

    totalWays[1] = (seprate + joined) % MOD;

    for (int i = 2; i <= MAX_N; ++i) {
        ll new_seprate = (4 * seprate + joined) % MOD;
        ll new_joined = (2 * joined + seprate) % MOD;

        totalWays[i] = (new_seprate + new_joined) % MOD;

        // Update the states for the next iteration
        seprate = new_seprate;
        joined = new_joined;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << totalWays[n] << '\n';
    }

    return 0;
}
