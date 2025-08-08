#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const int MAX = *max_element(a.begin(), a.end());
    vector<int> freq(MAX + 1, 0);
    for (int num : a) {
        freq[num]++;
    }

    for (int d = MAX; d >= 1; --d) {
        int count = 0;
        for (int multiple = d; multiple <= MAX; multiple += d) {
            count += freq[multiple];
            if (count >= 2) {
                cout << d << '\n';
                return 0;
            }
        }
    }

    cout << 1 << '\n';
    return 0;
}