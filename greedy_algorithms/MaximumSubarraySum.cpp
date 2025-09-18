#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long current = arr[0];
    long long best = arr[0];

    for (int i = 1; i < n; i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }

    cout << best << "\n";
    return 0;
}
