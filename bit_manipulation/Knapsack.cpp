#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, w;
  cin >> n >> w;

  vector<ll> values(n), wieghts(n);

  for(int i = 0; i < n; ++i) {
    cin >> wieghts[i] >> values[i];
  }

  ll res = 0;

  for(int mask = 0; mask < (1 << n); ++mask) {
    ll curr_val = 0, curr_weight = 0;

    for(int bit = 0; bit < n; ++bit) {
      if((mask & (1 << bit)) != 0) {
        curr_weight += wieghts[bit];
        curr_val += values[bit];
      }
    }

    if(curr_weight <= w) {
      res = max(res, curr_val);
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
