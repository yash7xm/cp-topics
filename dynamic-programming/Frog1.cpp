#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]
    int curr = 0;

    for(int i = 1; i < n; ++i) {
        if(i == 1) {
            curr = abs(h[i] - h[i - 1]);
        } else {
            int one = prev1 + abs(h[i] - h[i - 1]);
            int two = prev2 + abs(h[i] - h[i - 2]);
            curr = min(one, two);
        }

        prev2 = prev1;
        prev1 = curr;
    }

    cout << curr << '\n';
    return 0;
}
