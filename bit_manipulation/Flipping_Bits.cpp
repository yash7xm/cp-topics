#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n;
  cin >> n;

  cout << n ^ 0xFFFFFFFF << "\n";

  cout << ~(uint32_t(n)) << "\n";

  return 0;
}
