#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  
  vector<ll> msb_count(32, 0);
  for(int i=0; i<n; ++i) {
    int x;
    cin >> x;

    int msb = 31 - __builtin_clz(x);
    msb_count[msb]++;
  }

  ll res = 0;
  for(ll c : msb_count) {
    if(c >= 2) {
      res += (c * (c - 1)) / 2;
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
