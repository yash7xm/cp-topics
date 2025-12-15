#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--) {
    long long a, b, k;
    cin >> a >> b >> k;

    long long g = gcd(a, b);

    if(max(a/g , b/g) <= k) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }

  return 0;
}
