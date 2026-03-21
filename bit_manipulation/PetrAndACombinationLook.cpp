#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];

  for(int mask = 0; mask < (1<<n); ++mask) {
    int sum = 0;
    for(int bit = 0; bit < n; ++bit) {
      if((mask & (1 << bit)) != 0) {
        sum += arr[bit];
      } else {
        sum -= arr[bit];
      }
    }

    if(sum % 360 == 0) {
      cout << "YES" << "\n";
      return;
    }
  }

  cout << "NO" << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
