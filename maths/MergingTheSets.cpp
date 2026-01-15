#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> sets(n);
        vector<int> cnt(m + 1, 0);

        int covered = 0;

        // Read input and build full coverage
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            sets[i].resize(l);
            for (int j = 0; j < l; j++) {
                int x;
                cin >> x;
                sets[i][j] = x;
                if (cnt[x] == 0) covered++;
                cnt[x]++;
            }
        }

        // Check if even one solution exists
        if (covered < m) {
            cout << "NO\n";
            continue;
        }

        int ways = 1; // choosing all sets

        // Try removing each set
        for (int i = 0; i < n; i++) {
            for (int x : sets[i]) {
                cnt[x]--;
                if (cnt[x] == 0) covered--;
            }

            if (covered == m) ways++;

            // Restore
            for (int x : sets[i]) {
                if (cnt[x] == 0) covered++;
                cnt[x]++;
            }
        }

        cout << (ways >= 3 ? "YES\n" : "NO\n");
    }

    return 0;
}

