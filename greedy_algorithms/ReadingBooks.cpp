#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxBook = max(maxBook, a[i]);
    }

    cout << max(sum, 2 * maxBook) << "\n";
    return 0;
}
