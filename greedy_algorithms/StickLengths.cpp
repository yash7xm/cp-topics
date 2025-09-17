#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    long long median = sticks[n / 2];
    long long cost = 0;

    for (long long x : sticks) {
        cost += abs(x - median);
    }

    cout << cost << "\n";
    return 0;
}
