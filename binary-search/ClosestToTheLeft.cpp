#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    while (k--) {
        int x;
        cin >> x;

        // Get upper_bound iterator
        int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

        cout << idx << '\n';
    }

    return 0;
}
