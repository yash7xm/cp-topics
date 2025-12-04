#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<ll>> a(n, vector<ll>(n));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  int FULL = 1 << n;

  // Precompute score of each subset
  vector<ll> groupScore(FULL, 0);

  for(int mask = 0; mask < FULL; ++mask) {
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
      if(!(mask & (1 << i))) continue;

      for(int j = i + 1; j < n; ++j) {
        if(mask & (1 << j)) {
          sum += a[i][j];
        }
      }
    }

    groupScore[mask] = sum;
  }

  // DP over subsets
  vector<ll> dp(FULL, LLONG_MIN);
  dp[0] = 0;

  for(int mask = 1; mask < FULL; ++mask) {
    for(int sub = mask; sub > 0; sub = (sub - 1) & mask) {
      dp[mask] = max(dp[mask], dp[mask ^ sub] + groupScore[sub]);
    }
  }

  cout << dp[FULL - 1] << "\n";
  return 0;
}
