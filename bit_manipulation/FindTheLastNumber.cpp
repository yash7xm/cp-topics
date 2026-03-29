#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> active_indices;
  for (int i = 1; i < n; ++i) {
    active_indices.push_back(i);
  }

  vector<int> active_values;
  for (int i = 1; i <= n; ++i) {
    active_values.push_back(i);
  }

  for (int b = 0; b < 15; ++b) {
    if (active_values.size() <= 1) {
      break;
    }

    int C_1 = 0;
    for (int v : active_values) {
      if ((v >> b) & 1) {
        C_1++;
      }
    }

    if (C_1 == 0 || C_1 == active_values.size()) {
      continue;
    }

    int c_1 = 0;
    vector<int> next_indices_0, next_indices_1;

    for (int i : active_indices) {
      cout << "? " << i << " " << (1 << b) << "\n";
      cout.flush();

      int resp;
      cin >> resp;
      if (resp == -1) {
        exit(0);
      }

      if (resp == 1) {
        c_1++;
        next_indices_1.push_back(i);
      } else {
        next_indices_0.push_back(i);
      }
    }

    vector<int> next_values;

    if (c_1 < C_1) {
      active_indices = next_indices_1;
      for (int v : active_values) {
        if ((v >> b) & 1) {
          next_values.push_back(v);
        }
      }
    } else {
      active_indices = next_indices_0;
      for (int v : active_values) {
        if (((v >> b) & 1) == 0) {
          next_values.push_back(v);
        }
      }
    }

    active_values = next_values;
  }

  cout << "! " << active_values[0] << "\n";
  cout.flush();
}

int main() {
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}