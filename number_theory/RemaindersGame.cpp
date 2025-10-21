#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> c(n);
  for(int i=0; i<n; ++i) cin >> c[i];

  ll L = 1;

  for(int i=0; i<n; ++i) {
    ll g = gcd(L, c[i]);

    ll mul = c[i] / g;

    L = (L * mul) % k;

    if(L % k == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  
  if(L % k == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
