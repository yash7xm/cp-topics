#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];

  for(int bit = 0; bit < 20; ++bit) {
    int ones = 0;
    ll mask = (1LL << bit);
    for(ll a : arr) {
      if((a & mask) != 0) ones++;
    }

    for(int i = 0; i < ones; ++i) {
      arr[i] |= mask;
    }

    for(int i=ones; i < n; ++i) {
      if((arr[i] & mask) != 0) {
        arr[i] = (arr[i] & (~mask));
      }
    }
  }

  ll res = 0;
  for(ll a : arr) res += a*a;

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
