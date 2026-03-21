#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  ll total_sum = 0;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    total_sum += a[i];
  }

  vector<ll> p(n+1);
  for(int i = 1; i <= n; ++i) p[i] = p[i-1] ^ a[i-1];

  ll res = 0;

  for(int bit = 0; bit <= 28; ++bit) {
    ll count_0 = 1;
    ll count_1 = 0;

    for(int i = 1; i <= n; ++i) {
      if((p[i] & (1LL << bit)) == 0) {
        count_0++;
      } else {
        count_1++;
      }
    }

    ll pairs = count_0 * count_1;

    res += pairs * (1LL << bit);
  }

  cout << res - total_sum << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
