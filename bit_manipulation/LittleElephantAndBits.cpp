#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  int idx = -1;

  for(int i=0; i<n; ++i) {
    if(s[i] == '0') {
      idx = i;
      break;
    }
  }

  if(idx != -1) {
    for(int i=0; i<n; ++i) {
      if(i != idx) {
        cout << s[i];
      }
    }
  } else {
    for(int i=0; i<n-1; ++i) {
      cout << s[i];
    }
  }

  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  t = 1;
  while(t--) solve();

  return 0;
}
