#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  vector<int> a(n);
  ll ans = 0;
  for(int i=0; i<n; ++i) {
    cin >> a[i];
    ans += __builtin_popcount(a[i]);
  }

  for(int bit = 0; bit <= 60; ++bit) {
    ll cost = (1LL << bit);

    for(int x : a) {
      if(((x & cost) == 0) && k >= cost) {
        ans++;
        k -= cost;
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
