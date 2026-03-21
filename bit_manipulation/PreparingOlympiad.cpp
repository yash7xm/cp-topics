#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, l, r, x;
  cin >> n >> l >> r >> x;

  vector<ll> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];
  
  int res = 0;

  for(int mask = 0; mask < (1 << n); ++mask) {
    ll sum = 0, min_val = 1e9, max_val = 0;

    if(__builtin_popcount(mask) < 2) continue;

    for(int i = 0; i < n; ++i) {
      if((mask & (1 << i)) != 0) {
        sum += arr[i];
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
      }
    }

    if(sum >= l && sum <= r && (max_val - min_val) >= x) {
      res++;
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
