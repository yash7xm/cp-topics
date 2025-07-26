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


// using Maths

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char findKthDigit(ll k) {
    ll m = 1;       // Number of digits in the current group
    ll count = 9;   // Numbers in the current group
    ll start = 1;   // First number in the current group

    while (k > m * count) {
        k -= m * count;
        m++;
        count *= 10;
        start *= 10;
    }

    // Determine the specific number
    ll number = start + (k - 1) / m;
    // Determine the specific digit in the number
    ll digitPos = (k - 1) % m;
    return to_string(number)[digitPos];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--) {
    	ll k;
    	cin >> k;
    	cout << findKthDigit(k) << endl;
    }

    return 0;
}