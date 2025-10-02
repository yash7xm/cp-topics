#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i=0; i<n; ++i) {
    cin >> arr[i];
  }
  
  vector<int> a, b;
  a.push_back(INT_MAX);
  b.push_back(INT_MAX);
  
  int res = 0;
  for(int num : arr) {
    int x = a[a.size() - 1];
    int y = b[b.size() - 1];

    if(num <= x && num <= y) {
      if(x <= y) {
        a.push_back(num);
      } else {
        b.push_back(num);
      }
    } else if(num > x && num > y) {
      if(x <= y) {
        a.push_back(num);
      } else {
        b.push_back(num);
      }
      res++;
    } else {
      if(x <= y) {
        b.push_back(num);
      } else {
        a.push_back(num);
      }
    }
  }
  
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
