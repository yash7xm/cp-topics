#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int addmod(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  // a[i][j]: compatability of man i and woman j
  // using 0-based indexing 
  vector<vector<int>> a(n, vector<int>(n));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  int totalMasks = 1 << n;
  vector<int> dp(totalMasks, 0);

  // Base case: no men matched, no women used 
  dp[0] = 1;

  // Iterate over all masks 
  for(int mask = 0; mask < totalMasks; ++mask) {
    // How many men are already matched?
    int i = __builtin_popcount(mask);

    // If i == n, we've already mathced all men, no need to continue
    if(i > n) continue;

    // if there are 0 ways to reach this mask, skip
    if(dp[mask] == 0) continue;

    // Try to match man i with some compatible woman j
    for(int j = 0; j < n; ++j) {
      // If women j is not used yet AND compatible with man i 
      if(!(mask & (1 << j)) && a[i][j] == 1) {
        int newMask = mask | (1 << j);
        dp[newMask] = addmod(dp[newMask], dp[mask]);
      }
    }
  }

  // Answer: all n men mathced with all n women(all bits set) 
  int fullMask = (1 << n) - 1;
  cout << dp[fullMask] << "\n";

  return 0;
}
