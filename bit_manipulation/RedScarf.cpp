#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];
  
  int S = 0;
  for(int i=0; i<n; ++i) {
    S ^= arr[i];
  }

  for(int i=0; i<n; ++i) {
    cout << (S ^ arr[i]) << " ";
  }

  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
