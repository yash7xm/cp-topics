#include <iostream>
#include <queue>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int min_pieces = __builtin_popcount(n);

  if (k < min_pieces || k > n) {
    cout << "NO\n";
    return;
  }

  priority_queue<int> pq;

  for (int i = 0; i < 30; ++i) {
    if ((n >> i) & 1) {
      pq.push(1 << i);
    }
  }

  while (pq.size() < k) {
    int largest_piece = pq.top();
    pq.pop();

    pq.push(largest_piece / 2);
    pq.push(largest_piece / 2);
  }

  cout << "YES\n";
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}