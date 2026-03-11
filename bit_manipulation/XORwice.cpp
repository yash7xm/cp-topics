#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;

  int x = 0;
  for(int i = 0; i < 32; ++i) {
    int a_bit = (a & (1 << i)) == 0 ? 0 : 1;
    int b_bit = (b & (1 << i)) == 0 ? 0 : 1;

    if(a_bit == b_bit) {
      if(a_bit == 0) {
        x = (x & ~(1 << i));
      } else {
        x = (x | (1 << i));
      }
    } else {
      x |= (1 << i);
    }
  }

  cout << (a ^ x) + (b ^ x) << "\n";
}

int main() {
  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
