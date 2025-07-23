#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll digitCount(ll num) {
    ll digits = 0;
    ll length = 1;
    ll count = 9;
    ll start = 1;
    while (start * 10 <= num) {
        digits += count * length;
        start *= 10;
        count *= 10;
        length++;
    }
    digits += (num - start + 1) * length;
    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        // Binary search to find the number where k-th digit lies
        ll lo = 1, hi = 1e18, num = 1;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (digitCount(mid) >= k) {
                num = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Total digits before 'num'
        ll digitsBefore = digitCount(num - 1);
        ll index = k - digitsBefore - 1; // 0-based index in num

        string s = to_string(num);
        cout << s[index] << '\n';
    }

    return 0;
}