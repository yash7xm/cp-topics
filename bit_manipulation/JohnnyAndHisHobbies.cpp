#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<bool> present(1024, false);

  for(int i=0; i<n; ++i) {
    cin >> a[i];
    present[a[i]] = true;
  }

  for(int k = 1; k < 1024; ++k) {
    bool is_valid = true;

    for(int i=0; i < n; ++i) {
      int new_val = a[i] ^ k;

      if(new_val >= 1024 || !present[new_val]) {
        is_valid = false;
        break;
      }
    }

    if(is_valid) {
      cout << k << "\n";
      return;
    }
  }

  cout << -1 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
