#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int compute_prefix_xor(int n) {
  if(n % 4 == 0) return n;
  if(n % 4 == 1) return 1;
  if(n % 4 == 2) return n + 1;
  return 0;
}

void solve() {
  int a, b;
  cin >> a >> b;

  ll x = compute_prefix_xor(a-1);
  
  int ans = 0;

  if(x == b) ans = a;
  else if(x != b && (x^b) != a) ans = a + 1;
  else ans = a + 2;

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
