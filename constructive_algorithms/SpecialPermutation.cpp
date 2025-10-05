#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    for(int i=2; i<=n; ++i) {
      cout << i << " ";
    }
    cout << "1 \n";
  }

  return 0;
}
