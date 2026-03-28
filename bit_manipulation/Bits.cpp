#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll l, r;
  cin >> l >> r;

  ll x = l;

  while((x | (x + 1)) <= r) {
    x = x | (x + 1);
  }

  cout << x << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
