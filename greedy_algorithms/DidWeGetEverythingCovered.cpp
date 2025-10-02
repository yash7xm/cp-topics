#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;

        string res = "";
        vector<bool> found(k, false);

        int count = 0;
        for (char c : s) {
            if ((int)res.size() == n) break;

            if (!found[c - 'a']) {
                count++;
            }
            found[c - 'a'] = true;

            if (count == k) {
                // Reset tracking
                fill(found.begin(), found.end(), false);
                count = 0;
                res.push_back(c); // add one character to the subsequence
            }
        }

        if ((int)res.size() == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            // build missing subsequence
            for (int i = 0; i < k; i++) {
                if (!found[i]) {
                    while ((int)res.size() < n) {
                        res.push_back((char)('a' + i));
                    }
                }
            }
            cout << res << "\n";
        }
    }

    return 0;
}
