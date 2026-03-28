#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;

  long long res = 1;

  for(int i=0; i<k; ++i) {
    res = (res * n) % MOD;
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    
  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
