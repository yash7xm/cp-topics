#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;

    // Phase 1: handle prefix [1..m]
    {
        long long sum = 0;
        priority_queue<long long> pq; // store positives
        for (int i = m - 1; i >= 1; i--) {
            sum += a[i];
            pq.push(a[i]);
            while (sum > 0) { // we want prefix[m] <= all prefixes
                long long x = pq.top(); pq.pop();
                sum -= 2 * x; // flip this element
                res++;
            }
        }
    }

    // Phase 2: handle prefix (m..n]
    {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq; // store negatives
        for (int i = m; i < n; i++) {
            sum += a[i];
            pq.push(a[i]);
            while (sum < 0) { // prefix after m can't go below prefix[m]
                long long x = pq.top(); pq.pop();
                sum -= 2 * x; // flip this negative
                res++;
            }
        }
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
