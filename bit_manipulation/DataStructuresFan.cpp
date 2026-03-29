#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> pref(n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] ^ a[i];
  }

  string s;
  cin >> s;

  int x0 = 0, x1 = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      x0 ^= a[i];
    } else {
      x1 ^= a[i];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r;
      cin >> l >> r;

      int range_xor = pref[r] ^ pref[l - 1];

      x0 ^= range_xor;
      x1 ^= range_xor;

    } else if (type == 2) {
      int g;
      cin >> g;

      if (g == 0) {
        cout << x0 << " ";
      } else {
        cout << x1 << " ";
      }
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}