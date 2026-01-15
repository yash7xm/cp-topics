#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        long long ways = 1;
        int blocks = 0;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int len = j - i;
            ways = (ways * len) % MOD;
            blocks++;
            i = j;
        }

        int min_ops = n - blocks;

        for (int i = 1; i <= min_ops; i++) {
            ways = (ways * i) % MOD;
        }

        cout << min_ops << " " << ways << "\n";
    }

    return 0;
}

