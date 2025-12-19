#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a <= n) freq[a]++;
        }

        vector<int> catchCount(n + 1, 0);
        int ans = 0;

        for (int d = 1; d <= n; d++) {
            if (freq[d] == 0) continue;
            for (int m = d; m <= n; m += d) {
                catchCount[m] += freq[d];
                ans = max(ans, catchCount[m]);
            }
        }

        cout << ans << '\n';
    }
}

