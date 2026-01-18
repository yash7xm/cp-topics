#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // We only need a prefix to guarantee collision
    int m = min(n, 2000);

    // sum -> pair of indices (i, j)
    unordered_map<int, pair<int, int>> mp;
    mp.reserve(4000000);
    mp.max_load_factor(0.7);

    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int s = a[i] + a[j];

            if (!mp.count(s)) {
                mp[s] = {i, j};
            } else {
                auto [x, y] = mp[s];

                // Check all indices are distinct
                if (x != i && x != j && y != i && y != j) {
                    cout << "YES\n";
                    cout << x << " " << y << " " << i << " " << j << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}


