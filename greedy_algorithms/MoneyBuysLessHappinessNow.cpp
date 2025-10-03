#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    
  int t;
  cin >> t;

  while(t--) {
    int m, x;
    cin >> m >> x;

    vector<int> arr(m);
    for(int i=0; i<m; ++i) cin >> arr[i];

    priority_queue<int> pq;
    
    long long sum = 0;
    for(int c : arr) {
      if(sum >= c) {
        pq.push(c);
        sum -= c;
      } else if (pq.size() > 0 && pq.top() > c) {
        int max = pq.top(); pq.pop();
        sum += max - c;
        pq.push(c);
      }

      sum += x;
    }

    cout << pq.size() << "\n";
  }

  return 0;
}
