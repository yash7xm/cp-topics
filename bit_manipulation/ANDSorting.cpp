#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int x = ~0;
  for(int i=0; i<n; ++i) {
    int el;
    cin >> el;

    if(el != i) x &= el;
  }

  cout << x << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}
