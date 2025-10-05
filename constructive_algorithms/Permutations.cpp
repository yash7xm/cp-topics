#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 1) {
      cout << "1\n";
      return 0;
    }

    if(n == 2 || n == 3) {
      cout << "NO SOLUTION\n";
      return 0;
    }

    for(int i=2; i<=n; i+=2) {
      cout << i << " ";
    }

    for(int i=1; i<=n; i+=2) {
      cout << i << " ";
    }

    return 0;
}
