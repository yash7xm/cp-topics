#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];

  ll res = LLONG_MAX;

  for(int mask = 0; mask < (1 << n); ++mask) {
    ll A = 0, B = 0;

    for(int bit = 0; bit < n; ++bit) {
      if((mask & (1 << bit)) != 0) {
        A += arr[bit];
      } else {
        B += arr[bit];
      }
    }

    res = min(res, abs(A - B));
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
