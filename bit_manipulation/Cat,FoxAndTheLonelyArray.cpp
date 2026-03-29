#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int k = 1;
  for (int i = 0; i < 20; ++i) {
    int last = 0;
    bool found = false;

    for (int j = 1; j <= n; ++j) {
      if ((a[j - 1] & (1 << i)) != 0) {
        k = max(k, j - last);
        last = j;
        found = true;
      }
    }
    if (found) {
      k = max(k, n - last + 1);
    }
  }
  cout << k << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}