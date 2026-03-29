#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXBITS = 18;

int pref[MAXN][MAXBITS];

void precompute() {
  for (int i = 1; i < MAXN; i++) {
    for (int bit = 0; bit < MAXBITS; bit++) {

      pref[i][bit] = pref[i - 1][bit];

      if ((i & (1 << bit)) != 0) {
        pref[i][bit]++;
      }
    }
  }
}

void solve() {
  int l, r;
  cin >> l >> r;

  int total_elements = r - l + 1;
  int min_deletions = total_elements;

  for (int bit = 0; bit < MAXBITS; ++bit) {

    int ones_in_range = pref[r][bit] - pref[l - 1][bit];

    int zeros_in_range = total_elements - ones_in_range;

    min_deletions = min(min_deletions, zeros_in_range);
  }

  cout << min_deletions << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precompute();

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}