#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i=0; i<n; ++i) cin >> arr[i];
  
  sort(arr.begin(), arr.end());

  long long sum = 1;

  for(int c : arr) {
    if(c > sum) {
      break;
    }

    sum += c;
  }

  cout << sum << "\n";

  return 0;
}
