#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  int cnt = 0;
  for(int i=1; i<=n; ++i) {
    cin >> arr[i];
    if(arr[i] == 0) cnt++;
  }

  if(cnt == n) {
    cout << "NO" << "\n";
    return 0;
  }

  vector<long long> prefix(n+1, 0);
  for(int i=1; i<=n; ++i) {
    prefix[i] = prefix[i-1] + arr[i];
  }

  if(prefix[n] == 0) {
    for(int i=1; i<=n; ++i) {
      if(prefix[i] != 0) {
        cout << "YES\n2\n";
        cout << "1 " << i << "\n";
        cout << i+1 << " " << n << "\n";
        break;
      }
    }
  } else {
    cout << "YES\n1\n";
    cout << "1 " << n << "\n";
  }
  
  return 0;
}
