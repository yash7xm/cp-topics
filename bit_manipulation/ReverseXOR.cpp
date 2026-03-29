#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << "YES\n";
    return;
  }

  string s = "";
  int temp = n;
  while (temp > 0) {
    s += to_string(temp % 2);
    temp /= 2;
  }
  reverse(s.begin(), s.end());

  int B = s.length();

  int trailing_zeros = 0;
  for (int i = B - 1; i >= 0; i--) {
    if (s[i] == '0') {
      trailing_zeros++;
    } else {
      break;
    }
  }

  for (int zeros = 0; zeros <= trailing_zeros; ++zeros) {
    string padded = string(zeros, '0') + s;
    int L = padded.length();

    bool is_palindrome = true;
    for (int i = 0; i < L / 2; ++i) {
      if (padded[i] != padded[L - 1 - i]) {
        is_palindrome = false;
        break;
      }
    }

    if (is_palindrome) {
      if (L % 2 == 1 && padded[L / 2] != '0') {
        continue;
      }
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}