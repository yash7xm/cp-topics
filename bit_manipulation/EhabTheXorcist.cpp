#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll u, v;
  cin >> u >> v;

  if (u > v || (v - u) % 2 != 0) {
    cout << -1 << "\n";
    return;
  }

  if (u == 0 && v == 0) {
    cout << 0 << "\n";
    return;
  }

  if (u == v) {
    cout << 1 << "\n";
    cout << u << "\n";
    return;
  }

  ll x = (v - u) / 2;

  if ((u & x) == 0) {
    cout << 2 << "\n";
    cout << (u + x) << " " << x << "\n";
    return;
  }

  cout << 3 << "\n";
  cout << u << " " << x << " " << x << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}