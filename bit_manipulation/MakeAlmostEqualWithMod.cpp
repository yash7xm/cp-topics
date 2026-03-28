#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];

  for(int j = 1; j <= 60; ++j) {
    ll k = (1LL << j);

    set<ll> rem;

    for(int i = 0; i < n; ++i) {
      rem.insert(arr[i] % k);
    }

    if(rem.size() == 2) {
      cout << k << "\n";
      return ;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
